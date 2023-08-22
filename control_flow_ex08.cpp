/*
C++ Program to Reverse Digits of a Number

https://www.geeksforgeeks.org/cpp-program-to-reverse-digits-of-a-number/

*/

#include <iostream>
#include <algorithm>

int reverseNumber(int num) {
    // Method:
    // - cast to string
    // - reverse the string
    // - cast to integer
    // - return integer

    std::string num_str = std::to_string(num);
    std::reverse(num_str.begin(), num_str.end());

    return std::stoi(num_str);
}

int reverseNumberJennifer(const int & num) {

    int num_copy = num;
    int rev_num = 0;

    while (num_copy > 0) {
        rev_num *= 10;
        rev_num += num_copy % 10;
        num_copy /= 10;
    }

    return rev_num;
}

int main() {

    int n;
    std::cout << "Please enter a number to be reversed:" << std::endl;
    std::cin >> n;

    std::cout << n << " reversed: " << reverseNumber(n) << std::endl;
    std::cout << n << " reversed (Jennifer method): " << reverseNumberJennifer(n) << std::endl;

    return 0;
}
