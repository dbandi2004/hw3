#include "heap.h"
#include <iostream>
#include <string>

int main() {
    // Min-heap of integers
    Heap<int> minHeap;
    minHeap.push(3);
    minHeap.push(1);
    minHeap.push(4);
    minHeap.push(2);

    std::cout << "Min-heap of integers:" << std::endl;
    while (!minHeap.empty()) {
        std::cout << minHeap.top() << " ";
        minHeap.pop();
    }
    std::cout << std::endl;

    // Max-heap of integers
    Heap<int, std::greater<int>> maxHeap;
    maxHeap.push(3);
    maxHeap.push(1);
    maxHeap.push(4);
    maxHeap.push(2);

    std::cout << "Max-heap of integers:" << std::endl;
    while (!maxHeap.empty()) {
        std::cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    std::cout << std::endl;

    // Min-heap of strings
    Heap<std::string> stringHeap;
    stringHeap.push("banana");
    stringHeap.push("apple");
    stringHeap.push("cherry");
    stringHeap.push("date");

    std::cout << "Min-heap of strings:" << std::endl;
    while (!stringHeap.empty()) {
        std::cout << stringHeap.top() << " ";
        stringHeap.pop();
    }
    std::cout << std::endl;

    return 0;
}
