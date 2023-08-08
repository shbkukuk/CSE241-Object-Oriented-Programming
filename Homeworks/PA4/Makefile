
SRC_DIR := .
OBJ_DIR := obj
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

CXX := g++
CPPFLAGS := -I.
CXXFLAGS := -std=c++11 -MMD -Wall
LDFLAGS :=

TARGET := main.out

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

-include $(OBJ_FILES:.o=.d)

$(TARGET): $(OBJ_FILES)
	$(CXX) $(LDFLAGS) -o $@ $^

.PHONY: clean

clean:
	rm -rf $(OBJ_DIR) $(TARGET)