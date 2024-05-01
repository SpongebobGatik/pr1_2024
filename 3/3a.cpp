#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Car {
    string number;
    string model;
};

int main() {
    queue<Car> cars;

    // Добавляем заявки в очередь
    cars.push({"A123BC", "Toyota"});
    cars.push({"B456DE", "BMW"});
    cars.push({"C789FG", "Mercedes"});

    while (!cars.empty()) {
        Car car = cars.front();
        cout << "Обрабатывается автомобиль " << car.model << " с номером " << car.number << endl;

        // Удаляем заявку из очереди после обработки
        cars.pop();
    }

    return 0;
}
