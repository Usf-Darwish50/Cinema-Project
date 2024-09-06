# Makefile

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++14 -Wall -Wextra

# Directories
SRC_DIR = .
OBJ_DIR = obj
INC_DIRS = -ICustomer -ICinema -IMovie -IPayment

# Files
SOURCES = $(wildcard $(SRC_DIR)/*.cpp) \
          $(wildcard $(SRC_DIR)/Customer/*.cpp) \
          $(wildcard $(SRC_DIR)/Cinema/*.cpp) \
          $(wildcard $(SRC_DIR)/Movie/*.cpp) \
          $(wildcard $(SRC_DIR)/Payment/*.cpp)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Target executable
TARGET = my_program.out

# Default target
all: $(TARGET)

# Link the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

# Compile source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)  # Create the directory for the object file
	$(CXX) $(CXXFLAGS) $(INC_DIRS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJECTS) $(TARGET)
