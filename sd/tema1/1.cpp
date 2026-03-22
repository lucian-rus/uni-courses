#include <iostream>
#include <vector>

bool contine_cifre_pare(int num) {
    // daca nr e par, returneaza direct
    if ((num % 2) == 0) {
        return true;
    }

    // iteram sa vedem daca gasim cifre pare
    while (num != 0) {
        if (num % 2 == 0) {
            return true;
        }

        num /= 10;
    }

    return false;
}

// functie care genereaza un vector nou
std::vector<int> genereaza_vector_nou(const std::vector<int> &v) {
    std::vector<int> w;

    for (int item : v) {
        if (contine_cifre_pare(item) == true) {
            continue;
        }

        w.push_back(item);
        w.push_back(item);
    }

    return w;
}

void printeaza_vector(const std::vector<int> &v) {
    for (int item : v) {
        std::cout << item << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> v = {1, 2, 5, 13, 27, 22, 3, 14, 41, 57};
    printeaza_vector(v);
    std::vector<int> w = genereaza_vector_nou(v);
    printeaza_vector(w);

    return 0;
}