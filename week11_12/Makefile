all: week11_12

week11_12: task11_1.o task11_2.o task11_3.o task11_4.o main.o
	clang++ -std=c++17 task11_1.o task11_2.o task11_3.o task11_4.o main.o -o week11_12

task11_1.o: task11_1.cpp
	clang++ -std=c++17 -c task11_1.cpp

task11_2.o: task11_2.cpp
	clang++ -std=c++17 -c task11_2.cpp

task11_3.o: task11_3.cpp
	clang++ -std=c++17 -c task11_3.cpp

task11_4.o: task11_4.cpp
	clang++ -std=c++17 -c task11_4.cpp

main.o: main.cpp Array.h
	clang++ -std=c++17 -c main.cpp

run: week11_12
	./week11_12

clean:
	rm -f *.o week11_12

rebuild: clean all