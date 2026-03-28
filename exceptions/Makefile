all: program

program: main.cpp
	clang++ -std=c++17 main.cpp -o program

run: program
	./program

clean:
	rm -f program

rebuild: clean all