all: week4

week4: String.o Array.o Book.o Worker.o main.o
	clang++ -std=c++17 String.o Array.o Book.o Worker.o main.o -o week4

String.o: String.cpp String.h
	clang++ -std=c++17 -c String.cpp

Array.o: Array.cpp Array.h
	clang++ -std=c++17 -c Array.cpp

Book.o: Book.cpp Book.h
	clang++ -std=c++17 -c Book.cpp

Worker.o: Worker.cpp Worker.h
	clang++ -std=c++17 -c Worker.cpp

main.o: main.cpp String.h Array.h Book.h Worker.h
	clang++ -std=c++17 -c main.cpp

run: week4
	./week4

clean:
	rm -f *.o week4

rebuild: clean all