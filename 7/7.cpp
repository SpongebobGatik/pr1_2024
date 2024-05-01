#include <iostream>
#include <string>

// Базовый класс "Безопасность автомобильного транспорта"
class RoadSafety {
protected:
    std::string name; // название меры безопасности

public:
    RoadSafety(const std::string& n) : name(n) {}

    virtual void displayInfo() {
        std::cout << "Мера безопасности: " << name << std::endl;
    }
};

// Подкласс "Пассивная безопасность" (наследуется от RoadSafety)
class PassiveSafety : public RoadSafety {
private:
    int airbagsCount; // количество подушек безопасности

public:
    PassiveSafety(const std::string& n, int airbags) : RoadSafety(n), airbagsCount(airbags) {}

    void displayInfo() override {
        RoadSafety::displayInfo();
        std::cout << "Количество подушек безопасности: " << airbagsCount << std::endl;
    }
};

// Подкласс "Активная безопасность" (наследуется от RoadSafety)
class ActiveSafety : public RoadSafety {
private:
    bool hasABS; // наличие системы ABS
    bool hasESP; // наличие системы ESP

public:
    ActiveSafety(const std::string& n, bool abs, bool esp) : RoadSafety(n), hasABS(abs), hasESP(esp) {}

    void displayInfo() override {
        RoadSafety::displayInfo();
        std::cout << "Наличие системы ABS: " << (hasABS ? "Да" : "Нет") << std::endl;
        std::cout << "Наличие системы ESP: " << (hasESP ? "Да" : "Нет") << std::endl;
    }
};

// Подкласс "Профилактическая безопасность" (наследуется от RoadSafety)
class PreventiveSafety : public RoadSafety {
private:
    int maintenanceInterval; // интервал обслуживания в месяцах

public:
    PreventiveSafety(const std::string& n, int interval) : RoadSafety(n), maintenanceInterval(interval) {}

    void displayInfo() override {
        RoadSafety::displayInfo();
        std::cout << "Интервал обслуживания: " << maintenanceInterval << " месяцев" << std::endl;
    }
};

int main() {
    setlocale(LC_ALL, "Rus");
    PassiveSafety ps("Пассивная безопасность", 6);
    ActiveSafety as("Активная безопасность", true, true);
    PreventiveSafety pfs("Профилактическая безопасность", 12);

    ps.displayInfo();
    std::cout << std::endl;
    as.displayInfo();
    std::cout << std::endl;
    pfs.displayInfo();

    return 0;
}