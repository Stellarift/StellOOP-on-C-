all: intarray

intarray: IntArray.o main.o
	clang++ -std=c++17 IntArray.o main.o -o intarray

IntArray.o: IntArray.cpp IntArray.h
	clang++ -std=c++17 -c IntArray.cpp

main.o: main.cpp IntArray.h
	clang++ -std=c++17 -c main.cpp

run: intarray
	./intarray

clean:
	rm -f *.o intarray

rebuild: clean all