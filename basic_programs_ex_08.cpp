/*
Write a C++ Program to Multiply Two Floating-Point Numbers

https://www.geeksforgeeks.org/cpp-program-to-multiply-two-floating-point-numbers/

    Here, we will see how to multiply two floating-point numbers using the C++ program.

    Floating point numbers are numbers that include both integer part and fractional parts represented in the form of decimal and exponential values. float data type is used to store floating point values.

    For example

    Input  :  A =1.2, B = 3.0
    Output  :  3.6

*/

#include <iostream>

// Write a function that takes in 2x float numbers and returns the product
float mult_floats(float a, float b) {
    return a * b;
}

int main() {
    // Define the floats to be used
    float A = 1.2;
    float B = 3.0;

    // Calculate the product
    float product = mult_floats(A, B);

    // Print product to terminal
    std::cout << product << std::endl;

    return 0;
}