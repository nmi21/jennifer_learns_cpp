/*
C++ Program to Read Content From One File and Write it Into Another File

https://www.geeksforgeeks.org/cpp-program-to-read-content-from-one-file-and-write-it-into-another-file/
*/

#include <iostream>
#include <fstream>
#include <vector>

std::vector<std::string> readFromFile(const std::string & file_name) {
    
    // open an input file stream and check to make sure it is valid
    std::ifstream ifs {file_name};
    if (!ifs) {
        throw std::runtime_error("Unable to open file.");
    }

    // create a vector we will store the content in
    std::vector<std::string> lines;
    
    // create a string that we will continually use to extract a single line from the file
    std::string line_from_file;

    // grab the line from the file and add to our vector
    while (getline(ifs, line_from_file)) {
        // add lines from file_name to lines
        lines.push_back(line_from_file);
    }

    // publish a message saying we are done
    std::cout << "Data extraction from '" << file_name << "' successful." << std::endl;
    
    // return the vector
    return lines;
}

void writeToFile(const std::string & file_name, const std::vector<std::string> & str_vector) {

    // open an output file stream and check to make sure it is valid
    std::ofstream ofs {file_name};
    if (!ofs) {
        throw std::runtime_error("Could not open output file.");
    }

    // write lines from str_vector to new file
    for (auto line : str_vector) {
        ofs << line << std::endl;
    }

    // send a success message
    std::cout << "Data successfully written to '" << file_name << "'" << std::endl;
}

int main() {

    std::string read_file = "file_handling_ex11_read.txt";
    std::string write_file = "file_handling_ex11_write.txt";

    std::vector<std::string> lines_from_file = readFromFile(read_file);
    writeToFile(write_file, lines_from_file);

    return 0;
}