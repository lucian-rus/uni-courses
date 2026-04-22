#include <fstream>
#include <iostream>
#include <queue>

using CustomPQ = std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, Comparator>;
struct Comparator {
    bool operator()(const std::pair<std::string, int> &p1, const std::pair<std::string, int> &p2) const {
        if (p1.second == p2.second)
            return p1.first < p2.first;
        if (p1.second < p2.second)
            return true;
        return false;
        // return p1.second < p2.second
    }
};

void citire(std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, Comparator> &pacienti) {
    std::ifstream fis("pacienti.txt");
    std::string   numePacient;
    int           gradUrgenta;
    while (fis >> numePacient >> gradUrgenta) {
        // auto pacient = std::make_pair(numePacient, gradUrgenta);
        // std::pair<std::string, int> pacient = { numePacient, gradUrgenta };
        std::pair<std::string, int> pacient(numePacient, gradUrgenta);
        pacienti.push(pacient);
    }
    fis.close();
}

void afisare(CustomPQ pacienti) {
    while (!pacienti.empty()) {
        std::cout << pacienti.top().first << " " << pacienti.top().second << "\n";
        pacienti.pop();
    }
}

int main() {
    // less
    std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, Comparator> pacienti;
    citire(pacienti);
    afisare(pacienti);

    return 0;
}