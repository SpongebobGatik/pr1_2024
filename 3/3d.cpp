#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Event {
    string type;
    string description;
};

int main() {
    queue<Event> events;

    // Добавляем события в очередь
    events.push({"Accident", "Авария на улице Мира"});
    events.push({"TrafficJam", "Пробка на проспекте Ленина"});
    events.push({"RoadWork", "Ремонт дороги на улице Советской"});

    // Обрабатываем события в порядке их поступления
    while (!events.empty()) {
        Event currentEvent = events.front();
        events.pop();

        cout << "Обрабатывается событие: " << currentEvent.type << endl;
        cout << "Описание: " << currentEvent.description << endl;
    }

    return 0;
}
