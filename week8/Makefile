all: week8

week8: Student.o Person.o Apartment.o House.o main.o
	clang++ -std=c++17 Student.o Person.o Apartment.o House.o main.o -o week8

Student.o: Student.cpp Student.h
	clang++ -std=c++17 -c Student.cpp

Person.o: Person.cpp Person.h
	clang++ -std=c++17 -c Person.cpp

Apartment.o: Apartment.cpp Apartment.h Person.h
	clang++ -std=c++17 -c Apartment.cpp

House.o: House.cpp House.h Apartment.h
	clang++ -std=c++17 -c House.cpp

main.o: main.cpp Student.h House.h
	clang++ -std=c++17 -c main.cpp

run: week8
	./week8

clean:
	rm -f *.o week8

rebuild: clean all