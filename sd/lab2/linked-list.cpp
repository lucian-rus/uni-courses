#include <iostream>

typedef struct Node {
    int          key  = 0;
    struct Node *next = nullptr;
    struct Node *prev = nullptr;
} Node_t;

typedef struct {
    Node_t *head = nullptr;
    Node_t *tail = nullptr;

    void push_front(int val) {
        Node_t *node = new Node_t;
        node->key    = val;
        node->next   = head;
        node->prev   = nullptr;

        if (head != nullptr) {
            head->prev = node;
        }
        head = node;

        if (tail == nullptr) {
            tail = node;
        }
    }

    void pop_back() {
        if (tail == nullptr) {
            return;
        }
        Node_t *aux = tail;

        tail       = tail->prev;
        tail->next = nullptr;

        delete aux;
    }

    void print() {
        Node_t *node = head;
        while (node != nullptr) {
            std::cout << node->key << ' ';
            node = node->next;
        }
        std::cout << '\n';
    }

    void find(int val) {
        Node_t *node = head;
        while (node != nullptr && val != node->key) {
            std::cout << node->key << ' ';
            node = node->next;
        }
        std::cout << '\n';
    }
} List_t;

int main(void) {
    List_t list;

    list.push_front(3);
    list.push_front(5);
    list.push_front(4);
    list.push_front(6);

    list.print();
    list.find(5);
    return 0;
}