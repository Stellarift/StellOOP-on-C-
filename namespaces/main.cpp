#include <iostream>
#include "Geometry.h"
#include "Logger.h"
#include "Utils.h"
using namespace std;

void testGeometry() {
    cout << "\nЗадание 1, геометрические фигуры" << endl;
    
    double circle = Geometry::circleArea(5);
    cout << "Полная квалификация: Площадь круга радиусом 5 = " << circle << endl;
    
    using Geometry::rectangleArea;
    double rect = rectangleArea(4, 6);
    cout << "Using-объявление: Площадь прямоугольника 4x6 = " << rect << endl;
    
    Geometry::Shapes::Circle c(3);
    c.print();
}

void testLogger() {
    cout << "\nЛогирование, задание 2" << endl;
    
    Logger::log(Logger::INFO, "Программа запущена");
    Logger::log(Logger::WARNING, "Низкий заряд батареи");
    Logger::log(Logger::ERROR, "Критическая ошибка!");
    
    {
        using namespace Logger;
        log(INFO, "Сообщение внутри блока");
        log(WARNING, "Предупреждение внутри блока");
        
        FileLogger::logToFile("log.txt", "Запись в файл");
    }
    
    cout << "Вне блока using не работает" << endl;
}

void testUtils() {
    cout << "\nЗадание 3, анонимные пространства" << endl;
    
    cout << "Utils::clamp(1.5, 0, 10) = " << Utils::clamp(1.5, 0, 10) << endl;
    cout << "Utils::clamp(-0.5, 0, 10) = " << Utils::clamp(-0.5, 0, 10) << endl;
    cout << "Utils::clamp(0.3, 0, 10) = " << Utils::clamp(0.3, 0, 10) << endl;
    
    cout << "\nКоличество вызовов normalize: " << Utils::getCounter() << endl;
    
    cout << "\nnormalize и counter недоступны из main.cpp (анонимное пространство имён)" << endl;
}

int main() {
    setlocale(LC_ALL, "");
    
    testGeometry();
    testLogger();
    testUtils();
    
    return 0;
}