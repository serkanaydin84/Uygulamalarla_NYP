#include<iostream>
#include<string>
using std::string;

class Vehicle {
protected:
    string manufacturer;
    int year;
    string color;

public:
    string getManufacturer() {
        return manufacturer;
    }
    void setManufacturer(string value) {
        this->manufacturer = value;
    }

    int getYear() {
        return year;
    }
    void setYear(int value) {
        this->year = value;
    }

    string getColor() {
        return color;
    }
    void setColor(string value) {
        this->color = value;
    }

    Vehicle() {
        std::cout << "\nVehicle class'indan bir ornek turetildi. " << std::endl;
    }

    // : Vehicle() ifadesi ile ilk önce parametresiz constructor calışır sonra parametreli (overloading) constructor çalışır
    Vehicle(string manufacturer, int year, string color) : Vehicle(){  
        std::cout << "\nVehicle class'indan full parametrelerle bir ornek turetildi. " << std::endl; 
        this->manufacturer = manufacturer;
        this->year = year;
        this->color = color;
    }

    virtual void start() {
        std::cout << "Vehicle has been started. " << std::endl;
    }

    virtual void stop() {
        std::cout << "Vehicle has been stopped. " << std::endl;
    }

    virtual void drive() {
        std::cout << "Vehicle is being driven. " << std::endl;
    }

    virtual string toString() {
        return manufacturer + " - " + std::to_string(year) + " - " + color;
    }
 };

// Car sınıfı Vehicle sınıfından kalıtıldı. Yani Vehicle Sınıfının özelliklerini de kullanabilir 
class Car : public Vehicle {    
public:
    Car() {
        std::cout << "\nCar class'indan bir ornek turetildi. " << std::endl;
    }
    Car(string manufacturer, int year, string color) : Vehicle(manufacturer, year, color) {
        std::cout << "\nCar class'indan full parametrelerle bir ornek turetildi. " << std::endl;
    }
    void openSunroof() {
        std::cout << "Sunroof has been opened." << std::endl;
    }

    void drive() override {
        std::cout << "The car manufacturer by " << this->manufacturer << " is being driven " << std::endl;
    }

    void stop() override {
        std::cout << "The car manufacturer by " << this->manufacturer << " has been stopped " << std::endl;
    }
};

class Bus : public Vehicle {
public:
    Bus(string manufacturer, int year, string color) : Vehicle(manufacturer, year, color) {
        std::cout << "\nBus class'indan full parametrelerle bir ornek turetildi. " << std::endl;
    }

    void scheduling() {
        std::cout << "Otobus programlandi. " << std::endl;
    }

    void drive() override {
        std::cout << "The bus manufacturer by " << this->manufacturer << " is being driven " << std::endl;
    }

    void stop() override {
        std::cout << "The bus manufacturer by " << this->manufacturer << " has been stopped " << std::endl;
    }
};

class SchoolBus : public Bus {
public:
    SchoolBus(string manufacturer, int year, string color) : Bus(manufacturer, year, color) {
        std::cout << "\nSchoolBus class'indan full parametrelerle bir ornek turetildi. " << std::endl;
    }

    void getFare() {
        std::cout << "\ngeFare methodu cagrildi. " << std::endl;
    }

    void drive() override {
        std::cout << "The schoolbus manufacturer by " << this->manufacturer << " is being driven " << std::endl;
    }

    void stop() override {
        std::cout << "The schoolbus manufacturer by " << this->manufacturer << " has been stopped " << std::endl;
    }
};


int main() {
    // ilk önce base class ın consturactor çalışacak
    Vehicle item2 = Vehicle("Rifter", 2023, "Beyaz");
    std::cout << "Vehicle " << item2.getManufacturer() << " " << item2.getYear() << " " << item2.getColor() << std::endl;

    // sonra base class ın consturactor çalışacak,
    // hemen ardından kalıtılan class çalışacak
    Car item1 = Car();  // Car sınıfından nesne tanımlandı ancak Vehicle sınıfından kalıtıldığı için Vehicle sınıfının özelliklerini de kullanabiliyor
    item1.setManufacturer("TOGG");  // set - yazılma işlemi
    item1.setYear(2024);
    item1.setColor("Anadolu");
    std::cout << item1.toString() << std::endl;
    item1.openSunroof();

    // daha sonra tekrar base class ın consturactor çalışacak,
    // hemen ardından kalıtılan class ın parametreli consturactor ı çalışacak
    Car item3 = Car("Ford Focus", 2009, "Gri");  // Car sınıfından nesne tanımlandı ancak Vehicle sınıfından kalıtıldığı için Vehicle sınıfının özelliklerini de kullanabiliyor
    std::cout << item3.toString() << std::endl;
    item3.openSunroof();

    Bus item4 = Bus("Travego", 2015, "Mor");  // Bus sınıfından nesne tanımlandı ancak Vehicle sınıfından kalıtıldığı için Vehicle sınıfının özelliklerini de kullanabiliyor
    std::cout << item4.toString() << std::endl;
    item4.scheduling();

    SchoolBus item5 = SchoolBus("Isuzu", 2005, "Yeşil");
    std::cout << item5.toString() << std::endl;
    item5.scheduling();
    item5.getFare();

    item1.drive();
    item1.stop();

    item3.drive();
    item3.stop();
    
    item4.drive();
    item4.stop();
    
    item5.drive();
    item5.stop();



    char c = getchar();
    return 0;
}