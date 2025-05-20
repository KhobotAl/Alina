#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

void runTask1() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "");

    const char* text = "Hello, world!";
    const char* word = "world";

    size_t source_len = 0;
    while (text[source_len] != '\0') source_len++;

    size_t target_len = 0;
    while (word[target_len] != '\0') target_len++;

    size_t result;
    if (target_len == 0 || target_len > source_len) {
        result = string::npos;
    }
    else {
        result = string::npos;
        for (size_t i = 0; i <= source_len - target_len; ++i) {
            size_t j = 0;
            while (j < target_len && text[i + j] == word[j]) {
                ++j;
            }
            if (j == target_len) {
                result = i;
                break;
            }
        }
    }

    if (result != string::npos) {
        cout << "Слово знайдено на позиції: " << result << endl;
    }
    else {
        cout << "Не знайдено." << endl;
    }
}
