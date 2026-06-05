#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

enum Combustibil {
    BENZINA,
    MOTORINA
};

class Automobile {
private:
    char* model;
    char* producator;
    int putere;

public:
    Combustibil combustibil;
    // Constructor implicit
    Automobile() : model(nullptr), producator(nullptr), putere(0), combustibil(BENZINA) {}

    // Constructor cu parametri
    Automobile(const char* model, const char* producator, int putere, Combustibil combustibil)
        : model(nullptr), producator(nullptr), putere(putere), combustibil(combustibil) {
        cout << putere << " putere";
        if (putere < 200 || putere > 1500) {
            throw invalid_argument("Puterea trebuie să fie între 200 și 1500.");
        }
        this->model = new char[strlen(model) + 1];
        strcpy(this->model, model);
        this->producator = new char[strlen(producator) + 1];
        strcpy(this->producator, producator);
    }

    // Destructor
    ~Automobile() {
        delete[] model;
        delete[] producator;
    }

    // Constructor de copiere
    Automobile(const Automobile& other)
        : model(nullptr), producator(nullptr) {
        *this = other;
    }

    // Operator =
    Automobile& operator=(const Automobile& other) {
        if (this != &other) {
            delete[] model;
            delete[] producator;

            model = new char[strlen(other.model) + 1];
            strcpy(model, other.model);
            producator = new char[strlen(other.producator) + 1];
            strcpy(producator, other.producator);

            putere = other.putere;
            combustibil = other.combustibil;
        }
        return *this;
    }

    // Supraîncărcarea operatorului <
    bool operator<(const Automobile& other) const {
        return putere < other.putere;
    }

    // Supraîncărcarea operatorului >>
    friend istream& operator>>(istream& is, Automobile& autoMob) {
        char buffer[256];
        cout << "Model: ";
        is >> ws; // Ignorăm spații whitespace
        is.getline(buffer, sizeof(buffer));
        delete[] autoMob.model;
        autoMob.model = new char[strlen(buffer) + 1];
        strcpy(autoMob.model, buffer);

        cout << "Producător: ";
        is >> ws; // Ignorăm spații whitespace
        is.getline(buffer, sizeof(buffer));
        delete[] autoMob.producator;
        autoMob.producator = new char[strlen(buffer) + 1];
        strcpy(autoMob.producator, buffer);

        cout << "Putere: ";
        is >> autoMob.putere;
        if (autoMob.putere < 200 || autoMob.putere > 1500) {
            throw invalid_argument("Puterea trebuie să fie între 200 și 1500.");
        }

        cout << "Combustibil (0 - BENZINA, 1 - MOTORINA): ";
        int combustibil;
        is >> combustibil;
        if (combustibil == 0) {
            autoMob.combustibil = BENZINA;
        } else if (combustibil == 1) {
            autoMob.combustibil = MOTORINA;
        } else {
            throw invalid_argument("Combustibilul trebuie să fie 0 sau 1.");
        }

        return is;
    }

    // Supraîncărcarea operatorului <<
    friend ostream& operator<<(ostream& os, const Automobile& autoMob) {
        os << "Model: " << autoMob.model << endl;
        os << "Producător: " << autoMob.producator << endl;
        os << "Putere: " << autoMob.putere << endl;
        os << "Combustibil: " << (autoMob.combustibil == BENZINA ? "BENZINA" : "MOTORINA") << endl;
        return os;
    }
};

int main() {
    ifstream inputFile("autoturisme.txt");
    if (!inputFile.is_open()) {
        cerr << "Nu s-a putut deschide fișierul." << endl;
        return 1;
    }

    vector<Automobile> autoturisme;

    int N;
    cout << "Număr de autoturisme: ";
    cin >> N;

    for (int i = 0; i < N; ++i) {
        Automobile autoMob;
        inputFile >> autoMob;
        autoturisme.push_back(autoMob);
    }

    // Filtrăm și sortăm autoturismele
    vector<Automobile> benzina, motorina;

    for (const auto& autoMob : autoturisme) {
        if (autoMob.combustibil == BENZINA) {
            benzina.push_back(autoMob);
        } else {
            motorina.push_back(autoMob);
        }
    }

    sort(benzina.begin(), benzina.end());
    sort(motorina.begin(), motorina.end());

    cout << "Autoturisme pe BENZINĂ:" << endl;
    for (const auto& autoMob : benzina) {
        cout << autoMob << endl;
    }

    cout << "Autoturisme pe MOTORINĂ:" << endl;
    for (const auto& autoMob : motorina) {
        cout << autoMob << endl;
    }

    inputFile.close();
    return 0;
}