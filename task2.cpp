#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
using namespace std;

void runTask2() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "");

    string input;
    int choice;

    do {
        cout << "\n--- Меню Завдання 2 ---\n";
        cout << "1. Ввести рядок\n";
        cout << "2. Перевірити рядок\n";
        cout << "3. Обробити рядок\n";
        cout << "4. Обробити файл\n";
        cout << "0. Назад до головного меню\n";
        cout << "Ваш вибір: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            cout << "Введіть рядок: ";
            getline(cin, input);
            break;

        case 2: {
            if (input.empty()) {
                cout << "Спочатку введіть рядок.\n";
                break;
            }

            bool valid = true;
            for (char c : input) {
                if (c == ' ') continue;
                unsigned char uc = static_cast<unsigned char>(c);
                if (!((uc >= 192 && uc <= 223) || uc == 168 || uc == 170 || uc == 175 || uc == 178)) {
                    valid = false;
                    break;
                }
            }
            cout << (valid ? "Рядок коректний.\n" : "Некоректні символи у рядку.\n");
            break;
        }

        case 3: {
            if (input.empty()) {
                cout << "Спочатку введіть рядок.\n";
                break;
            }

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

        case 4: {
            string inName, outName;
            cout << "Ім'я вхідного файлу: "; getline(cin, inName);
            cout << "Ім'я вихідного файлу: "; getline(cin, outName);

            ifstream inFile(inName);
            ofstream outFile(outName);

            if (!inFile || !outFile) {
                cout << "Помилка відкриття файлів.\n";
                break;
            }

            string line;
            while (getline(inFile, line)) {
                bool valid = true;
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

        case 0:
            cout << "Повернення до головного меню.\n";
            break;

        default:
            cout << "Невірний вибір.\n";
        }

    } while (choice != 0);
}
