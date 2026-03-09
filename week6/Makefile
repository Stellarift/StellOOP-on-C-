all: week6

week6: Date.o MyString.o main.o
	clang++ -std=c++17 Date.o MyString.o main.o -o week6

Date.o: Date.cpp Date.h
	clang++ -std=c++17 -c Date.cpp

MyString.o: MyString.cpp MyString.h
	clang++ -std=c++17 -c MyString.cpp

main.o: main.cpp Date.h MyString.h
	clang++ -std=c++17 -c main.cpp

run: week6
	./week6

clean:
	rm -f *.o week6

rebuild: clean all