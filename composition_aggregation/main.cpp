#include <iostream>
#include <vector>
#include <string>
using namespace std;

// копмпозиция

class Room {
private:
    string name;
public:
    Room(const string& n) : name(n) {}
    void print() const { cout << "  Комната: " << name << endl; }
};

class House {
private:
    string address;
    vector<Room> rooms;  //комнаты принадлежат дому-это композиция
public:
    House(const string& addr) : address(addr) {}
    
    void addRoom(const string& name) {
        rooms.push_back(Room(name));  //комнаты создаются внутри дома
    }
    
    void print() const {
        cout << "Дом: " << address << endl;
        for (const auto& r : rooms) r.print();
    }
};

// агрегация

class Student {
private:
    string name;
public:
    Student(const string& n) : name(n) {}
    void print() const { cout << "  Студент: " << name << endl; }
};

class University {
private:
    string name;
    vector<Student*> students;  // агрегация-только ссылки
public:
    University(const string& n) : name(n) {}
    
    void addStudent(Student* s) {
        students.push_back(s);  // студенты существуют отдельно
    }
    
    void print() const {
        cout << "Университет: " << name << endl;
        for (const auto& s : students) s->print();
    }
};


int main() {
    setlocale(LC_ALL, "");
    
    cout << "Композиция" << endl;
    House house("Ленина 10");
    house.addRoom("Гостиная");
    house.addRoom("Спальня");
    house.print();
    // при уничтожении house комнаты удаляются автоматически
    
    cout << "\nАгрегация" << endl;
    
    //Студенты создаются независимо
    Student s1("Иванов");
    Student s2("Петрова");
    
    //Университет хранит ссылки на студентов
    University uni("МГУ");
    uni.addStudent(&s1);
    uni.addStudent(&s2);
    uni.print();
    
    //Студенты продолжают существовать после уничтожения университета
    cout << "\nСтуденты существуют независимо:" << endl;
    s1.print();
    s2.print();
    
    return 0;
}