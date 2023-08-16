/*
C++ program to create a file

https://www.geeksforgeeks.org/c-program-to-create-a-file/#
*/

#include <iostream>
#include <fstream>

void createFile(const std::string & file) {
    
    // create a file named 'file'
    std::ofstream out_stream {file};

    // verify it was created
    if (!out_stream) {
        throw std::runtime_error("Cannot open output file");
        return;
    }

    // show that it was created successfully
    std::cout << "File '" << file << "' successfully created" << std::endl;
}


int main() {

    std::string file_name = "my_test_file.txt";

    createFile(file_name);

    return 0;
}