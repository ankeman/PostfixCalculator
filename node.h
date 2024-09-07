#include <iostream>
using namespace std;

class node {
public:
    node();
    int the_data;
    node *next;
    void print();
    void reversePrint();
};

node::node() {
    next = NULL;
}

void node::print() {
    cout << the_data << " ";
    if (next != NULL) {
        next->print();
    }
}
