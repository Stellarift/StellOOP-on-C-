all: program

program: Point.o Fraction.o Student.o main.o
	clang++ -std=c++17 Point.o Fraction.o Student.o main.o -o program

Point.o: Point.cpp Point.h
	clang++ -std=c++17 -c Point.cpp

Fraction.o: Fraction.cpp Fraction.h
	clang++ -std=c++17 -c Fraction.cpp

Student.o: Student.cpp Student.h
	clang++ -std=c++17 -c Student.cpp

main.o: main.cpp Point.h Fraction.h Student.h
	clang++ -std=c++17 -c main.cpp

run: program
	./program

clean:
	rm -f *.o program

rebuild: clean all