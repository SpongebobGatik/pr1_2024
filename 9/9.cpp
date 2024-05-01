#include <iostream>
#include <map>
#include <vector>
#include <string>

// a. Создание словаря с ключами-строками и значениями-списками чисел
auto createDictionary() {
    std::map<std::string, std::vector<int>> dictionary;
    dictionary["speed_limits"] = { 30, 50, 60, 70, 90, 110, 130 }; // скоростные ограничения
    dictionary["seatbelt_fines"] = { 100, 200, 500, 1000 }; // штрафы за не использование ремня безопасности
    return dictionary;
}

// b. Функция, которая повторяет строку указанное количество раз
auto repeatString(int count, const std::string& str) {
    std::string result;
    for (int i = 0; i < count; ++i) {
        result += str;
    }
    return result;
}

int main() {
    auto dictionary = createDictionary();
    for (const auto& pair : dictionary) {
        std::cout << pair.first << ": ";
        for (int num : pair.second) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    std::cout << repeatString(4, "AVE ") << "AVTF" << std::endl;

    return 0;
}
