#include <iostream>
#include <cmath>
using namespace std;

// Оголошення функцій
void task_geom28(); // Завдання 2: Перевірка, чи точка потрапляє в червону фігуру
bool isValidDouble(double x); // Для перевірки коректності введення числа

void task_9(); // Завдання 9: Обчислення виразу для заданих x і n

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

// Завдання 9: Обчислення виразу для заданих x і n
void task_9() {
    double x, sum = 0; // Ініціалізація змінних
    int n;

    // Введення натурального числа n
    cout << "Enter a natural number n: ";
    while (true) {
        cin >> n;
        if (cin.fail() || n <= 0) {  // n має дійсним типом
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
        if (cin.fail() || x < 0 || x > 5) {  // x має бути в межах [1, 5] 
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

        // Виведення кожного четвертого елемента
        if (k % 4 == 0) {
            cout << "Element at k = " << k << ": " << term << endl;
        }
    }

    // Виведення загальної суми
    cout << "Total sum: " << sum << endl;
}

// Завдання 30: Дослідження ряду на збіжність

// Функція для обчислення факторіалу
double factorial(int n) {
    if (n <= 1) return 1; // Якщо n <= 1, факторіал дорівнює 1
    double res = 1;
    for (int i = 1; i <= n; i++) {
        res *= i; // Множимо всі числа від 1 до n
    }
    return res;
}

// Функція для обчислення ряду та перевірки на збіжність
void task_30() {
    double x, sum = 0, u, e = 1E-05; // e - тоічність для збіжності
    int n = 1;

    // Введення значення x
    cout << "Enter the value of x (real number): ";
    while (true) {
        cin >> x;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Invalid input! Please enter a real number: ";
        }
        else {
            break; // вихід з циклу, якщо ввід коректний
        }
    }

    // Обчислення першого елемента ряду
    u = (pow(x, n) * factorial(n)) / pow(n, n / 2.0);
    sum += u;

    // Виведення першого елемента
    cout << "First element: " << u << endl;

    // Обчислення суми ряду
    while (fabs(u) > e && fabs(u) < 100) {
        n++;  // Збільшуємо n для обчислення наступного елемента
        u = (pow(x, n) * factorial(n)) / pow(n, n / 2.0); // Обчислення кожного елемента ряду
        sum += u;

        // Виведення поточного елемента
        cout << "Element at n = " << n << ": " << u << endl;

        // Умова зупинки по розбіжності
        if (fabs(u) > 100) {
            cout << "Series is divergent at n = " << n << ". Stopping calculation.\n";
            break;
        }

        // Умова зупинки по збіжності
        if (fabs(u) < e) {
            cout << "Series has converged at n = " << n << ". Stopping calculation.\n";
            break;
        }
    }

    // Виведення загальної суми
    cout << "Total sum: " << sum << endl;
}
