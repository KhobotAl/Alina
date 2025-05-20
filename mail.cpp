#include <iostream>
#include <Windows.h>
#include "task1.h"
#include "task2.h"
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "");

    int choice;
    do {
       cout << "\n=== ГОЛОВНЕ МЕНЮ ===\n";
       cout << "1. Завдання 1\n";
       cout << "2. Завдання 2\n";
       cout << "0. Вихід\n";
       cout << "Ваш вибір: ";
       cin >> choice;

        switch (choice) {
        case 1:
            runTask1();
            break;
        case 2:
            runTask2();
            break;
        case 0:
            cout << "Завершення програми.\n";
            break;
        default:
           cout << "Невірний вибір.\n";
        }
    } while (choice != 0);

    return 0;
}
