#define CATCH_CONFIG_MAIN  
#include "catch.hpp"
#include "Directory.h"  

TEST_CASE("Files Creation Tests") {
    Directory d("root", nullptr);

    d.addTxt("abc", "txt");
    REQUIRE(d.fileContain("abc") == true);

    d.addImage("abc2", "png", 1080, 1080);
    REQUIRE(d.fileContain("abc2") == true);

    d.addAudio("abc3", "mp3", 100, 10);
    REQUIRE(d.fileContain("abc3") == true);

    d.addCpp("abc4", "txt");
    REQUIRE(d.fileContain("abc4") == true);

    d.addExecutable("abc5", "exe", "Windows", true);
    REQUIRE(d.fileContain("abc5") == true);
}

TEST_CASE("Files Deletion Tests") {
    Directory d("root", nullptr);
    d.addTxt("abc", "txt");
    d.addImage("abc2", "png", 1080, 1080);
    d.addAudio("abc3", "mp3", 100, 10);
    d.addCpp("abc4", "txt");
    d.addExecutable("abc5", "exe", "Windows", true);

    d.removeFile("abc");
    REQUIRE(d.fileContain("abc") == false);

    d.removeFile("abc2");
    REQUIRE(d.fileContain("abc2") == false);

    d.removeFile("abc3");
    REQUIRE(d.fileContain("abc3") == false);

    d.removeFile("abc4");
    REQUIRE(d.fileContain("abc4") == false);

    d.removeFile("abc5");
    REQUIRE(d.fileContain("abc5") == false);
}

TEST_CASE("Directories Creation Tests") {
    Directory d("root", nullptr);
    d.addDirectory("abc");
    REQUIRE(d.directoryContain("abc") == true);

    d.addDirectory("abc2");
    REQUIRE(d.directoryContain("abc2") == true);

    d.addDirectory("abc3");
    REQUIRE(d.directoryContain("abc3") == true);

    d.addDirectory("abc4");
    REQUIRE(d.directoryContain("abc4") == true);

    d.addDirectory("abc5");
    REQUIRE(d.directoryContain("abc5") == true);
}

TEST_CASE("Directories Deletion Tests") {
    Directory d("root", nullptr);
    d.addDirectory("abc");
    d.addDirectory("abc2");
    d.addDirectory("abc3");
    d.addDirectory("abc4");
    d.addDirectory("abc5");

    d.removeDirectory("abc");
    REQUIRE(d.directoryContain("abc") == false);

    d.removeDirectory("abc2");
    REQUIRE(d.directoryContain("abc2") == false);

    d.removeDirectory("abc3");
    REQUIRE(d.directoryContain("abc3") == false);

    d.removeDirectory("abc4");
    REQUIRE(d.directoryContain("abc4") == false);

    d.removeDirectory("abc5");
    REQUIRE(d.directoryContain("abc5") == false);
}

TEST_CASE("Directories within Directories Tests") {
    Directory *d = new Directory("root", nullptr);

    d->addDirectory("1");
    REQUIRE(d->getParent() == nullptr);

    std::stringstream input("0\n");
    std::streambuf* orig_cin = std::cin.rdbuf(input.rdbuf());

    Directory *next = d->getDirectory();
    REQUIRE(next->getParent() != nullptr);

    std::stringstream input2("1\n");
    std::streambuf* orig_cin2 = std::cin.rdbuf(input2.rdbuf());
    REQUIRE(d->getDirectory() == nullptr);

    next->addDirectory("2");
    std::stringstream input3("0\n");
    std::streambuf* orig_cin3 = std::cin.rdbuf(input3.rdbuf());
    Directory *next2 = next->getDirectory();

    REQUIRE(next2 != nullptr);
    REQUIRE(next2->getParent() == next);

    d->clear();
    REQUIRE(d->directoryContain("1") == false);
    delete d;
}

TEST_CASE("Files/Directories Modification Tests") {
    Directory d("root", nullptr);

    d.setName("dir");
    REQUIRE(d.getName() == "dir");

    std::stringstream input("0\n2\nMacintosh\n0\nHelloWorld$\n2\n2\nHelloWorld2$\n2\n");
    std::streambuf* orig_cin = std::cin.rdbuf(input.rdbuf());

    d.addExecutable("abc", "exe", "Windows", true);
    d.op();
    Executable *f = (Executable*)d.getFile();
    REQUIRE(f->getPlatform() == "Macintosh");

    Txt t("text", "txt");
    t.readData();
    REQUIRE(t.getData() == "\nHelloWorld");

    t.op();

    REQUIRE(t.getData() == "\nHelloWorld2");
}
