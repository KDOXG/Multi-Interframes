# Multi-Interframes
A parallel and distributed inter-frame prediction solution for video coding made with OpenMP and MPI.

Repo: https://github.com/KDOXG/Multi-Interframes

How to run:
Download video from https://drive.google.com/file/d/1MfZ13T8ZSEt2DczSoQtER2bqQtg3GgPX/view?usp=share_link
Move video to project root folder
Open terminal in project root folder
To build without MPI:
* execute 'make' or 'make main'
* execute 'make run'

To build with MPI:
* execute 'make mpi'
* execute 'make mpirun'

The function that uses OpenMP and MPI parallelism is located at src/Interframes.cpp 
