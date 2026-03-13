all: set

set: IntSet.o main.o
	clang++ -std=c++17 IntSet.o main.o -o set

IntSet.o: IntSet.cpp IntSet.h
	clang++ -std=c++17 -c IntSet.cpp

main.o: main.cpp IntSet.h
	clang++ -std=c++17 -c main.cpp

run: set
	./set

clean:
	rm -f *.o set

rebuild: clean all