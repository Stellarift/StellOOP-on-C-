#include <iostream>
#include "Room.h"
#include "WallpaperRoll.h"
#include "Apartment.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "");
    
    cout << " Расчет стоимости обоев " << endl;
    
    Apartment apt;
    
    Room room1("Гостиная", 4.5, 2.7, 5.0, false);
    Room room2("Спальня", 3.5, 2.7, 4.0, false);
    Room room3("Кухня", 3.0, 2.7, 3.0, true);
    
    apt.addRoom(&room1);
    apt.addRoom(&room2);
    apt.addRoom(&room3);
    
    WallpaperRoll roll("Флизелиновые", 1.06, 10.0, 1200);
    
    apt.calculate(&roll);
    
    return 0;
}