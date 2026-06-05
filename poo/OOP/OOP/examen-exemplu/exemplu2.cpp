#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

class Car {
private:
    std::string model;
    std::string producer;
    int power;

public:
    enum class FuelType { BENZINA, MOTORINA };
    FuelType fuelType;
    // Constructor default
    Car() : power(0), fuelType(FuelType::BENZINA) {}

    // Constructor cu parametri
    Car(const std::string& model, const std::string& producer, int power, FuelType fuelType) 
        : model(model), producer(producer), power(power), fuelType(fuelType) {
        if (power < 200 || power > 1500) {
            throw std::invalid_argument("Power must be in the range [200, 1500]");
        }
    }

    // Constructor de copiere
    Car(const Car& other) : model(other.model), producer(other.producer), power(other.power), fuelType(other.fuelType) {}

    // Operator =
    Car& operator=(const Car& other) {
        if (this != &other) {
            model = other.model;
            producer = other.producer;
            power = other.power;
            fuelType = other.fuelType;
        }
        return *this;
    }

    // Destructor
    ~Car() {}

    // Supraîncărcarea operatorului >> pentru citire
    friend std::istream& operator>>(std::istream& is, Car& car) {
        is >> car.model >> car.producer >> car.power;
        std::string fuelStr;
        is >> fuelStr;
        if (fuelStr == "BENZINA") {
            car.fuelType = Car::FuelType::BENZINA;
        } else if (fuelStr == "MOTORINA") {
            car.fuelType = Car::FuelType::MOTORINA;
        } else {
            throw std::invalid_argument("Invalid fuel type");
        }
        return is;
    }

    // Supraîncărcarea operatorului << pentru afișare
    friend std::ostream& operator<<(std::ostream& os, const Car& car) {
        os << car.model << " " << car.producer << " " << car.power << " " 
           << (car.fuelType == Car::FuelType::BENZINA ? "BENZINA" : "MOTORINA");
        return os;
    }

    // Supraîncărcarea operatorului < pentru comparare după putere
    bool operator<(const Car& other) const {
        return power < other.power;
    }

    // Getter pentru fuelType (pentru a putea accesa enum-ul în afara clasei)
    FuelType getFuelType() const {
        return fuelType;
    }
};

int main() {
    std::ifstream file("cars.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    int N;
    file >> N;
    std::vector<Car> cars(N);

    for (int i = 0; i < N; ++i) {
        try {
            file >> cars[i];
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error reading car data: " << e.what() << std::endl;
            return 1;
        }
    }
    file.close();

    // Sortarea vectorului de autoturisme în funcție de tipul combustibilului și putere
    std::sort(cars.begin(), cars.end());

    // Afișarea listei sortate
    for (const auto& car : cars) {
        if (car.getFuelType() == Car::FuelType::BENZINA) {
            std::cout << "BENZINA: " << car << std::endl;
        } else {
            std::cout << "MOTORINA: " << car << std::endl;
        }
    }

    return 0;
}