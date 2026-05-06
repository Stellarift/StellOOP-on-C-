CXX = clang++
CXXFLAGS = -std=c++17 -Wall

# Цели по умолчанию
all: task1_before task1_after task2_before task2_after

# Программа 1 (до рефакторинга)
task1_before: task1_before.cpp
	$(CXX) $(CXXFLAGS) task1_before.cpp -o task1_before

# Программа 1 (после рефакторинга)
task1_after: task1_after.cpp
	$(CXX) $(CXXFLAGS) task1_after.cpp -o task1_after

# Программа 2 (до рефакторинга)
task2_before: task2_before.cpp
	$(CXX) $(CXXFLAGS) task2_before.cpp -o task2_before

# Программа 2 (после рефакторинга)
task2_after: task2_after.cpp
	$(CXX) $(CXXFLAGS) task2_after.cpp -o task2_after

# Запуск программ
run1_before: task1_before
	./task1_before

run1_after: task1_after
	./task1_after

run2_before: task2_before
	./task2_before

run2_after: task2_after
	./task2_after

# Очистка
clean:
	rm -f task1_before task1_after task2_before task2_after

# Пересборка
rebuild: clean all

.PHONY: all clean rebuild