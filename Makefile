CC = g++
STD = -std=c++17
SRCS = $(wildcard src/*.cpp)

# mingw32-make

main: $(SRCS)
	$(CC) $(STD) main.cpp $(SRCS) -o release/main.exe