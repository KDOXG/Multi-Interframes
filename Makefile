CC = g++
STD = -std=c++17
FLAGS = -fopenmp -lpthread
SRCS = $(wildcard src/*.cpp)

# mingw32-make

main: $(SRCS)
	@echo Making...
	@$(CC) $(STD) $(FLAGS) main.cpp $(SRCS) -o release/main
	@echo Make done!
	@./release/main