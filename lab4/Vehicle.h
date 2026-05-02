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
        std::cout << "Mae " << wheels << " koles ta " << engine << " dvyhun.\nSyhnalyt " << sound << " holosom: ";
        return 1;
    };
};

class Car : public Vehicle
{
public:
    Car()
    {
        int e = SetWheels(4);
        e = SetEngine("benzynovyj");
        e = SetSound("huchnym");
        e = ShowVehicle();
        e = Honk();
    };

    int Honk()
    {
        std::cout << "Bip-bip! Biiip!";
        return 1;
    };
};

class Motorcycle : public Vehicle
{
public:
    Motorcycle()
    {
        int e = SetWheels(2);
        e = SetEngine("benzynovyj");
        e = SetSound("hromkim");
        e = ShowVehicle();
        e = Honk();
    };

    int Honk()
    {
        std::cout << "Vrum-vrum! Brrr!";
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
        std::cout << "\nMarka avto: " << brand;
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
        std::cout << "\nTse elektro " << brand << " " << model << ". Batareya: " << battery << " kWh. Vidklykayetsya na: " << model;
    }
};
