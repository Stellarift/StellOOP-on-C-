all: week7

week7: Circle.o Airplane.o main.o
	clang++ -std=c++17 Circle.o Airplane.o main.o -o week7

Circle.o: Circle.cpp Circle.h
	clang++ -std=c++17 -c Circle.cpp

Airplane.o: Airplane.cpp Airplane.h
	clang++ -std=c++17 -c Airplane.cpp

main.o: main.cpp Circle.h Airplane.h
	clang++ -std=c++17 -c main.cpp

run: week7
	./week7

clean:
	rm -f *.o week7

rebuild: clean all