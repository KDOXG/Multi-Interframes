CC = g++
MPICC = mpiCC
MPIR = mpirun
STD = -std=c++17
FLAGS = -fopenmp -lpthread
SRCS = $(wildcard src/*.cpp)

# mingw32-make

main: $(SRCS) | release
	@echo Making...
	@$(CC) $(STD) $(FLAGS) main.cpp $(SRCS) -o release/main
	@echo Make done!

mpi: $(SRCS) | release
	@echo Making...
	@$(MPICC) $(STD) $(FLAGS) main.cpp $(SRCS) -o release/main_mpi
	@echo Make done!

release:
	@mkdir release

run:
	@./release/main

mpirun:
	@$(MPIR) -n 4 --use-hwthread-cpus ./release/main_mpi