all: elevator wallpaper group

elevator:
	clang++ -std=c++17 task1_elevator/Elevator.cpp task1_elevator/main_elevator.cpp -o elevator

wallpaper:
	clang++ -std=c++17 task2_wallpaper/*.cpp -o wallpaper

group:
	clang++ -std=c++17 task3_group/*.cpp -o group

run-elevator: elevator
	./elevator

run-wallpaper: wallpaper
	./wallpaper

run-group: group
	./group

clean:
	rm -f elevator wallpaper group

rebuild: clean all