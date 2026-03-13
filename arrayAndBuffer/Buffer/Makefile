all: buffer

buffer: Buffer.o main.o
	clang++ -std=c++17 Buffer.o main.o -o buffer

Buffer.o: Buffer.cpp Buffer.h
	clang++ -std=c++17 -c Buffer.cpp

main.o: main.cpp Buffer.h
	clang++ -std=c++17 -c main.cpp

run: buffer
	./buffer

clean:
	rm -f *.o buffer

rebuild: clean all