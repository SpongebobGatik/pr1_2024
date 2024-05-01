#include <iostream>
#include <fstream>
#include <string>
using namespace std;

template <typename T>
class Account {
private:
    T balance;
public:
    Account(T initial_balance) : balance(initial_balance) {}
    void deposit(T amount) { balance += amount; }
    void withdraw(T amount) { if (balance >= amount) balance -= amount; }
    T get_balance() const { return balance; }
};

template <typename T>
class Object {
private:
    T data[5];
public:
    Object(T d[5]) { for (int i = 0; i < 5; i++) data[i] = d[i]; }
    T get_data(int index) const { return data[index]; }
    void set_data(int index, T value) { data[index] = value; }
    int size() const { return 5; }
};

class User {
private:
    string login;
    string password;
public:
    User(string l, string p) : login(l), password(p) {}
    bool authenticate(string l, string p) { return l == login && p == password; }
    void change_password(string new_password) { password = new_password; }
    string get_profile() const { return "User Profile: " + login; }
};

class FileManager {
public:
    void create_file(const string& filename) {
        ofstream file(filename);
        file.close();
    }

    void delete_file(const string& filename) {
        remove(filename.c_str());
    }

    void rename_file(const string& old_filename, const string& new_filename) {
        rename(old_filename.c_str(), new_filename.c_str());
    }

    void write_to_file(const string& filename, const string& content) {
        ofstream file(filename);
        file << content;
        file.close();
    }

    string read_from_file(const string& filename) {
        ifstream file(filename);
        string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
        return content;
    }
};

int main() {
    // Создание объекта класса "Счет"
    Account<double> myAccount(100.0);
    myAccount.deposit(50.0);
    cout << "Balance: " << myAccount.get_balance() << endl;

    // Создание объекта класса "Объект"
    int arr[5] = { 1, 2, 3, 4, 5 };
    Object<int> myObject(arr);
    cout << "Object data at index 2: " << myObject.get_data(2) << endl;

    // Создание объекта класса "Пользователь"
    User myUser("username", "password");
    if (myUser.authenticate("username", "password")) {
        cout << "Authentication successful!" << endl;
    }

    // Создание объекта класса "Файловый менеджер"
    FileManager myFileManager;
    myFileManager.create_file("test.txt");
    myFileManager.write_to_file("test.txt", "Hello, world!");
    cout << "File content: " << myFileManager.read_from_file("test.txt") << endl;

    return 0;
}
