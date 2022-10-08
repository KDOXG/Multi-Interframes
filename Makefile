CC = g++

# mingw32-make

main: YUVHeader.o VideoHeader.o YUV.o Frame.o Interframes.o
	$(CC) main.cpp bin/Frame.o bin/VideoHeader.o bin/YUVHeader.o bin/YUV.o bin/Interframes.o -o release/main.exe

Frame.o:
	$(CC) src/Frame.cpp -c -o bin/Frame.o

YUVHeader.o:
	$(CC) src/YUVHeader.cpp -c -o bin/YUVHeader.o

VideoHeader.o:
	$(CC) src/VideoHeader.cpp -c -o bin/VideoHeader.o
	
YUV.o:
	$(CC) src/YUV.cpp -c -o bin/YUV.o

Interframes.o:
	$(CC) src/Interframes.cpp -c -o bin/Interframes.o