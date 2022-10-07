CC = g++

# mingw32-make

main: YUVHeader.o YUV.o Frame.o Interframes.o
	$(CC) main.cpp bin/Frame.o bin/YUVHeader.o bin/YUV.o bin/Interframes.o -o release/main

Frame.o:
	$(CC) src/Frame.cpp -c -o bin/Frame.o

YUVHeader.o:
	$(CC) src/YUVHeader.cpp -c -o bin/YUVHeader.o
	
YUV.o:
	$(CC) src/YUV.cpp -c -o bin/YUV.o

Interframes.o:
	$(CC) src/Interframes.cpp -c -o bin/Interframes.o