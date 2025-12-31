#all:
#	g++ -Isrc/include -Lsrc/lib -o main main.cpp -lsfml-graphics -lsfml-window -lsfml-system

CXX = g++

INCLUDES = -Isrc/include
LIB_PATHS = -Lsrc/lib

CXXFLAGS = -Wall -g $(INCLUDES)

LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio $(LIB_PATHS)

TARGET = ./bin/main.exe

OBJS = main.o bat.o ball.o RandomGenerator.o
SRC_MAIN = ./src/main.cpp
SRC_BAT = ./src/bat.cpp
SRC_BALL = ./src/ball.cpp
SRC_RNG = ./src/RandomGenerator.cpp

all: clean build clean_objects

fix_float:
	bspc rule -a SFML state=floating center=true

clean:
	del /s *.o

clean_objects:
	del /s *.o

build: $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(LDFLAGS)

main.o: $(SRC_MAIN)
	$(CXX) $(CXXFLAGS) -c $< -o $@

bat.o: $(SRC_BAT)
	$(CXX) $(CXXFLAGS) -c $< -o $@

ball.o: $(SRC_BALL)
	$(CXX) $(CXXFLAGS) -c $< -o $@

RandomGenerator.o: $(SRC_RNG)
	$(CXX) $(CXXFLAGS) -c $< -o $@