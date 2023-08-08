/*
C++ Program For Fibonacci Numbers

https://www.geeksforgeeks.org/cpp-program-for-fibonacci-numbers/
*/

#include <iostream>
#include <system_error>

int fibonacciNumber(int n) {
    if (n < 0) {
        std::runtime_error("cannot have fibonacci < 0");
    }

    if (n == 0 || n == 1) {
        return n;
    }

    return fibonacciNumber(n - 1) + fibonacciNumber(n - 2);
}

int main() {

    // collect user input
    int num;
    std::cout << "Enter a number, n, to find the Fibonacci number F(n):" << std::endl;
    std::cin >> num;

    // determine result and print
    std::cout << "F(" << num << ") == " << fibonacciNumber(num) << std::endl;

    return 0;
}