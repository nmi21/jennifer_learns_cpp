/*
C++ Program to Find Largest Among Three Numbers

https://www.geeksforgeeks.org/cpp-program-to-find-largest-among-three-numbers/


Example:
Input: a = 1, b = 2, c = 45
Output: The Largest Among 3 is 45
*/

#include <iostream>

int main() {
    /*
    Method:
        * With only three numbers, it doesn't make a ton of sense to write a bunch of code to find the max
        * use the built in function to determine the max
    */

    // take in 3 user-input numbers
    int a, b, c;
    std::cout << "Enter 3 integers (return to accept):" << std::endl;
    std::cin >> a >> b >> c;

    //TODO check which is the largest from those numbers
    int max_num = std::max(a, std::max(b, c));

    //TODO print the largest of the numbers
    std::cout << "The largest among the three numbers is " << max_num << std::endl;

    return 0;
}