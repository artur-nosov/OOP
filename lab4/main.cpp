#include "Vehicle.h"

int main()
{
    std::cout << "=== Stvoryuyemo Vehicle ===" << std::endl;
    Vehicle *v = new Vehicle();
    int e = v->SetEngine("benzynovyj");
    e = v->SetWheels(4);
    e = v->SetSound("stranniy");
    e = v->Honk();
    delete v;

    std::cout << std::endl << std::endl;
    std::cout << "=== Stvoryuyemo Car ===" << std::endl;
    Car *car = new Car();
    delete car;

    std::cout << std::endl << std::endl;
    std::cout << "=== Stvoryuyemo Motorcycle ===" << std::endl;
    Motorcycle *moto = new Motorcycle();
    delete moto;

    std::cout << std::endl << std::endl;
    std::cout << "=== Stvoryuyemo SportsCar ===" << std::endl;
    SportsCar *sport = new SportsCar("BMW");
    delete sport;

    std::cout << std::endl << std::endl;
    std::cout << "=== Stvoryuyemo ElectricSportsCar ===" << std::endl;
    ElectricSportsCar *tesla = new ElectricSportsCar("Tesla", "Model S", 100);
    delete tesla;

    std::cout << std::endl;
    return 0;
}
