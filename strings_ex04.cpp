/*
C++ Program to Replace a Character in a String

https://www.geeksforgeeks.org/cpp-program-to-replace-a-character-in-a-string/
*/

#include <iostream>

std::string replaceChar(std::string str, char ch1, char ch2) {
    // Replace all instances of 'ch1' in 's' with 'ch2'

    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == ch1) {
            str[i] = ch2;
        }
    }

    return str;
}

int main() {

    std::string s = "Jennifer is learning to code in C++!";
    
    std::cout << "The current string is as follows:" << std::endl
        << s << std::endl << std::endl;
    
    char c1;
    std::cout << "Enter a character to be replaced: ";
    std::cin >> c1;
    
    char c2;
    std::cout << "Enter the character you would like insert in its place: ";
    std::cin >> c2;

    std::cout << "\n\n";

    std::cout 
        << "Original string:" << std::endl
        << "\t" << s << std::endl
        << "Replaced string:" << std::endl
        << "\t" << replaceChar(s, c1, c2) << std::endl;

    return 0;
}