# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++11 -Wall -MMD

# Directory
SRCDIR := .

# Source files (excluding main.cpp and FileSystem.cpp)
SRCS := $(wildcard $(SRCDIR)/*.cpp)
SRCS := $(filter-out $(SRCDIR)/main.cpp, $(SRCS))
SRCS := $(filter-out $(SRCDIR)/FileSystem.cpp, $(SRCS))

# Object files directory
OBJDIR := obj

# Object files and dependency files
OBJS := $(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
DEPS := $(OBJS:.o=.d)

# Test source file
TEST_SRCS := tests.cpp
TEST_OBJS := $(OBJDIR)/tests.o
TEST_DEPS := $(TEST_OBJS:.o=.d)

# Executable
TEST_EXEC := tests

# Main target
$(TEST_EXEC): $(OBJS) $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compile source files (excluding main.cpp and FileSystem.cpp)
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile tests source file
$(TEST_OBJS): $(TEST_SRCS) | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create obj directory if it doesn't exist
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Clean task
clean:
	rm -rf $(OBJDIR) $(TEST_EXEC) $(DEPS) $(TEST_DEPS)

# Include dependency files if they exist
-include $(DEPS)
-include $(TEST_DEPS)

.PHONY: clean
