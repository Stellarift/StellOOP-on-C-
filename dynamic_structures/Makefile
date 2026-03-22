all: dynamic

dynamic: main.o
	clang++ -std=c++17 main.o -o dynamic

main.o: main.cpp SinglyLinkedList.h Stack.h Queue.h
	clang++ -std=c++17 -c main.cpp

run: dynamic
	./dynamic

clean:
	rm -f *.o dynamic

rebuild: clean all