CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

TARGET = program
SRC = main.cpp FuncA.cpp
OBJ = $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
  $(CXX) $(CXXFLAGS) -o $@ $(OBJ)

%.o: %.cpp
  $(CXX) $(CXXFLAGS) -c $< -o $@

clean:
  rm -f $(OBJ) $(TARGET)

.PHONY: all clean
