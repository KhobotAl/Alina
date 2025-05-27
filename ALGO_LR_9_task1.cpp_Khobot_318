#include <iostream> // Підключення бібліотеки для введення/виведення
#include <Windows.h> // Підключення бібліотеки для роботи з кодуванням Windows
#include <string> // Підключення бібліотеки для роботи з рядками
using namespace std;

void runTask1() {
    SetConsoleCP(1251); //Підключення підтримки кирилиці для введення
    SetConsoleOutputCP(1251); // Підключення підтримки кирилиці для виведення
    setlocale(LC_ALL, ""); // Встановлення локалі для підтримки національних символів

    // Вихідний рядок (текст) та слово, яке потрібно знайти в ньому
    const char* text = "Hello, world!";
    const char* word = "world";

    // Обчислення довжини тексту
    size_t source_len = 0;
    while (text[source_len] != '\0') source_len++;

    // Обчислення довжини слова
    size_t target_len = 0;
    while (word[target_len] != '\0') target_len++;

    size_t result;

    // Перевірка: якщо слово порожнє або довше за текст — пошук неможливий
    if (target_len == 0 || target_len > source_len) {
        result = string::npos; 
    }
    else {
        result = string::npos;

        // Пошук слова в тексті "вручну", без використання стандартних функцій
        for (size_t i = 0; i <= source_len - target_len; ++i) {
            size_t j = 0;
            while (j < target_len && text[i + j] == word[j]) {
                ++j;
            }

            // Якщо всі символи співпали — зберегти позицію і припинити пошук
            if (j == target_len) {
                result = i;
                break;
            }
        }
    }

    // Виведення результату пошуку
    if (result != string::npos) {
        cout << "Слово знайдено на позиції: " << result << endl;
    }
    else {
        cout << "Не знайдено." << endl;
    }
}
