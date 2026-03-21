#include <iostream>
#include <queue>
#include <random>
#include <stack>


void generate_data(std::queue<int> &queue, std::stack<int> &stack) {
    for (int i = 0; i < 10; i++) {
        int randnum = std::rand() % 100;
        std::cout << randnum << ' ';
        if(randnum % 2 == 0) {
            queue.push(randnum);
        } 
        else {
            stack.push(randnum);
        }
    }
    std::cout << '\n';
}

int main() {
    std::stack<int> stack;
    std::queue<int> queue;

    generate_data(queue, stack);

    std::cout << "stack:\n";
    while (stack.size() != 0) {
        std::cout << stack.top() << ' ';
        stack.pop();
    }
    std::cout << "\nqueue:\n";

    while (queue.size() != 0) {
        std::cout << queue.front() << ' ';
        queue.pop();
    }

    std::cout << '\n';

    return 0;
}