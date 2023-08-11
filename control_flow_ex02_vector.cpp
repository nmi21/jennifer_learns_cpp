#include <iostream>
#include <vector>
#include <set>

std::vector<int> getNumbers() {

    std::vector<int> numbers;

    std::cout << "Enter numbers ('q' to quit):" << std::endl;

    int a;
    while (std::cin >> a) {
        numbers.push_back(a);
    }

    return numbers;
}

int getMax(const std::vector<int> & vect) {

    // Method 1
    int max_val = vect[0];

    // figure out the max value
    for (int i = 0; i < vect.size(); ++i) {
        if (vect[i] > max_val) {
            max_val = vect[i];
        }
    }

    return max_val;
}

int main() {

    std::set<int> my_set;

    std::vector<int> num_vector = getNumbers();

    int max_num = getMax(num_vector);

    std::cout << max_num << std::endl;

    return 0;
}