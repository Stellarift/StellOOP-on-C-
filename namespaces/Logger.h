#pragma once

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

namespace Logger {
    enum LogLevel { INFO, WARNING, ERROR };
    
    void log(LogLevel level, const string& message) {
        switch (level) {
            case INFO:
                cout << "[INFO] " << message << endl;
                break;
            case WARNING:
                cout << "[WARNING] " << message << endl;
                break;
            case ERROR:
                cout << "[ERROR] " << message << endl;
                break;
        }
    }
    
    namespace FileLogger {
        void logToFile(const string& filename, const string& message) {
            ofstream file(filename, ios::app);
            if (file.is_open()) {
                file << message << endl;
                file.close();
                cout << "Сообщение записано в файл: " << filename << endl;
            } else {
                cout << "Ошибка открытия файла!" << endl;
            }
        }
    }
}