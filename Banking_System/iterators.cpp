#include <functional>
#include <iostream>

// This file only exists to demonstrate OOP Concepts for COP 3003 and does not affect the Banking System Program!

/**
Milestone 6 (LO7):
An aggregate is something that has or hold many things. In code, that could be an array or a vector.
An iterator can iterate through an aggregate(Lines 23-28).

In C++, functions can take other functions as parameters. Two functions are defined as "square_num" and "subtract".
subtract as passed as a parameter when the square_num function is called (Line 35).
*/



// Function Prototypes
int square_num(int num1, int num2, std::function<int(int,int)> func);
int subtract(int num1, int num2);

// Code is commented out because it conflicts with main application.

//int main() {

    // Integrator on an aggregate:

    // this array is an aggregate
//    std::string people[5] = {"John", "Jim", "Rose", "Sean", "Mark"};

   // this loop iterates through the array (iterator)
//    for(std::string person : people) {
//        std::cout << person << std::endl;
//    }

    // This function call will square the difference of 5 and 3, then it will return that value.
//    int total = square_num(5, 3, &subtract);
//    std::cout<< "The difference between 5 - 3 squared is: " << total;


    //return 0;
//}



int subtract(int num1, int num2){
    return num1- num2;
}

// This function takes a function as a parameter
int square_num(int num1, int num2, std::function<int(int,int)> func){
    int difference = func(num1, num2);
    return difference * difference;
    }






