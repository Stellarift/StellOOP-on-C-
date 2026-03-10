all: week9

week9: Array.o String.o Var.o main.o
	clang++ -std=c++17 Array.o String.o Var.o main.o -o week9

Array.o: Array.cpp Array.h
	clang++ -std=c++17 -c Array.cpp

String.o: String.cpp String.h
	clang++ -std=c++17 -c String.cpp

Var.o: Var.cpp Var.h String.h
	clang++ -std=c++17 -c Var.cpp

main.o: main.cpp Array.h Var.h
	clang++ -std=c++17 -c main.cpp

run: week9
	./week9

clean:
	rm -f *.o week9

rebuild: clean all