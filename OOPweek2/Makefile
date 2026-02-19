all: phonebook

phonebook: PhoneBook.o main.o
	clang++ -std=c++17 PhoneBook.o main.o -o phonebook

PhoneBook.o: PhoneBook.cpp PhoneBook.h
	clang++ -std=c++17 -c PhoneBook.cpp

main.o: main.cpp PhoneBook.h
	clang++ -std=c++17 -c main.cpp

run: phonebook
	./phonebook

clean:
	rm -f *.o phonebook

rebuild: clean all