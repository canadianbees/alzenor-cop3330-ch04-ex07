#include <iostream>
#include "std_lib_facilities.h"

using namespace std;
int g_ERROR = -1223334444;
vector<string> numList;


//does the calculation
void calculator(int x, int y, const string &operation) {

    //addition
    if (operation == "+") {
        cout << "The sum of " << x << " and " << y << " is " << x + y;

        //subtraction
    } else if (operation == "-") {
        cout << "The difference of " << x << " and " << y << " is " << x - y;

        //multiplication
    } else if (operation == "*") {
        cout << "The product of " << x << " and " << y << " is " << x * y;

        //division
    } else if (operation == "/") {
        if (y == 0) {
            cout << "Can not divide by zero";
        } else {
            cout << "The quotient of " << x << " and " << y << " is " << x / y;
        }

        //anything else is invalid
    } else {
        cout << "Not a valid operation";
    }
}

void initList() {
    numList.push_back("zero");
    numList.push_back("one");
    numList.push_back("two");
    numList.push_back("three");
    numList.push_back("four");
    numList.push_back("five");
    numList.push_back("six");
    numList.push_back("seven");
    numList.push_back("eight");
    numList.push_back("nine");
}

int getNumber() {
    int x = g_ERROR;
    string num;

    //if user inputted an integer
    if (cin >> x) {
        return x;
    }
    //clear the input
    cin.clear();
    //have user input a string
    cin >> num;

    //look for number
    for (int i = 0; i < numList.size(); i++) {
        if (numList[i] == num) {
            return i;
        }
    }

    //if number couldn't be found return the global error
    return x;
}

//function to get the operation
string getOp() {
    string op;


    //if user inputs a valid operation
    cin >> op;
    if (op == "+" || op == "-" || op == "*" || op == "/") {
        return op;
    }

    return "Not a valid operation";
}


int main() {

    //initializes the list of numbers
    initList();

    cout << "Enter equation in number number operation format\n";
    int x = getNumber();
    int y = getNumber();
    string op = getOp();

    if (x == g_ERROR || y == g_ERROR) {
        cout << "Invalid numbers";
    } else {
        calculator(x, y, op);

    }
    return 0;
}