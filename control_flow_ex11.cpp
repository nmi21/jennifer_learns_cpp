/*
C++ Program to Check Whether a Number is Palindrome or Not

https://www.geeksforgeeks.org/cpp-program-to-check-whether-a-number-is-palindrome-or-not/
*/

#include <iostream>

bool isPalindrome(int n) {  
    // this method should be robust to single digits and negative numbers

    //convert to string to make the slicing easier
    std::string str = std::to_string(n);
    int len = str.length();

    // go through and check opposite indices
    for (int i = 0; i < len; ++i) {
        if (str[i] != str[len - 1 - i]) {
            return false;
        }
    }

    // if you made it here, it is a palindrome
    return true;
}

int main() {

    // Collect user input
    int num;
    std::cout << "Enter a number to check if it is a palindrome:" << std::endl;
    std::cin >> num;

    // pass number into palindrome checker and print result
    if (isPalindrome(num)) {
        std::cout << "Yes! " << num << " is a palindrome!" << std::endl;
    } else {
        std::cout << "No! " << num << " is not a palindrome!" << std::endl;
    }

    return 0;
}