#include <iostream>
#include <vector>

void concatenare_vector(std::vector<int> &vec1, std::vector<int> &vec2, std::vector<int> &res) {
    for (int i : vec1) {
        res.push_back(i);
    }

    for (int i : vec2) {
        res.push_back(i);
    }
}

int main() {
    std::vector<int> vec1;
    std::vector<int> vec2;
    std::vector<int> res;

    int n;
    std::cout << "dimensiune vec1: ";
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        int aux;
        std::cin >> aux;

        vec1.push_back(aux);
    }

    std::cout << "dimensiune vec2: ";
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int aux;
        std::cin >> aux;

        vec2.push_back(aux);
    }

    concatenare_vector(vec1, vec2, res);
    for (auto val : res) {
        std::cout << val << ' ';
    }
    std::cout << '\n';

    return 0;
}
