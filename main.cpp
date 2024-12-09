#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.14159265

// Оголошення функцій
void task_geom28(); // Завдання 2: Перевірка, чи точка потрапляє в червону фігуру
bool isValidDouble(double x); // Для перевірки коректності введення числа

void task_9(); // Завдання 9: Обчислення виразу для заданих x і n
bool validateX(double x); // Перевірка коректності x (1 <= x <= 5)
bool validateN(int n); // Перевірка коректності n (натуральне число)

void task_30(); // Завдання 30: Дослідження ряду на збіжність
double factorial(int n); // Функція для обчислення факторіалу

// Основна функція меню
int main() {
    int menu;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Check if the point is inside the red shape\n";
        cout << "2. Calculate expression\n";
        cout << "3. Calculate series convergence\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        // Введення вибору користувача з перевіркою
        while (true) {
            cin >> menu;
            if (cin.fail() || menu < 1 || menu > 4) {
                cin.clear();
                cin.ignore(32767, '\n');
                cout << "Invalid input! Please enter a number between 1 and 4: ";
            }
            else {
                break;
            }
        }

        // Вибір дії
        switch (menu) {
        case 1:
            task_geom28();
            break;
        case 2:
            task_9();
            break;
        case 3:
            task_30();
            break;
        case 4:
            cout << "Exiting the program.\n";
            return 0;
        }
    }
}

// Завдання 28: Перевірка, чи точка потрапляє в червону фігуру
void task_geom28() {
    double x, y, r;

    // Введення координат точки
    cout << "Enter the coordinates of the point (x, y): ";
    while (true) {
        cin >> x >> y;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Invalid input! Please enter valid coordinates for the point: ";
        }
        else {
            break;
        }
    }

    // Введення радіусу кола
    cout << "Enter the radius of the circle r: ";
    while (true) {
        cin >> r;
        if (cin.fail() || r <= 0) {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Invalid input! Please enter a positive radius: ";
        }
        else {
            break;
        }
    }

    // Перевірка, чи точка потрапляє в одну з двох областей
    double dx = x + r, dist = dx * dx + y * y;
    bool inFirstRegion = (x >= -r && x <= 0 && y >= -r && y <= 0 && abs(y) <= abs(x) && dist <= r * r);
    bool inSecondRegion = (x >= -2 * r && x <= -r && y >= -r && y <= 0 && dist >= r * r);

    // Виведення результату
    if (inFirstRegion || inSecondRegion) {
        cout << "The point falls into the red shape." << endl;
    }
    else {
        cout << "The point does not fall into the red shape." << endl;
    }
}

// Функція для перевірки дійсного числа
bool isValidDouble(double x) {
    return !cin.fail(); // Перевірка на коректність введеного числа
}

// Завдання 9: Обчислення виразу для заданих x і n
void task_9() {
    double x, sum = 0; // Ініціалізація змінних
    int n;

    // Введення натурального числа n
    cout << "Enter a natural number n: ";
    while (true) {
        cin >> n;
        if (cin.fail() || !validateN(n)) {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Invalid value for n. It must be a natural number. Try again: ";
        }
        else {
            break; // Якщо n коректне, виходимо з циклу
        }
    }

    // Введення реального числа x
    cout << "Enter a real number x (1 <= x <= 5): ";
    while (true) {
        cin >> x;
        if (cin.fail() || !validateX(x)) {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Invalid value for x. It must satisfy 1 <= x <= 5. Try again: ";
        }
        else {
            break; // Якщо x коректне, виходимо з циклу
        }
    }

    // Обчислення суми
    cout << "Calculating the sum and partial elements:" << endl;
    for (int k = 1; k <= n; k++) {
        double term = (pow(x, 1.0 / k) * k * pow(-1, k)) / pow(x, k - 1);
        sum += term;

        // Виведення кожного третього чи четвертого елемента в залежності від парності n
        if ((n % 2 == 0 && k % 3 == 0) || (n % 2 != 0 && k % 4 == 0)) {
            cout << "Element at k = " << k << ": " << term << endl;
        }
    }

    // Виведення загальної суми
    cout << "Total sum: " << sum << endl;
}

// Завдання 30: Дослідження ряду на збіжність
void task_30() {
    double x, u, sum = 0, e = 1E-20; // Точність для завершення
    int n = 1;

    cout << "Task: Calculate the sum of the series\n";
    cout << "Enter the value of x (real number): ";
    while (true) {
        cin >> x;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Invalid value! Try again: ";
        }
        else {
            break;
        }
    }

    // Обчислення першого елемента ряду
    u = (pow(x, n) * factorial(n)) / pow(n, n / 2.0);
    sum = u;

    cout << "First element of the series: u = " << u << endl;

    // Обчислення ряду до досягнення заданої точності або максимального ліміту ітерацій
    while (fabs(u) > e) {
        n++;
        u = (pow(x, n) * factorial(n)) / pow(n, n / 2.0); // Обчислення кожного елемента ряду
        sum += u;

        cout << "Current element: u = " << u << endl;

        // Ліміт на кількість ітерацій
        if (n > 200) {
            cout << "Iteration limit (200) reached. Calculation stopped.\n";
            break;
        }
    }

    // Виведення результату
    cout << "Total sum: " << sum << endl;
}

// Функція для обчислення факторіалу
double factorial(int n) {
    double res = 1;
    for (int i = 1; i <= n; i++) {
        res *= i;
    }
    return res;
}

// Перевірка коректності x
bool validateX(double x) {
    return x >= 1 && x <= 5; // x має бути в межах [1, 5]
}

// Перевірка коректності n
bool validateN(int n) {
    return n > 0; // n має бути натуральним числом
}
