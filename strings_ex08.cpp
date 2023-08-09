/*
Remove Leading Zeros From String in C++

https://www.geeksforgeeks.org/remove-leading-zeros-from-string-in-cpp/
*/

#include <iostream>

std::string removeLeadingZeros(std::string & str) {

    // find out how many leading characters are either strings or spaces
    int counter = 0;
    while (str[counter] == '0') {
        ++counter;
    }

    // remove the amount of characters counted
    str.erase(0, counter);

    return str;
}

int main() {

    // collect string from user to modify
    std::string str_in;
    std::cout << "Remove leading 0s and spaces!" << std::endl 
        << "Enter a number or set of words to remove:" << std::endl;
    std::cin >> str_in;

    // modify string and print result
    std::cout << "With zeros removed: " << std::endl
        << removeLeadingZeros(str_in) << std::endl;

    return 0;
}