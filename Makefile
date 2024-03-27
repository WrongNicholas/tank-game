# Compiler
CC = g++

# Compiler flags
CFLAGS = -std=c++20

# SFML and Box2D paths
SFML_INCLUDE = -I/opt/homebrew/Cellar/sfml/2.6.1/include
SFML_LIB = -L/opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
BOX2D_INCLUDE = -I/opt/homebrew/Cellar/box2d/2.4.1/include
BOX2D_LIB = -L/opt/homebrew/Cellar/box2d/2.4.1/lib -lBox2D
NLOHMANN_INCLUDE = -I/opt/homebrew/Cellar/nlohmann-json/3.11.3/include

# Directories
BUILD_DIR = build
SRC_DIR = source
INCLUDE_DIR = include

# Source files
SRCS = $(wildcard $(SRC_DIR)/core/*.cpp) $(wildcard $(SRC_DIR)/gameobject/*.cpp) $(SRC_DIR)/main.cpp

# Object files
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Ensure output directories exist
$(shell mkdir -p $(dir $(OBJS)))

# Executable
EXECUTABLE = $(BUILD_DIR)/tank-game

# Build rule
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CC) $(CFLAGS) $(SFML_LIB) $(BOX2D_LIB) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) $(SFML_INCLUDE) $(BOX2D_INCLUDE) $(NLOHMANN_INCLUDE) -I$(INCLUDE_DIR) -c -o $@ $<

# Run the executable
run: $(EXECUTABLE)
	@echo "Running executable..."
	./$(EXECUTABLE)

clean:
	@echo "Cleaning up..."
	@rm -rf $(BUILD_DIR)/*
	@echo "Cleanup Complete."

