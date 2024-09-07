/*
Program by Manish Dawadi 
Please enter two  positive digits and operator in postfix order.
It will not take more than two digits before operator.
It won't perform any operation if there is only one input in the stack.
Work has been done for an extra credit.

*/




#include <iostream>
#include <string>
#include "node.h"
#include "linked.h"

using namespace std;

/**
 * Main program for the postfix calculator.
 * 
 * Outputs a welcome message and instructions, then calls Postfix() to start the
 * postfix evaluation loop. If the result of the evaluation is valid, it is
 * printed to the user.
 */
int main() {
    linkedlist l1;

    
    cout << "Welcome to the postfix calculator." << endl;
    cout << "Enter values and operators in postfix order." << endl;
    cout << "Available operators: +, -, *, /, abs, %, sin." << endl;
    cout << "Enter '=' to get the result." << endl;

    
    int result = l1.Postfix();

    
    if (result != -1) {
        cout << "The result is: " << result << endl;
    }

    return 0;
}
