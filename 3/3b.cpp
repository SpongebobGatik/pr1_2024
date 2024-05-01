#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Task {
    string carNumber;
    string taskDescription;
};

int main() {
    queue<Task> tasks;

    // Добавляем задачи в очередь
    tasks.push({"A123BC", "Проверить тормозную систему"});
    tasks.push({"B456DE", "Заменить масло в двигателе"});
    tasks.push({"C789FG", "Проверить состояние шин"});

    while (!tasks.empty()) {
        Task task = tasks.front();
        cout << "Выполняется задача для автомобиля " << task.carNumber << ": " << task.taskDescription << endl;

        // Удаляем задачу из очереди после выполнения
        tasks.pop();
    }

    return 0;
}
