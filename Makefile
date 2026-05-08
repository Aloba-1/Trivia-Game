#
# Makefile
# TriviaGame
#Created by AKE<3
# Compiler
CXX = g++

# Flags
CXXFLAGS = -Wall -Wextra -std=c++17 -Iheaders -MMD -MP

# Directories
SRC_DIR = sources
PROG_DIR = programs
BIN_DIR = bin

# Source files (shared code)
SRC = $(wildcard $(SRC_DIR)/*.cpp)

# Program files (each becomes its own executable)
PROG = $(wildcard $(PROG_DIR)/*.cpp)

# Object files for shared source
SRC_OBJ = $(patsubst $(SRC_DIR)/%.cpp,$(BIN_DIR)/source/%.o,$(SRC))

# Object files for programs
PROG_OBJ = $(patsubst $(PROG_DIR)/%.cpp,$(BIN_DIR)/programs/%.o,$(PROG))

# Executables (one per program)
EXE = $(patsubst $(PROG_DIR)/%.cpp,$(BIN_DIR)/%,$(PROG))

# Dependency files
DEP = $(SRC_OBJ:.o=.d) $(PROG_OBJ:.o=.d)

# Default target
all: $(BIN_DIR) $(EXE)

# Create bin directories
$(BIN_DIR):
	mkdir -p $(BIN_DIR)/source $(BIN_DIR)/programs

# Link each program separately
$(BIN_DIR)/%: $(BIN_DIR)/programs/%.o $(SRC_OBJ)
	$(CXX) $^ -o $@

# Compile shared source
$(BIN_DIR)/source/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile program files
$(BIN_DIR)/programs/%.o: $(PROG_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Include dependencies
-include $(DEP)

# Clean
clean:
	rm -rf $(BIN_DIR)

