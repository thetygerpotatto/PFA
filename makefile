# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall

# wx-config flags
WX_CXXFLAGS := $(shell wx-config --cxxflags)
WX_LIBS := $(shell wx-config --libs)

# Source and output
SRC = src/App.cpp src/MainFrame.cpp
OUT = bin/PFA

# Default target
all: $(OUT)

# Linking and compiling

$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) $(WX_CXXFLAGS) -o $(OUT) $(SRC) $(WX_LIBS)

# Clean target
clean:
	rm -f $(OUT)
