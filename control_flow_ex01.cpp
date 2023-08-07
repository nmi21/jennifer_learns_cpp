/*

C++ Program To Check Whether Number is Even Or Odd

https://www.geeksforgeeks.org/cpp-program-to-check-whether-number-is-even-or-odd/

A number is even if it is completely divisible by 2 without leaving a remainder. 
A number is odd if it is not completely divisible by 2 and leaves the remainder 1. 
In this article, we will learn to write a C++ program to check whether a number is even or odd.

*/

#include <iostream>

// write a function that determines if a number is even or odd
int isEven(int n) {
    // if a number mod 2 is 0, then the number is even, else it is odd
    return (n % 2 == 0);
}

int main() {
    //input number to check
    int n = 101;

    // check if even or odd
    // print result
    if (isEven(n)) {
        std::cout << "Even" << std::endl;
    } else {
        // if not even then it is odd
        std::cout << "Odd" << std::endl;
    }

    return 0;
}