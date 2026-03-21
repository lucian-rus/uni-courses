#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <fstream>

void read_from_file(int &n, std::vector<std::tuple<std::string, std::string, int, int, int>> &v) {
    std::ifstream fin("/home/lucian-rus/Desktop/dev/school/uni-courses/sd/lab1/elevi.txt");
    std::string nume, prenume;
    fin >> n;
    int a, b, c;
    for(int idx = 0; idx < n; idx++) {
        fin >> nume >> prenume >> a >> b >> c;
        v.push_back(std::tuple<std::string, std::string, int, int, int>(nume, prenume, a, b, c));
    } 

    fin.close();
}

int main() {
    std::vector<std::tuple<std::string, std::string, int, int, int>> v;
    // num of elems
    int n;
    read_from_file(n, v);

    std::sort(v.begin(), v.end(),
              [](std::tuple<std::string, std::string, int, int, int> a, std::tuple<std::string, std::string, int, int, int> b) {
                  return ((float)(((float)(std::get<2>(a)) + (float)(std::get<3>(a)) + (float)(std::get<4>(a)) / 3))
                          > (float)(((float)(std::get<2>(b)) + (float)(std::get<3>(b)) + (float)(std::get<4>(b)) / 3)));
              });

    for(const auto &item :v) {
        std::cout << std::get<0>(item) << ' ' << std::get<1>(item) << std::get<2>(item) << std::get<3>(item) << std::get<4>(item) << '\n';
    }

    return 0;
}