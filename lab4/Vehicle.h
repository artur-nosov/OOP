#include <iostream>

class Vehicle
{
    std::string engine;
    int wheels;
    std::string sound;

public:
    int SetEngine(std::string engine_type)
    {
        engine = engine_type;
        return 1;
    };

    int SetWheels(int number_of_wheels)
    {
        wheels = number_of_wheels;
        return 1;
    };

    int SetSound(std::string vehicle_sound)
    {
        sound = vehicle_sound;
        return 1;
    };

    int Honk()
    {
        std::cout << "...";
        return 1;
    };

protected:
    int ShowVehicle()
    {
        std::cout << "Має " << wheels << " коліс та " << engine << " двигун.\nСигналить " << sound << " голосом: ";
        return 1;
    };
};

class Car : public Vehicle
{
public:
    Car()
    {
        int e = SetWheels(4);
        e = SetEngine("бензиновий");
        e = SetSound("гучним");
        e = ShowVehicle();
        e = Honk();
    };

    int Honk()
    {
        std::cout << "Біп-біп! Біііп!";
        return 1;
    };
};

class Motorcycle : public Vehicle
{
public:
    Motorcycle()
    {
        int e = SetWheels(2);
        e = SetEngine("бензиновий");
        e = SetSound("гучним");
        e = ShowVehicle();
        e = Honk();
    };

    int Honk()
    {
        std::cout << "Врум-врум! Бррр!";
        return 1;
    };
};

class SportsCar : public Car
{
protected:
    std::string brand;

public:
    int SetBrand(std::string car_brand)
    {
        brand = car_brand;
        return 1;
    };

    SportsCar(std::string car_brand)
    {
        int e = SetBrand(car_brand);
        std::cout << "\nМарка авто: " << brand;
    }

    SportsCar() {}
};

class ElectricSportsCar : public SportsCar
{
    std::string model;
    int battery;

public:
    int SetModel(std::string car_model)
    {
        model = car_model;
        return 1;
    };

    int SetBattery(int capacity)
    {
        battery = capacity;
        return 1;
    };

    ElectricSportsCar(std::string car_brand, std::string car_model, int bat)
    {
        int e = SetBrand(car_brand);
        e = SetModel(car_model);
        e = SetBattery(bat);
        std::cout << "\nЦе електро " << brand << " " << model << ". Батарея: " << battery << " кВт·год. Відгукується на: " << model;
    }
};
