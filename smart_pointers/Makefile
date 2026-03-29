all: program

program: Timer.o main.o
	clang++ -std=c++17 Timer.o main.o -o program

Timer.o: Timer.cpp Timer.h
	clang++ -std=c++17 -c Timer.cpp

main.o: main.cpp Timer.h
	clang++ -std=c++17 -c main.cpp

run: program
	./program

clean:
	rm -f *.o program

rebuild: clean all