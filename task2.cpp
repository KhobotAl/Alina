#include <iostream> // Підключення бібліотеки для введення/виведення
#include <string> // Підключення бібліотеки для роботи з рядками
#include <fstream> // Підключення бібліотеки для роботи з файлами
#include <Windows.h> // Підключення бібліотеки для встановлення кодування Windows
using namespace std;

void runTask2() {
    // Встановлення кодування консолі для підтримки кирилиці
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "");

    string input; // Змінна для зберігання введеного рядка
    int choice; // Змінна для зберігання вибору користувача

    // Меню користувача для вибору дій
    do {
        cout << "\n--- Меню Завдання 2 ---\n";
        cout << "1. Ввести рядок\n";
        cout << "2. Перевірити рядок\n";
        cout << "3. Обробити рядок\n";
        cout << "4. Обробити файл\n";
        cout << "0. Назад до головного меню\n";
        cout << "Ваш вибір: ";
        cin >> choice;
        cin.ignore(); // Очистка буфера після вводу числа

        switch (choice) {
        // Ввід рядка користувачем
        case 1:
            cout << "Введіть рядок: ";
            getline(cin, input);
            break;

        // Перевірка рядка на коректність
        case 2: {
            if (input.empty()) {
                cout << "Спочатку введіть рядок.\n";
                break;
            }

            bool valid = true;
            for (char c : input) {
                if (c == ' ') continue; // Ігнорування пробілів
                unsigned char uc = static_cast<unsigned char>(c);
                // Перевірка на допустимі кириличні символи
                if (!((uc >= 192 && uc <= 223) || uc == 168 || uc == 170 || uc == 175 || uc == 178)) {
                    valid = false;
                    break;
                }
            }
            cout << (valid ? "Рядок коректний.\n" : "Некоректні символи у рядку.\n");
            break;
        }

        // Обробка рядка: заміна повторних літер на крапки
        case 3: {
            if (input.empty()) {
                cout << "Спочатку введіть рядок.\n";
                break;
            }

            // Перевірка на допустимі символи
            bool valid = true;
            for (char c : input) {
                if (c == ' ') continue;
                unsigned char uc = static_cast<unsigned char>(c);
                if (!((uc >= 192 && uc <= 223) || uc == 168 || uc == 170 || uc == 175 || uc == 178)) {
                    valid = false;
                    break;
                }
            }

            if (!valid) {
                cout << "Некоректний рядок.\n";
                break;
            }

            // Обробка: заміна повторних літер в слові на '.'
            string result;
            size_t i = 0;
            while (i < input.length()) {
                while (i < input.length() && input[i] == ' ') {
                    result += ' ';
                    ++i;
                }

                size_t start = i;
                while (i < input.length() && input[i] != ' ') {
                    ++i;
                }

                if (start < i) {
                    string word = input.substr(start, i - start);
                    if (!word.empty()) {
                        char firstChar = word[0];
                        for (size_t j = 0; j < word.length(); ++j) {
                            if (j != 0 && word[j] == firstChar)
                                result += '.';
                            else
                                result += word[j];
                        }
                    }
                }
            }

            cout << "Результат: " << result << endl;
            break;
        }

        // Обробка рядків з вхідного файлу і запис результатів у вихідний файл
        case 4: {
            string inName, outName;
            cout << "Ім'я вхідного файлу: "; getline(cin, inName);
            cout << "Ім'я вихідного файлу: "; getline(cin, outName);

            ifstream inFile(inName); // Відкриття вхідного файлу
            ofstream outFile(outName); // Відкриття вихідного файлу
 
            if (!inFile || !outFile) {
                cout << "Помилка відкриття файлів.\n";
                break;
            }

            string line;
            // Читання рядків з вхідного файлу
            while (getline(inFile, line)) {
                bool valid = true;
                // Перевірка рядка на допустимі символи
                for (char c : line) {
                    if (c == ' ') continue;
                    unsigned char uc = static_cast<unsigned char>(c);
                    if (!((uc >= 192 && uc <= 223) || uc == 168 || uc == 170 || uc == 175 || uc == 178)) {
                        valid = false;
                        break;
                    }
                }

                if (!valid) {
                    outFile << "[Некоректний рядок]" << endl;
                }
                else {
                    string result;
                    size_t i = 0;
                    while (i < line.length()) {
                        while (i < line.length() && line[i] == ' ') {
                            result += ' ';
                            ++i;
                        }

                        size_t start = i;
                        while (i < line.length() && line[i] != ' ') {
                            ++i;
                        }

                        if (start < i) {
                            string word = line.substr(start, i - start);
                            if (!word.empty()) {
                                char firstChar = word[0];
                                for (size_t j = 0; j < word.length(); ++j) {
                                    if (j != 0 && word[j] == firstChar)
                                        result += '.';
                                    else
                                        result += word[j];
                                }
                            }
                        }
                    }

                    outFile << result << endl;
                }
            }

            cout << "Файл оброблено.\n";
            break;
        }

        // Повернення до головного меню
        case 0:
            cout << "Повернення до головного меню.\n";
            break;

        // Обробка неправильного вибору
        default:
            cout << "Невірний вибір.\n";
        }

    } while (choice != 0); // Повторювати, поки не буде вибрано "0"
}
