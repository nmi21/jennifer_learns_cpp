/*
C++ Program To Find If A Character Is Vowel Or Consonant

https://www.geeksforgeeks.org/cpp-program-to-find-if-a-character-is-vowel-or-consonant/

Given a character, check if it is a vowel or consonant. Vowels are ‘a’, ‘e’, ‘i’, ‘o’, and ‘u’. All other characters (‘b’, ‘c’, ‘d’, ‘f’ ….) are consonants.
*/

#include <iostream>

bool isVowel(char ch_in) {
    // Return true if is a vowel, false if not

    // first convert input char to lower and then you have to check fewer things
    char ch_lower = tolower(ch_in);

    // check to see if it is a vowel
    switch(ch_lower) {
        case 'a': 
        case 'e': 
        case 'i': 
        case 'o': 
        case 'u':

        return true;
    }

    // check to make sure it is a letter
    if ((int(ch_in) < int('A')) || (int(ch_in) > int('z'))) {
        throw std::runtime_error("Character entered was not a letter");
    }
    
    // else return false as it is a consonant
    return false;
}

int main() {

    // allow user input of a character
    char ch;
    std::cout << "Enter a letter to check if vowel of consonant:" << std::endl;
    std::cin >> ch;

    // check entry and print result
    if (isVowel(ch)) {
        std::cout << ch << " is a vowel!" << std::endl;
    } else {
        std::cout << ch << " is a consonant!" << std::endl;
    }

    return 0;
}