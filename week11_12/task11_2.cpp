#include <iostream>
#include <cmath>
using namespace std;

// Шаблон для линейного уравнения a*x + b = 0
template <typename T>
bool solveLinear(T a, T b, double& root) {
    if (a == 0) {
        return false;  // нет решения или бесконечно много
    }
    root = -static_cast<double>(b) / a;
    return true;
}

// Шаблон для квадратного уравнения a*x^2 + b*x + c = 0
template <typename T>
int solveQuadratic(T a, T b, T c, double& root1, double& root2) {
    if (a == 0) {
        // вырождается в линейное
        return solveLinear(b, c, root1) ? 1 : 0;
    }
    
    double discriminant = static_cast<double>(b)*b - 4*static_cast<double>(a)*c;
    
    if (discriminant < 0) {
        return 0;  // нет действительных корней
    }
    else if (discriminant == 0) {
        root1 = -static_cast<double>(b) / (2 * a);
        return 1;  // один корень (два одинаковых)
    }
    else {
        root1 = (-static_cast<double>(b) + sqrt(discriminant)) / (2 * a);
        root2 = (-static_cast<double>(b) - sqrt(discriminant)) / (2 * a);
        return 2;  // два различных корня
    }
}

void demoTask2() {
    cout << "\n--- Задание 2: Корни уравнений ---" << endl;
    
    // Линейные уравнения
    double root;
    cout << "Линейное 2x + 4 = 0: ";
    if (solveLinear(2, 4, root)) {
        cout << "x = " << root << endl;
    } else {
        cout << "нет решения" << endl;
    }
    
    cout << "Линейное 0x + 5 = 0: ";
    if (solveLinear(0, 5, root)) {
        cout << "x = " << root << endl;
    } else {
        cout << "нет решения" << endl;
    }
    
    // Квадратные уравнения
    double r1, r2;
    int roots;
    
    cout << "\nКвадратное x^2 - 3x + 2 = 0: ";
    roots = solveQuadratic(1, -3, 2, r1, r2);
    if (roots == 2) cout << "x1 = " << r1 << ", x2 = " << r2 << endl;
    else if (roots == 1) cout << "x = " << r1 << endl;
    else cout << "нет действительных корней" << endl;
    
    cout << "Квадратное x^2 - 2x + 1 = 0: ";
    roots = solveQuadratic(1, -2, 1, r1, r2);
    if (roots == 2) cout << "x1 = " << r1 << ", x2 = " << r2 << endl;
    else if (roots == 1) cout << "x = " << r1 << endl;
    else cout << "нет действительных корней" << endl;
    
    cout << "Квадратное x^2 + 1 = 0: ";
    roots = solveQuadratic(1, 0, 1, r1, r2);
    if (roots == 2) cout << "x1 = " << r1 << ", x2 = " << r2 << endl;
    else if (roots == 1) cout << "x = " << r1 << endl;
    else cout << "нет действительных корней" << endl;
}