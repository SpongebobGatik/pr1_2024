#include <iostream>
#include <queue>
using namespace std;

// Структура данных для хранения информации о безопасности автомобильного транспорта
struct CarSafetyData {
    string carModel;
    int safetyRating;
};

int main() {
    // Создаем очередь для хранения данных о безопасности автомобильного транспорта
    queue<CarSafetyData> buffer;

    // Добавляем данные в буфер
    buffer.push({"Model S", 5});
    buffer.push({"Model 3", 5});
    
    // Обрабатываем данные из буфера
    while (!buffer.empty()) {
        CarSafetyData data = buffer.front();
        buffer.pop();
        cout << "Car Model: " << data.carModel << ", Safety Rating: " << data.safetyRating << endl;
    }

    return 0;
}
