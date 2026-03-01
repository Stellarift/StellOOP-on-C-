all: cats

cats: Cat.o HouseCat.o WildCat.o PersianCat.o main.o
	clang++ -std=c++17 Cat.o HouseCat.o WildCat.o PersianCat.o main.o -o cats

Cat.o: Cat.cpp Cat.h
	clang++ -std=c++17 -c Cat.cpp

HouseCat.o: HouseCat.cpp HouseCat.h Cat.h
	clang++ -std=c++17 -c HouseCat.cpp

WildCat.o: WildCat.cpp WildCat.h Cat.h
	clang++ -std=c++17 -c WildCat.cpp

PersianCat.o: PersianCat.cpp PersianCat.h Cat.h
	clang++ -std=c++17 -c PersianCat.cpp

main.o: main.cpp Cat.h HouseCat.h WildCat.h PersianCat.h
	clang++ -std=c++17 -c main.cpp

run: cats
	./cats

clean:
	rm -f *.o cats