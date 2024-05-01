#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Все возможные буквы в номере машины
const vector<char> letters = { 'A', 'B', 'C', 'E', 'H', 'K', 'M', 'O', 'P', 'T', 'X', 'Y' };

// Рекурсивная функция для генерации номеров
void generateNumbers(string number, int letterCount, int digitCount) {
    if (letterCount == 0 && digitCount == 0) {
        cout << number << endl;
        return;
    }

    if (letterCount > 0) {
        for (char letter : letters) {
            generateNumbers(number + letter, letterCount - 1, digitCount);
        }
    }

    if (digitCount > 0) {
        for (int digit = 0; digit <= 9; ++digit) {
            generateNumbers(number + to_string(digit), letterCount, digitCount - 1);
        }
    }
}

int main() {
    // Начинаем с пустого номера, 3 буквы и 3 цифры
    generateNumbers("", 3, 3);
    return 0;
}
