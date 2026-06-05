#include <fstream>
#include <iostream>
#include <queue>
#include <stack>

typedef struct Node {
    char  val;
    Node *left;
    Node *right;
} Node_t;

typedef struct BinTree {
    Node_t *root;

    void print_bfs(void) {
        std::queue<Node *> q;
        q.push(root);

        // bfs pentru ca e mai usor sa vedem nivelurile
        while (!q.empty()) {
            if (q.front()->left != nullptr) {
                q.push(q.front()->left);
            }

            if (q.front()->right != nullptr) {
                q.push(q.front()->right);
            }

            std::cout << q.front()->val << ' ';
            q.pop();
        }

        std::cout << '\n';
    }

} BinTree_t;

void citire_din_fisier(std::vector<char> &expresie) {
    std::ifstream fin("sd/input/expresie-arbore.txt");

    char aux;
    while (fin >> aux) {
        // ignoram whitespace de la citire pentru a simplifica parcurgerea        
        if (aux != ' ') {
            expresie.push_back(aux);
        }
    }

    fin.close();
}

int main(void) {
    std::vector<char> expresie;
    citire_din_fisier(expresie);

    for (const auto &c : expresie) {
        std::cout << c;
    }
    std::cout << '\n';

    return 0;
}