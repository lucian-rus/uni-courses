#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

typedef struct Node {
    int   val;
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

void citire_din_fisier(std::vector<int> &srd, std::vector<int> &rsd) {
    std::ifstream fin("sd/input/rsdsrd.txt");

    std::vector<int> aux;

    int n;
    while (fin >> n) {
        aux.push_back(n);
    }

    // mergem doar pana la jumatate din cauza a cum citim inputul
    int j = aux.size() / 2;
    for (int i = 0; i < j; i++) {
        rsd.push_back(aux[i]);
        srd.push_back(aux[i + j]);
    }

    fin.close();
}

// rsd: 20 15 9 0 17 30 24 22 36 45
// srd: 0 9 15 17 20 22 24 30 36 45 
// pasul 1: luam 20 din rsd, impartim srd in 0,9,15,17 si 22,24,30,36,45
// pasul 2: luam 15 din rsd, impartim noul vector in 0,9 si 17
// pasul 3: luam 9 din rsd, impartim noul vector in 0
// reconstruim ramura stanga

Node *constructie_recursiva(const std::vector<int> &rsd, const std::vector<int> &srd, int start, int end, int &idx_preordine) {
    // conditie de iesire default
    if (start > end || idx_preordine >= rsd.size()) {
        return nullptr;
    }

    // root-ul e intotdeauna din preordine
    int   root_val  = rsd[idx_preordine++];
    Node *root_node = new Node(root_val);

    // daca am ajuns la finalul sectiunii, iesim
    if (start == end) {
        return root_node;
    }

    int in_idx;
    for (int i = start; i <= end; ++i) {
        if (srd[i] == root_val) {
            in_idx = i;
            break;
        }
    }

    // construim prin parcurgere recursiva
    root_node->left  = constructie_recursiva(rsd, srd, start, in_idx - 1, idx_preordine);
    root_node->right = constructie_recursiva(rsd, srd, in_idx + 1, end, idx_preordine);

    return root_node;
}

void constructie_arbore(const std::vector<int> &srd, const std::vector<int> &rsd) {
    BinTree_t *bintree = new BinTree_t;

    // la preordine, root-ul e la primul index; de aici plecam ca sa reconstruim
    int idx_preordine = 0;
    if (!rsd.empty() && !srd.empty()) {
        bintree->root = constructie_recursiva(rsd, srd, 0, srd.size() - 1, idx_preordine);
    }

    bintree->print_bfs();
}

int main(void) {
    std::vector<int> srd;
    std::vector<int> rsd;

    citire_din_fisier(srd, rsd);

    std::cout << "srd: ";
    for (const auto &el : srd) {
        std::cout << el << ' ';
    }
    std::cout << "\nrsd: ";
    for (const auto &el : rsd) {
        std::cout << el << ' ';
    }
    std::cout << '\n';

    constructie_arbore(srd, rsd);


    return 0;
}