#include <iostream>

// Базовый класс
class VehicleSafety {
public:
    virtual void safetyFeature() = 0; // Чистая виртуальная функция
};

// Производный класс: CarSafety
class CarSafety : public VehicleSafety {
public:
    void safetyFeature() override {
        std::cout << "Автомобиль: ABS, подушки безопасности, система стабилизации и что-то ещё" << std::endl;
    }
};

// Производный класс: BusSafety
class BusSafety : public VehicleSafety {
public:
    void safetyFeature() override {
        std::cout << "Автобус: аварийные выходы, огнетушители, система стабилизации и что-то ещё" << std::endl;
    }
};

int main() {
    setlocale(LC_ALL, "Rus");
    CarSafety car;
    BusSafety bus;
    VehicleSafety* vehicle1 = &car;
    VehicleSafety* vehicle2 = &bus;
    vehicle1->safetyFeature();
    vehicle2->safetyFeature();
    return 0;
}
