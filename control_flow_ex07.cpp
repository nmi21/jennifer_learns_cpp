/*
C++ Program To Find Factorial Of A Number

https://www.geeksforgeeks.org/cpp-program-to-find-factorial-of-a-number/

*/

#include <iostream>
#include <stdexcept>

unsigned long long factorial(int n) {
    /*
    For a 64bit unsigned integer, we can get values [0, 2^64 - 1]
    This means that we are limited to factorials n! when n <= 20 else we 
    would overflow
    */

    // Check to ensure we are below our value for the variable type
    if (n > 20) {
        throw std::runtime_error("Potential overflow error!");
    }

    // Check to ensure that the value being input is otherwise valid (positive or zero)
    if (n < 0) {
        throw std::runtime_error("Cannot compute n! when n < 0");
    }

    // Check to see if we are at 0
    if (n == 0) {
        // 0! = 1
        return 1;
    }

    return n * factorial(n - 1);
}

void printFactorial(int n) {
    std::cout << n << "! == " << factorial(n) << std::endl;
}

int main() {

    for (int i = 0; i <= 20; ++i) {
        printFactorial(i);
    }

    /*
    0! == 1
    1! == 1
    2! == 2
    3! == 6
    4! == 24
    5! == 120
    6! == 720
    7! == 5040
    8! == 40320
    9! == 362880
    10! == 3628800
    11! == 39916800
    12! == 479001600
    13! == 6227020800
    14! == 87178291200
    15! == 1307674368000
    16! == 20922789888000
    17! == 355687428096000
    18! == 6402373705728000
    19! == 121645100408832000
    20! == 2432902008176640000
    */

    return 0;
}