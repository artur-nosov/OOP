#include "Vehicle.h"
#include <windows.h>

int main()
{
    // Налаштування консолі для підтримки кирилиці (кодування UTF-8)
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    std::cout << "=== Створюємо Vehicle ===" << std::endl;
    Vehicle *v = new Vehicle();
    int e = v->SetEngine("бензиновий");
    e = v->SetWheels(4);
    e = v->SetSound("дивовижний");
    e = v->Honk();
    delete v;

    std::cout << std::endl << std::endl;
    std::cout << "=== Створюємо Car ===" << std::endl;
    Car *car = new Car();
    delete car;

    std::cout << std::endl << std::endl;
    std::cout << "=== Створюємо Motorcycle ===" << std::endl;
    Motorcycle *moto = new Motorcycle();
    delete moto;

    std::cout << std::endl << std::endl;
    std::cout << "=== Створюємо SportsCar ===" << std::endl;
    SportsCar *sport = new SportsCar("BMW");
    delete sport;

    std::cout << std::endl << std::endl;
    std::cout << "=== Створюємо ElectricSportsCar ===" << std::endl;
    ElectricSportsCar *tesla = new ElectricSportsCar("Tesla", "Model S", 100);
    delete tesla;

    std::cout << std::endl;
    return 0;
}
