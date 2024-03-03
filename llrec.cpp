#include "llrec.h"

// Helper function for recursion
void llpivotHelper(Node* current, Node*& smaller, Node*& larger, Node*& smallerTail, Node*& largerTail, int pivot) {
    if (current == nullptr) {
        // Base case: end of the list
        return;
    }

    Node* next = current->next;  // Save the next node
    current->next = nullptr;     // Disconnect the current node from the list

    if (current->val <= pivot) {
        if (smaller == nullptr) {
            smaller = current;
            smallerTail = current;
        } else {
            smallerTail->next = current;
            smallerTail = current;
        }
    } else {
        if (larger == nullptr) {
            larger = current;
            largerTail = current;
        } else {
            largerTail->next = current;
            largerTail = current;
        }
    }

    // Recursive call for the next node
    llpivotHelper(next, smaller, larger, smallerTail, largerTail, pivot);
}

void llpivot(Node*& head, Node*& smaller, Node*& larger, int pivot) {
    smaller = nullptr;
    larger = nullptr;
    Node* smallerTail = nullptr;
    Node* largerTail = nullptr;

    llpivotHelper(head, smaller, larger, smallerTail, largerTail, pivot);

    // Set the head to nullptr as the original list has been divided into smaller and larger lists
    head = nullptr;
}
