#include <iostream>
#include <stack>
#include <vector>

void sortStack(std::stack<int>& stack) {
    // Temporary stack to hold elements in sorted order
    std::stack<int> tmpStack;

    while (!stack.empty()) {
        // 1. Pop the top element from the original stack
        int current = stack.top();
        stack.pop();

        // 2. While tmpStack is not empty and its top element is GREATER than current
        while (!tmpStack.empty() && tmpStack.top() > current) {
            // Move elements back to the original stack to clear the way
            stack.push(tmpStack.top());
            tmpStack.pop();
        }

        // 3. Push current into the correct spot in tmpStack
        tmpStack.push(current);
    }

    // Copy elements back so smallest is on top
    while (!tmpStack.empty()) {
        stack.push(tmpStack.top());
        tmpStack.pop();
    }
}

// Helper function to print a stack without destroying the original
void printStack(std::stack<int> s) {
    std::vector<int> elements;
    while (!s.empty()) {
        elements.push_back(s.top());
        s.pop();
    }
    std::cout << "[";
    for (int i = static_cast<int>(elements.size()) - 1; i >= 0; --i) {
        std::cout << elements[i] << (i > 0 ? ", " : "");
    }
    std::cout << "] (top is right)\n";
}

int main() {
    std::stack<int> myStack;
    for (int val : {34, 3, 31, 98, 92, 23}) {
        myStack.push(val);
    }

    std::cout << "Original Stack: ";
    printStack(myStack);

    sortStack(myStack);

    std::cout << "Sorted Stack:   ";
    printStack(myStack);

    return 0;
}