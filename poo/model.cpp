#include <fstream>
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

class Autoturism {
  public:
    typedef enum {
        BENZINA = 0,
        MOTORINA,
    } Combustibil_t;

  private:
    char *m_prod;
    char *m_model;

    int m_putere;

    Combustibil_t m_combustibil;

  public:
    Autoturism() : m_prod(nullptr), m_model(nullptr), m_putere(0), m_combustibil(BENZINA) {
    }

    Autoturism(char *prod, char *model, int putere, Combustibil_t combustibil) {
        // mergem pe abordare fara initializator
        m_prod = new char[strlen(prod) + 1];
        strncpy(m_prod, prod, strlen(prod));

        m_model = new char[strlen(model) + 1];
        strncpy(m_model, model, strlen(model));

        m_putere      = putere;
        m_combustibil = combustibil;
    }

    Autoturism(const Autoturism &other) {
        m_prod = new char[strlen(other.m_prod) + 1];
        strcpy(m_prod, other.m_prod);

        m_model = new char[strlen(other.m_model) + 1];
        strcpy(m_model, other.m_model);

        m_putere      = other.m_putere;
        m_combustibil = other.m_combustibil;
    }

    ~Autoturism() {
        delete[] m_prod;
        delete[] m_model;
    }

    Autoturism &operator=(const Autoturism &other) {
        if (this != &other) {
            // Delete old data
            delete[] m_prod;
            delete[] m_model;

            // Copy new data
            m_prod = new char[strlen(other.m_prod) + 1];
            strcpy(m_prod, other.m_prod);

            m_model = new char[strlen(other.m_model) + 1];
            strcpy(m_model, other.m_model);

            m_putere      = other.m_putere;
            m_combustibil = other.m_combustibil;
        }
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &os, const Autoturism &car) {
        os << "Producator: " << car.m_prod << ", Model: " << car.m_model << ", Putere: " << car.m_putere
           << " CP, Combustibil: " << (car.m_combustibil == BENZINA ? "Benzina" : "Motorina");
        return os;
    }

    friend std::istream &operator>>(std::istream &is, Autoturism &car) {
        char prod[256], model[256];
        int  putere, combustibil;

        is >> prod >> model >> putere >> combustibil;

        // Delete old data if already initialized
        if (car.m_prod != nullptr)
            delete[] car.m_prod;
        if (car.m_model != nullptr)
            delete[] car.m_model;

        // Allocate and copy new data
        car.m_prod = new char[strlen(prod) + 1];
        strcpy(car.m_prod, prod);

        car.m_model = new char[strlen(model) + 1];
        strcpy(car.m_model, model);

        car.m_putere      = putere;
        car.m_combustibil = static_cast<Combustibil_t>(combustibil);

        return is;
    }

    bool operator<(const Autoturism &other) const {
        return this->m_putere < other.m_putere;
    }
};

int main(void) {
    std::ifstream inputFile("poo/input.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open input.txt" << std::endl;
        return 1;
    }

    std::vector<Autoturism> cars;
    Autoturism              temp;

    // Read all cars from file
    while (inputFile >> temp) {
        cars.push_back(temp);
    }

    inputFile.close();

    // Display all cars before sorting
    std::cout << "\nCars read from file (BEFORE SORT):\n";
    for (size_t i = 0; i < cars.size(); ++i) {
        std::cout << "Car " << (i + 1) << ": " << cars[i] << std::endl;
    }

    // Sort by power
    std::sort(cars.begin(), cars.end());

    // Display all cars after sorting
    std::cout << "\nCars after sorting by power (AFTER SORT):\n";
    for (size_t i = 0; i < cars.size(); ++i) {
        std::cout << "Car " << (i + 1) << ": " << cars[i] << std::endl;
    }

    return 0;
}