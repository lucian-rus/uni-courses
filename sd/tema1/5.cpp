#include <fstream>
#include <iostream>
#include <vector>

void citire_vector(std::vector<std::vector<int>> &mat, int &height, int &width) {
    std::ifstream fin("teren.txt");

    fin >> height >> width;
    // citeste elementele vectorului
    std::cout << "elementele vectorului:\n";
    for (int i = 0; i < height; i++) {
        std::vector<int> vec;
        for (int j = 0; j < width; j++) {
            int temp;
            fin >> temp;

            vec.push_back(temp);
        }
        mat.push_back(vec);
    }
}

void afisare_vector(const std::vector<std::vector<int>> &mat, const int &height, const int &width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            std::cout << mat[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

int main() {
    int width;
    int height;

    int vacute = 0;
    int gaste  = 0;

    std::vector<std::vector<int>> mat;
    citire_vector(mat, height, width);
    afisare_vector(mat, height, width);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (mat[i][j] == 0) {
                continue;
            }

            int north, south, west, east;

            west  = (j == 0) ? 0 : mat[i][j - 1];
            east  = (j == width - 1) ? 0 : mat[i][j + 1];
            north = (i == 0) ? 0 : mat[i - 1][j];
            south = (i == height - 1) ? 0 : mat[i + 1][j];

            if (north == 2 || south == 2 || west == 2 || east == 2) {
                mat[i][j - 1] = mat[i][j + 1] = mat[i - 1][j] = mat[i + 1][j] = mat[i][j] = 0;
                vacute++;
            }
            else {
                gaste++;
            }
        }
    }

    std::cout << "vacute: " << vacute << '\n';
    std::cout << "gaste:  " << gaste << '\n';

    return 0;
}