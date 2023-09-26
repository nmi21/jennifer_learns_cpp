/*
C/C++ Program to find Prime Numbers between given range

https://www.geeksforgeeks.org/c-cpp-program-to-find-prime-numbers-between-given-range/
*/

/*
Method
    - ask the user for an starting point (inclusive)
    - ask the user for an end point (inclusive)
    - iterate between the start and end point, check to see if number is prime
    - if number is prime, add to a vector
*/

#include <iostream>
#include <vector>

// function that checks if a number is prime
// there are a lot of different ways to do this type of thing
// each method has it's own pros/cons
// I don't think that having a super efficient prime solver is the point of this exercise, though
bool isPrime(int n) {

    // deal with numbers < 2
    if (n < 2) {
        return false;
    }

    // deal with even numbers
    if (n == 2) {
        return true;
    }
    if (n % 2 == 0) {
        return false;
    }

    // deal with remaining numbers
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }

    // otherwise the number is prime
    return true;
}

// function that will check if every number between the start and end points and see if it is prime
std::vector<int> primesInRange(int start, int end) {
    
    // create the vector we will store primes into
    std::vector<int> prime_list;

    // check all of the numbers between start and end, add primes to the vector
    for (int i = start; i <= end; ++i) {
        if (isPrime(i)) {
            prime_list.push_back(i);
        }
    }

    return prime_list;
}

int main() {

    std::cout << "Check to see what numbers are prime in a range!" << std::endl;
    
    int first;
    std::cout << "Enter the first number in the range: ";
    std::cin >> first;

    int last;
    std::cout << "Enter a the last number in the range: ";
    std::cin >> last;

    std::cout << std::endl;

    std::vector<int> primes = primesInRange(first, last);

    std::cout << "There are " << primes.size() << " primes between " << first << " and " << last << "." << std::endl;
    if (primes.size() > 0) {
        std::cout << "They are as follows:" << std::endl;
        for (auto prime : primes) {
            std::cout << prime << std::endl;
        }
    }

    return 0;
}