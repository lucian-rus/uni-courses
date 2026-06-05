#include <algorithm>
#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#include <vector>

using TreeNode = std::tuple<int, int, int>;

typedef struct BinTree {
    std::vector<TreeNode> node_list;

    void print(void) {
        for (const auto &n : node_list) {
            int val   = std::get<0>(n);
            int left  = std::get<1>(n);
            int right = std::get<2>(n);

            // daca nu avem copil pt nodul dat -> -1
            int child_left  = left != -1 ? std::get<0>(node_list[left]) : -1;
            int child_right = right != -1 ? std::get<0>(node_list[right]) : -1;

            std::cout << "nodul " << val << " are copii: " << child_left << " si " << child_right << '\n';
        }
    }

    void print_raw(void) {
        for (const auto &n : node_list) {
            int val   = std::get<0>(n);
            int left  = std::get<1>(n);
            int right = std::get<2>(n);

            std::cout << val << ' ' << left << ' ' << right << ' ';
        }
        std::cout << '\n';
    }

    ///////////////////////////////////////// EGALITATE

    // overload la operatorul `==` ca sa il putem folosi pentru comparatie
    // folosim `std::equal` pentru ca e mai safe
    bool operator==(const BinTree &b) const {
        return std::equal(node_list.begin(), node_list.end(), b.node_list.begin(), b.node_list.end());
    }

} BinTree_t;

void citire_din_fisier_3_vectori(BinTree_t &tree) {
    std::ifstream fin("sd/input/2-vec-tree.txt");

    // vector in care punem input-ul
    std::vector<std::string> input;

    std::string aux;
    while (std::getline(fin, aux, ' ')) {
        input.push_back(aux);
    }

    // putem sa parcurgem doar primele 1/3 elemente, pentru ca avem 3 vectori de lungimi egale
    // reducem size-ul inputului si construim ceilalti doi indecsi necesari
    int row_size = input.size() / 3;
    for (int i = 0; i < row_size; i++) {
        int val   = stoi(input[(row_size * 0) + i]);
        int left  = input[(row_size * 1) + i] != "*" ? stoi(input[(row_size * 1) + i]) : -1;
        int right = input[(row_size * 2) + i] != "*" ? stoi(input[(row_size * 2) + i]) : -1;

        tree.node_list.push_back(TreeNode(val, left, right));
    }

    fin.close();
}

// functie generica de extragere a datelor din lista interna
void get_data(int &val, int &left, int &right, BinTree_t *tree, const int &index) {
    val   = std::get<0>(tree->node_list[index]);
    left  = std::get<1>(tree->node_list[index]);
    right = std::get<2>(tree->node_list[index]);
}

///////////////////////////////////////// INALTIME
void inaltime_subarborde(BinTree_t *tree, const int &index, int &max_height) {
    int val, left, right;
    get_data(val, left, right, tree, index);

    // static ca sa pastram valoarea, sa nu trebuiasca sa o tot plimbam
    static int curr_height = 0;

    if (left != -1) {
        curr_height += 1;
        inaltime_subarborde(tree, left, max_height);
    }

    if (right != -1) {
        curr_height += 1;
        inaltime_subarborde(tree, right, max_height);
    }

    if (curr_height > max_height) {
        max_height = curr_height;
    }

    curr_height--;
}

///////////////////////////////////////// PARCURGERI

// RSD = preorder
// SRD = inorder
// SDR = postdorder

// dam ca param si `index` ca sa ne fie mai usor cu parcurgerea prin recursivitate
void rsd(BinTree_t *tree, const int &index) {
    int val, left, right;
    get_data(val, left, right, tree, index);

    std::cout << val << ' ';
    if (left != -1) {
        rsd(tree, left);
    }

    if (right != -1) {
        rsd(tree, right);
    }
}

void srd(BinTree_t *tree, const int &index) {
    int val, left, right;
    get_data(val, left, right, tree, index);

    if (left != -1) {
        srd(tree, left);
    }

    std::cout << val << ' ';

    if (right != -1) {
        srd(tree, right);
    }
}

void sdr(BinTree_t *tree, const int &index) {
    int val, left, right;
    get_data(val, left, right, tree, index);

    if (left != -1) {
        sdr(tree, left);
    }

    if (right != -1) {
        sdr(tree, right);
    }

    std::cout << val << ' ';
}

void niveluri(BinTree_t *tree, const int &index) {
    std::queue<int> q;
    q.push(index);

    while (!q.empty()) {
        int curr_index = q.front();
        q.pop();

        int val, left, right;
        get_data(val, left, right, tree, curr_index);

        std::cout << val << ' ';

        if (left != -1) {
            q.push(left);
        }
        if (right != -1) {
            q.push(right);
        }
    }
}

///////////////////////////////////////// FRUNZE
void frunze(BinTree_t *tree, const int &index) {
    int val, left, right;
    get_data(val, left, right, tree, index);

    if (left != -1) {
        frunze(tree, left);
    }

    if (right != -1) {
        frunze(tree, right);
    }

    // o sa fie egale doar daca e frunza
    if (left == right) {
        std::cout << val << ' ';
    }
}

int main(void) {
    BinTree_t tree;
    citire_din_fisier_3_vectori(tree);

    tree.print();
    tree.print_raw();

    int max_height = -1;
    inaltime_subarborde(&tree, 0, max_height);
    std::cout << "inaltime: " << max_height << '\n';

    std::cout << "rsd: ";
    rsd(&tree, 0);
    std::cout << '\n';

    std::cout << "srd: ";
    srd(&tree, 0);
    std::cout << '\n';

    std::cout << "sdr: ";
    sdr(&tree, 0);
    std::cout << '\n';

    std::cout << "niveluri: ";
    niveluri(&tree, 0);
    std::cout << '\n';

    std::cout << "frunze: ";
    frunze(&tree, 0);
    std::cout << '\n';

    BinTree_t b;
    b.node_list.push_back(TreeNode(20, 1, 2));
    b.node_list.push_back(TreeNode(15, 3, 4));
    b.node_list.push_back(TreeNode(30, 5, 6));
    b.node_list.push_back(TreeNode(9, 7, -1));
    b.node_list.push_back(TreeNode(17, -1, -1));
    b.node_list.push_back(TreeNode(24, 8, -1));
    b.node_list.push_back(TreeNode(36, -1, 9));
    b.node_list.push_back(TreeNode(0, -1, -1));
    b.node_list.push_back(TreeNode(22, -1, -1));
    b.node_list.push_back(TreeNode(45, -1, -1));

    std::cout << "a si b sunt egale: ";
    if (tree == b) {
        std::cout << "da\n";
    }
    else {
        std::cout << "nu\n";
    }
    return 0;
}