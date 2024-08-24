# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic

# Executable name
EXEC = TestingMain

# Source files (finds all .cpp files in the directory)
SRCS = $(wildcard *.cpp)

# Object files (one for each source file)
OBJS = $(SRCS:.cpp=.o)

# Default rule to build the executable
all: $(EXEC)

# Rule to link object files and create the executable
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

# Rule to compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to run the program
run: $(EXEC)
	./$(EXEC)

# Clean up object files and the executable
clean:
	rm -f $(OBJS) $(EXEC)
