/*
rename function in C/C++

https://www.geeksforgeeks.org/rename-function-in-ccpp/
*/

#include <stdio.h>
#include <iostream>
#include <filesystem>

void renameFile(std::string old_name, std::string new_name) {
    // there is a native function for renaming files within stdio.h
    // but how it would handle certain situations might differ system to system
    // thus, we can add our own checks to make sure it would work as expected
    
    if (!std::filesystem::exists(old_name)) {
        std::cout << "File '" << old_name << "' does not exist. Thus cannot rename." << std::endl;
        
        // if the new file doesn't exist, exist the function
        return;
    }

    if (std::filesystem::exists(new_name)) {
        std::cout << "File '" << new_name << "' already exists. Cannot rename file." << std::endl;

        // if there is a new file, exit this function
        return;
    }

    // rename has a nonzero return if false, and so we can use it as a conditional
    // need to convert the std::string to array of chars, which can be done with .c_str()
    if (std::rename(old_name.c_str(), new_name.c_str())) {
        std::perror("Error renaming.");
    } else {
        std::cout << "Successfully renamed '" << old_name << "' to '" << new_name << "." << std::endl;
    }
}

int main() {

    std::string old_file = "file_handling_ex04_old_file_name.txt";
    std::string new_file = "file_handling_ex04_new_file_name.txt";

    renameFile(old_file, new_file);    

    return 0;
}