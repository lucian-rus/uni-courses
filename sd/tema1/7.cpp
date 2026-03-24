#include <fstream>
#include <iostream>
#include <queue>

typedef struct _Stack {
    std::queue<int> q1;
    std::queue<int> q2;

    int top(void) {
        return q1.front();
    }

    void pop(void) {
        if (q1.size() > 0) {
            q1.pop();
        }
    }

    void push(int item) {
        q2.push(item);
        while (q1.size() > 0) {
            q2.push(q1.front());
            q1.pop();
        }

        while (q2.size() > 0) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    bool isEmpty(void) {
        return (q1.size() == 0);
    }

    void clear(void) {
        while (q1.size() != 0) {
            q1.pop();
        }
    }
} Stack_t;

int main() {
    Stack_t stack;
    stack.push(5);
    stack.push(4);
    stack.push(3);
    stack.push(2);
    stack.push(1);

    // ordinea asteptata 1 2 3 4 5
    while (stack.isEmpty() == false) {
        std::cout << stack.top() << ' ';
        stack.pop();
    }

    std::cout << '\n';
    return 0;
}