all: program

program: main.o Circle.o Rectangle.o Triangle.o
	clang++ -std=c++17 main.o Circle.o Rectangle.o Triangle.o -o program

main.o: main.cpp Animal.h Dog.h Cat.h Cow.h Horse.h Circle.h Rectangle.h Triangle.h
	clang++ -std=c++17 -c main.cpp

Circle.o: Circle.cpp Circle.h Shape.h
	clang++ -std=c++17 -c Circle.cpp

Rectangle.o: Rectangle.cpp Rectangle.h Shape.h
	clang++ -std=c++17 -c Rectangle.cpp

Triangle.o: Triangle.cpp Triangle.h Shape.h
	clang++ -std=c++17 -c Triangle.cpp

run: program
	./program

clean:
	rm -f *.o program

rebuild: clean all