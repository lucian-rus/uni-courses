#include <iostream>
#include <vector>

void citire_vector_unidimensional(std::vector<int> &vec);
void afisare_vector_unidimensional(std::vector<int> vec);

bool putere_2(int num) {
    if(num == 1) {
        return true;
    }

    while(num > 1) {
        if(num % 2 != 0) {
            return false;
        }

        num = num / 2;
    }

    return true;
}

int gaseste_k(std::vector<int> vec) {
    int capat_puteri_2 = vec.size();
    int n = vec.size();

    for(int i = n - 1 ; i >= 0; i--) {
        if(putere_2(vec[i]) == false) {
            break;
        }

        capat_puteri_2--;
    }

    for(int k = 0; k < n; k++) {
        int suma = 0;
        
        for(int i = 0; i < k; i++) {
            suma = suma + vec[i];
        }   

        int produs = 1; 
        for(int i = n - 1; i >= n - 1 - k; i--) {
            produs = produs * vec[i];
        }

        std::cout << suma << ' ' << produs << '\n';
    }
    return 0;
}

int main() {
    std::vector<int> vec;

    citire_vector_unidimensional(vec);
    afisare_vector_unidimensional(vec);

    gaseste_k(vec);
    return 0;
}

void citire_vector_unidimensional(std::vector<int> &vec) {
    int n;
    std::cout << "dimensiune vector: ";
    std::cin >> n;
    vec.resize(n);

    for (int i = 0; i < n; i++) {
        std::cin >> vec[i];
    }
}

// Functia afisare_vector_unidimensional afiseaza elementele vectorului
// pe o singura linie.
// Parametru: vec - vectorul de afisat.

void afisare_vector_unidimensional(std::vector<int> vec) {
    for (int val : vec) {
        std::cout << val << ' ';
    }
    std::cout << '\n';
}
