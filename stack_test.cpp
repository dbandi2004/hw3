#include "stack.h"
#include <iostream>
#include <string>

int main() {
    Stack<int> intStack;
    Stack<std::string> stringStack;

    std::cout << "Testing integer stack:" << std::endl;
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);

    std::cout << "Top element: " << intStack.top() << std::endl;

    while (!intStack.empty()) {
        std::cout << "Popping: " << intStack.top() << std::endl;
        intStack.pop();
    }

    std::cout << "\nTesting string stack:" << std::endl;
    stringStack.push("Hello");
    stringStack.push("World");
    stringStack.push("!");

    std::cout << "Top element: " << stringStack.top() << std::endl;

    while (!stringStack.empty()) {
        std::cout << "Popping: " << stringStack.top() << std::endl;
        stringStack.pop();
    }

    std::cout << "\nTesting underflow error:" << std::endl;
    try {
        intStack.pop();
    } catch (const std::underflow_error& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
