/*
C++ Program to Append a String in an Existing File

https://www.geeksforgeeks.org/cpp-program-to-append-a-string-in-an-existing-file/
*/

#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>

void writeToFile(std::string file_name, std::string data) {
    // will add data to file_name

    // having all of your writing in a function will avoid memory leaks
    // as soon as an ofstream is out of scope, it will close the file
    
    // output vs input filestreams allow you to write and read respectively
    // the second input means that it will enter append to the file rather than write over it
    std::ofstream ofs {file_name, std::ios::app};

    // check to make sure it was opened properly, error if not
    if (!ofs) {
        throw std::runtime_error("Could not open file");
    }

    ofs << data << std::endl;
}

int main() {

    std::string file = "file_handling_ex10_test.txt";

    for (int i = 0; i < 10; ++i) {
        std::string text = std::to_string(i) + ". I added a line!";
        writeToFile(file, text);
    }

    return 0;
}