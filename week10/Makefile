all: week10

week10: Complex.o Time.o main.o
	clang++ -std=c++17 Complex.o Time.o main.o -o week10

Complex.o: Complex.cpp Complex.h
	clang++ -std=c++17 -c Complex.cpp

Time.o: Time.cpp Time.h
	clang++ -std=c++17 -c Time.cpp

main.o: main.cpp Complex.h Time.h
	clang++ -std=c++17 -c main.cpp

run: week10
	./week10

clean:
	rm -f *.o week10

rebuild: clean all