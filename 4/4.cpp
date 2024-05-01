#include <string>
#include <vector>
#include <iostream>
using namespace std;

class NodeHashTable {
public:
    string key;
    pair<string, int> element;
    NodeHashTable* next;
    NodeHashTable* prev;
    NodeHashTable() : key(""), element(make_pair("", 0)), next(nullptr), prev(nullptr) {}
    NodeHashTable(const string& key, const string& element) : key(key), element(make_pair(element, 1)), next(nullptr), prev(nullptr) {}
};

class HashTable {
public:
    vector<NodeHashTable*> nodes;
    int count;
    HashTable() : nodes(vector<NodeHashTable*>(100000, nullptr)), count(0) {}
    void printHashTable();
    void freeHashTable();
    void HSET(const string& key, const string& value);
    void HDEL(const string& key);
    pair<string, int> HGET(const string& key);
};

// Функция для вычисления хеша
int calculateHashT(const string& element) {
    int hash = 0;
    for (char c : element) {
        hash = 31 * hash + c;
    }
    return abs(hash) % 100000;
}

// Функция для добавления элемента в хеш-таблицу
void HashTable::HSET(const string& key, const string& value) {
    int hash = calculateHashT(key);
    NodeHashTable* newNode = new NodeHashTable(key, value);
    NodeHashTable* current = nodes[hash];
    while (current != nullptr) {
        if (current->key == key) {
            current->element.second++; // Увеличиваем частоту
            delete newNode;
            return;
        }
        if (current->next == nullptr) {
            break;
        }
        current = current->next;
    }
    if (current == nullptr) {
        nodes[hash] = newNode;
    }
    else {
        current->next = newNode;
        newNode->prev = current;
    }
    count++;
}

// Функция для получения элемента из хеш-таблицы
pair<string, int> HashTable::HGET(const string& key) {
    int hash = calculateHashT(key);
    NodeHashTable* current = nodes[hash]; // Получаем узел по хеш-ключу
    while (current != nullptr) { // Перебираем узлы в цепочке
        if (current->key == key) { // Если ключ совпадает
            return current->element;
        }
        current = current->next; // Переходим к следующему узлу
    }
    return {"", 0 };
}

// Функция для удаления элемента из хеш-таблицы
void HashTable::HDEL(const string& key) {
    int hash = calculateHashT(key);
    NodeHashTable* current = nodes[hash]; // Получаем узел по хеш-ключу
    NodeHashTable* nodeToRemove = nullptr;
    while (current != nullptr) { // Перебираем узлы в цепочке
        if (current->key == key) { // Если ключ совпадает
            nodeToRemove = current; // Устанавливаем узел для удаления
            break;
        }
        current = current->next; // Переходим к следующему узлу
    }
    if (nodeToRemove != nullptr) {
        if (nodeToRemove->prev != nullptr) { // Если у узла есть предыдущий узел
            nodeToRemove->prev->next = nodeToRemove->next; // Удаляем узел из цепочки
        }
        else {
            nodes[hash] = nodeToRemove->next; // Устанавливаем следующий узел как начало цепочки
        }
        if (nodeToRemove->next != nullptr) { // Если у узла есть следующий узел
            nodeToRemove->next->prev = nodeToRemove->prev; // Устанавливаем предыдущий узел для следующего узла
        }
        // Освобождаем память удаляемого узла
        delete nodeToRemove;
        count--;
    }
    else {
        cout << "Ключ не найден.\n";
    }
}

// Функция для освобождения памяти хеш-таблицы
void HashTable::freeHashTable() {
    for (int i = 0; i < 100000; i++) {
        NodeHashTable* current = nodes[i];
        while (current != nullptr) {
            NodeHashTable* temp = current;
            current = current->next;
            delete temp;
        }
        nodes[i] = nullptr; // Установка указателя в nullptr после удаления узлов
    }
}

// Функция для вывода хеш-таблицы
void HashTable::printHashTable() {
    cout << "Хеш-таблица:\n";
    for (int i = 0; i < 100000; i++) {
        NodeHashTable* current = nodes[i];
        if (current != nullptr) {
            cout << "Индекс " << i << ": ";
            while (current != nullptr) {
                cout << "(" << current->key << ", " << current->element.first << ", " << current->element.second << ") ";
                current = current->next;
            }
            cout << "\n";
        }
    }
}

int main() {
    setlocale(LC_ALL, "Rus");
    HashTable hashTable;
    // Добавление элементов
    hashTable.HSET("ключ1", "значение1");
    hashTable.HSET("ключ2", "значение2");
    hashTable.HSET("ключ3", "значение3");
    // Повторное добавление элемента с тем же ключом увеличивает частоту
    hashTable.HSET("ключ1", "значение1");
    // Вывод хеш-таблицы
    hashTable.printHashTable();
    // Получение элемента по ключу
    pair<string, int> value = hashTable.HGET("ключ1");
    if (!value.first.empty()) {
        cout << "Значение для 'ключ1': " << value.first << "\n";
    }
    else {
        cout << "'ключ1' не найден.\n";
    }
    // Удаление элемента по ключу
    hashTable.HDEL("ключ2");
    // Вывод хеш-таблицы после удаления элемента
    hashTable.printHashTable();
    // Освобождение памяти хеш-таблицы
    hashTable.freeHashTable();
    return 0;
}
