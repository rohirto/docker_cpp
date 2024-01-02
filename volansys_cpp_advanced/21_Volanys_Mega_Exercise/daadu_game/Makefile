SRC_DIR = src
INC_DIR = inc
BUILD_DIR = build

CXX = g++
CXXFLAGS = -Wall -I$(INC_DIR) -g -lncurses

# Get a list of all .cpp files in the src directory
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)

# Derive the object file names from the source file names
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC_FILES))

# Derive the dependency file names from the source file names
DEP_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.d,$(SRC_FILES))

# The final executable name
TARGET = $(BUILD_DIR)/a.out

all: $(TARGET)

# Rule to build the executable
$(TARGET): $(OBJ_FILES)
	$(CXX) $^ -o $@ $(CXXFLAGS)

# Rule to build object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

# Include generated dependencies
-include $(DEP_FILES)

# Rule to generate dependency files
$(BUILD_DIR)/%.d: $(SRC_DIR)/%.cpp
	@set -e; rm -f $@; \
	$(CXX) -MM -I$(INC_DIR) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,$(BUILD_DIR)/\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

# Clean rule
clean:
	rm -rf $(BUILD_DIR)

# Ensure that build directory exists before building
$(shell mkdir -p $(BUILD_DIR))