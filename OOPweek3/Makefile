all: program

program: Geometry.o Point.o Fraction.o Student.o main.o
	clang++ -std=c++17 Geometry.o Point.o Fraction.o Student.o main.o -o program

Geometry.o: Geometry.cpp Geometry.h
	clang++ -std=c++17 -c Geometry.cpp

Point.o: Point.cpp Point.h
	clang++ -std=c++17 -c Point.cpp

Fraction.o: Fraction.cpp Fraction.h
	clang++ -std=c++17 -c Fraction.cpp

Student.o: Student.cpp Student.h
	clang++ -std=c++17 -c Student.cpp

main.o: main.cpp Geometry.h Point.h Fraction.h Student.h
	clang++ -std=c++17 -c main.cpp

run: program
	./program

clean:
	rm -f *.o program

rebuild: clean all