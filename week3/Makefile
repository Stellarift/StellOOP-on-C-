all: string_program

string_program: String.o main.o
	clang++ -std=c++17 String.o main.o -o string_program

String.o: String.cpp String.h
	clang++ -std=c++17 -c String.cpp

main.o: main.cpp String.h
	clang++ -std=c++17 -c main.cpp

run: string_program
	./string_program

clean:
	rm -f *.o string_program

rebuild: clean all