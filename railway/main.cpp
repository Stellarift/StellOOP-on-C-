#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <fstream>
#include "Train.h"
#include "Route.h"
#include "Ticket.h"
#include "Stack.h"
using namespace std;
using namespace Railway;
using namespace Ticketing;

PassengerTrain* castToPassengerTrain(Train* train) {
    return dynamic_cast<PassengerTrain*>(train);
}

//сохранения расписания в файл
void saveSchedule(const vector<shared_ptr<Train>>& trains, const vector<Route>& routes, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Ошибка" << endl;
        return;
    }
    
    file << "Расписание" << endl;
    file << "Поезда:" << endl;
    for (const auto& train : trains) {
        train->saveToFile(file);
    }
    
    file << "Routes:" << endl;
    for (const auto& route : routes) {
        route.saveToFile(file);
    }
    
    file.close();
    cout << "Расписание сохранено в файл: " << filename << endl;
}

int main() {
    setlocale(LC_ALL, "");
    
    cout << "симуляция железной дороги" << endl;
    
    //умные указатели
    cout << "\nСоздание поезда:" << endl;
    vector<shared_ptr<Train>> trains;
    
    trains.push_back(make_shared<PassengerTrain>("P001", "Sapsan", 10, 50));
    trains.push_back(make_shared<PassengerTrain>("P002", "Lastochka", 8, 40));
    trains.push_back(make_shared<FreightTrain>("F001", "Locomotive", 15, 500.0));
    trains.push_back(make_shared<FreightTrain>("F002", "Diesel", 12, 350.0));
    
    Train::incrementTrainsSent();
    Train::incrementTrainsSent();
    Train::incrementTrainsSent();
    Train::incrementTrainsSent();
    
    cout << "Всего отправлено поездов: " << Train::getTrainsSent() << endl;
    
    //Создание маршрутов (композиция)
    cout << "\nСоздание маршрута" << endl;
    vector<Route> routes;
    routes.push_back(Route("Moscow", "Saint Petersburg", 650));
    routes.push_back(Route("Saint Petersburg", "Helsinki", 400));
    routes.push_back(Route("Moscow", "Kazan", 800));
    
    //объединение маршрутов
    cout << "\nОбъединение маршрутов" << endl;
    Route combined = routes[0] + routes[1];
    cout << "Combined route: " << combined << endl;
    
    //стек отменённых маршрутов
    cout << "\nСтек отмененных маршрутов" << endl;
    Stack<Route> canceledRoutes;
    canceledRoutes.push(routes[2]);
    canceledRoutes.push(routes[1]);
    
    cout << "Стек отменённых маршрутов:" << endl;
    for (size_t i = 0; i < canceledRoutes.size(); i++) {
        cout << "  [" << i << "] " << canceledRoutes[i] << endl;
    }
    
    canceledRoutes.pop();
    cout << "После pop(), верхний элемент: " << canceledRoutes.top() << endl;
    
    //исключения
    cout << "\nПродажа билетов" << endl;
    vector<Ticket> tickets;
    
    PassengerTrain* pTrain = dynamic_cast<PassengerTrain*>(trains[0].get());
    if (pTrain) {
        try {
            for (int i = 0; i < 55; i++) {
                pTrain->sellTicket();
                tickets.push_back(Ticket("Passenger" + to_string(i+1), pTrain->getNumber(), i+1, trains[0]));
            }
        } catch (const runtime_error& e) {
            cout << "Исключение: " << e.what() << endl;
        }
    }
    
    // сортировка
    cout << "\nСортировка маршрутов по расписанию" << endl;
    sort(routes.begin(), routes.end(),
         [](const Route& a, const Route& b) {
             return a.getDistance() < b.getDistance();
         });
    
    cout << "Маршруты (от короткого к длинному):" << endl;
    for_each(routes.begin(), routes.end(),
             [](const Route& r) {
                 cout << "  " << r << endl;
             });
    
    //преобразования типов
    cout << "\nПреобразование типов" << endl;
    for (auto& train : trains) {
        PassengerTrain* pt = castToPassengerTrain(train.get());
        if (pt) {
            cout << "Успешное преобразование: " << pt->getNumber() << " - пассажирский поезд" << endl;
        } else {
            cout << "Преобразование не удалось: " << train->getNumber() << " - не пассажирский" << endl;
        }
    }
    
    //сохранение
    cout << "\nСохранение в файл" << endl;
    saveSchedule(trains, routes, "schedule.txt");
    
    // вся информация
    cout << "\nВсе поезда" << endl;
    for (const auto& train : trains) {
        train->print();
    }
    
    cout << "\nВсе билеты" << endl;
    for (const auto& ticket : tickets) {
        ticket.print();
    }
    
    return 0;
}