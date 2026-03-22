#include <fstream>
#include <iostream>

typedef struct Node {
    int          key  = 0;
    struct Node *next = nullptr;
    struct Node *prev = nullptr;
} Node_t;

typedef struct {
    Node_t *head = nullptr;
    Node_t *tail = nullptr;

    void push_front(int key) {
        Node_t *node = new Node_t;
        node->key    = key;
        node->next   = head;
        node->prev   = nullptr;

        // daca head-ul exista, seteaza nodul curent ca fiind prev pentru head-ul anterior
        if (head != nullptr) {
            head->prev = node;
        }
        head = node;

        // daca nu exista tail, il facem
        if (tail == nullptr) {
            tail = node;
        }
    };

    void push_back(int key) {
        Node_t *node = new Node_t;
        node->key    = key;
        node->next   = nullptr;
        node->prev   = tail;

        if (tail != nullptr) {
            tail->next = node;
        }
        tail = node;

        if (head == nullptr) {
            head = node;
        }
    };

    void pop_front(void) {
        if (size() == 0) {
            std::cout << "lista este goala!\n";
            return;
        }

        Node_t *next = head->next;
        delete head;

        head = next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr;
        }
    };

    void pop_back(void) {
        if (size() == 0) {
            std::cout << "lista este goala!\n";
            return;
        }

        Node_t *prev = tail->prev;
        delete tail;

        tail = prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        }
        else {
            head = nullptr;
        }
    };

    Node_t *find(int key) {
        if (size() == 0) {
            std::cout << "lista este goala!\n";
            return nullptr;
        }

        Node_t *curr = head;
        while ((curr->next != nullptr) && (curr->key != key)) {
            curr = curr->next;
        }

        return curr;
    };

    void erase(Node_t node) {};

    void remove(int key) {
        if (size() == 0) {
            std::cout << "lista este goala!\n";
            return;
        }

        Node_t *curr = head;
        while (curr->next != nullptr) {
            if (curr->key == key) {
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                delete curr;
            }
            curr = curr->prev->next;
        }
    };

    void insert_after(int key1, int key2) {};
    void empty() {};
    void clear() {};

    void print() {
        if (size() == 0) {
            std::cout << "lista este goala!\n";
            return;
        }

        Node_t *curr = head;
        while (curr != nullptr) {
            std::cout << curr->key << ' ';
            curr = curr->next;
        }
        std::cout << '\n';
    };

    int size() {
        Node_t *curr = head;

        int size = 0;
        while (curr != nullptr) {
            size++;
            curr = curr->next;
        }

        return size;
    };
} LinkedList_t;

int main() {
    LinkedList_t ll;

    std::cout << "dimensiunea este: " << ll.size() << '\n';
    ll.print();

    ll.push_front(3);
    std::cout << "dimensiunea este: " << ll.size() << '\n';
    ll.print();

    ll.push_front(5);
    std::cout << "dimensiunea este: " << ll.size() << '\n';
    ll.print();

    ll.push_back(2);
    std::cout << "dimensiunea este: " << ll.size() << '\n';
    ll.print();

    ll.pop_front();
    std::cout << "dimensiunea este: " << ll.size() << '\n';
    ll.print();

    ll.pop_back();
    std::cout << "dimensiunea este: " << ll.size() << '\n';
    ll.print();

    ll.pop_back();
    std::cout << "dimensiunea este: " << ll.size() << '\n';
    ll.print();

    return 0;
}