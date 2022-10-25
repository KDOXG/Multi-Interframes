CC = g++
STD = -std=c++17
FLAGS = -fopenmp -lpthread
SRCS = $(wildcard src/*.cpp)

# mingw32-make

main: $(SRCS)
	$(CC) $(STD) $(FLAGS) main.cpp $(SRCS) -o release/main.exe