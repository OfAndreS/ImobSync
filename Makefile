CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Wpedantic -g -Iinclude -MMD -MP
TARGET = imobsync
SRC_DIR = src
OBJ_DIR = obj
SOURCES = $(shell find $(SRC_DIR) -name '*.cpp')
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))
DEPS = $(patsubst %.o,%.d,$(OBJECTS))

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@echo "LN -> $@"
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@echo "CC -> $<"
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	@echo "Limpando o projeto..."
	rm -rf $(TARGET) $(OBJ_DIR)

.PHONY: all clean

-include $(DEPS)