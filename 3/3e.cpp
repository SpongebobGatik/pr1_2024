#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>

std::queue<int> tasks;
std::mutex mtx;
std::condition_variable cv;
bool finished = false;

void producer(int id) {
    for (int i = 0; i < 10; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::unique_lock<std::mutex> lock(mtx);
        std::cout << "Producer " << id << " добавил задачу " << i << std::endl;
        tasks.push(i);
        cv.notify_all();
    }
}

void consumer(int id) {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return !tasks.empty() || finished; });
        if (finished && tasks.empty()) {
            return;
        }
        int value = tasks.front();
        tasks.pop();
        std::cout << "Consumer " << id << " выполнил задачу " << value << std::endl;
        lock.unlock();
        cv.notify_all();
    }
}

int main() {
    setlocale(LC_ALL, "Rus");
    std::thread producers[2];
    std::thread consumers[2];

    for (int i = 0; i < 2; ++i) {
        producers[i] = std::thread(producer, i + 1);
        consumers[i] = std::thread(consumer, i + 1);
    }

    for (int i = 0; i < 2; ++i) {
        producers[i].join();
    }

    finished = true;
    cv.notify_all();

    for (int i = 0; i < 2; ++i) {
        consumers[i].join();
    }

    return 0;
}
