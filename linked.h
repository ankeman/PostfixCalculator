#include <iostream>
#include <cmath> // For math functions like sin, abs
#include <string>
#include <bits/stdc++.h>
using namespace std;

class linkedlist {
private:
    node *head;
    node *tail;
public:
    linkedlist();
    void push(int);
    void print();
    int pop();
    int Postfix();
};

/**
 * Default constructor for linkedlist. Initializes head and tail to NULL.
 */
linkedlist::linkedlist() {
    head = NULL;
    tail = NULL;
}

void linkedlist::print() {
    if (head != NULL) {
        head->print();
    }
    cout << endl;
}

/**
 * Pushes an integer onto the stack.
 */
void linkedlist::push(int c) {
    node *temp = new node();
    temp->the_data = c;
    temp->next = head;
    head = temp;
    if (tail == NULL) {
        tail = head;
    }
}

/**
 * Pops an integer from the stack.
 */
int linkedlist::pop() {
    if (head == nullptr) {
        cout << "Error: Not enough operands." << endl;
        return -1;  // Return error indicator
    }

    int poppedData = head->the_data;
    node *temp = head;
    head = head->next;

    if (head == nullptr) {
        tail = nullptr;
    }

    delete temp;
    return poppedData;
}

/**
 * Evaluates the postfix expression with basic operations (+, -, *, /) 
 * and additional operations (abs, %, sin).
 */
int linkedlist::Postfix() {
    string input;

    while (true) {
        cin >> input;

        if (isdigit(input[0])) {
            // Convert string to int and push
            push(stoi(input));
        } 
        else if (input == "+" || input == "-" || input == "*" || input == "/") {
            // Ensure there are enough operands
            int b = pop();
            int a = pop();
            if (a == -1 || b == -1) {
                cout << "Error: Malformed expression. Not enough operands." << endl;
                return -1;
            }

            if (input == "+") push(a + b);
            else if (input == "-") push(a - b);
            else if (input == "*") push(a * b);
            else if (input == "/") {
                if (b == 0) {
                    cout << "Error: Division by zero." << endl;
                    return -1;
                }
                push(a / b);
            }
        }
        else if (input == "abs") {
            int a = pop();
            if (a == -1) return -1;
            push(abs(a));
        }
        else if (input == "%") {
            int b = pop();
            int a = pop();
            if (a == -1 || b == -1) {
                cout << "Error: Malformed expression. Not enough operands." << endl;
                return -1;
            }
            if (b == 0) {
                cout << "Error: Modulus by zero." << endl;
                return -1;
            }
            push(a % b);
        }
        else if (input == "sin") {
            int a = pop();
            if (a == -1) return -1;
            push(static_cast<int>(sin(a * M_PI / 180.0))); // Convert degrees to radians
        }
        else if (input == "=") {
            if (head != nullptr && head->next == nullptr) {
                return pop();
            } else {
                cout << "Error: Malformed expression." << endl;
                return -1;
            }
        }
        else {
            cout << "Error: Invalid input." << endl;
        }
    }
}
