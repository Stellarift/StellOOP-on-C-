all: program

program: main.cpp
	clang++ -std=c++17 -pthread main.cpp -o program

run: program
	./program

clean:
	rm -f program

rebuild: clean all