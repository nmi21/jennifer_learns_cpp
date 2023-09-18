/*
C++ Program For Fibonacci Numbers

https://www.geeksforgeeks.org/cpp-program-for-fibonacci-numbers/
*/

#include <iostream>
#include <system_error>

int fibonacciNumber(int n) {
    // Returns the nth Fibonacci number
    // 
    // The following is how the sequence starts:
    //  fibonacciNumber(0) == 0
    //  fibonacciNumber(1) == 1
    //  fibonacciNumber(2) == 1
    //  fibonacciNumber(3) == 2
    //  fibonacciNumber(4) == 3
    //  fibonacciNumber(5) == 5
    //  fibonacciNumber(6) == 8
    //  fibonacciNumber(7) == 13
    //  fibonacciNumber(8) == 21
    //  fibonacciNumber(9) == 34
    //  fibonacciNumber(10) == 55
    //  ...etc...

    // note that inputs must be > 0
    if (n < 0) {
        std::runtime_error("cannot have fibonacci < 0");
    }

    // handles the first handful of cases which are definitions of Fibonacci numbers
    // namely:
    //  F(1) = 1
    //  F(2) = 1
    if (n == 0 || n == 1) {
        return n;
    }

    return fibonacciNumber(n - 1) + fibonacciNumber(n - 2);
}

int main() {

    // print some of the first Fibonacci numbers
    for (int i = 0; i < 10 + 1; ++i) {
        std::cout << "fibonacciNumber(" << i << ") == " << fibonacciNumber(i) << std::endl;
    }

    // collect user input
    int num;
    std::cout << "Enter a number, n, to find the Fibonacci number F(n):" << std::endl;
    std::cin >> num;

    // determine result and print
    std::cout << "F(" << num << ") == " << fibonacciNumber(num) << std::endl;

    return 0;
}