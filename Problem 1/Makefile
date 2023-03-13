TARGET = app
RFLAGS =

BUILD  = build

PWD=$(shell pwd)

SRC := $(shell find src -name "*.cpp")
OBJ := $(patsubst %.cpp,$(BUILD)/%.o,$(SRC))

CC     = cc
CXX    = c++
CFLAGS = -g -std=c11 -Wall -g -fsanitize=address -I$(LIBDIR)/src
CXXFLAGS = -g -std=c++17 -Wall -g -fsanitize=address -I$(LIBDIR)/src
LIBRARIES =

all: $(BUILD)/$(TARGET)

$(BUILD)/$(TARGET) : $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) $(LDFLAGS) $(LIBRARIES) -o $(BUILD)/$(TARGET)

$(BUILD)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD)/%.o: %.cpp
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS)  -c $< -o $@

clean:
	rm -rf build

