/*
C++ Program to check if two Arrays are Equal or not

https://www.geeksforgeeks.org/c-program-to-check-if-two-arrays-are-equal-or-not/

Given two arrays arr1[] and arr2[] of length N and M respectively, the task is to check if the two arrays are equal or not. 
*/

/*
A note on arrays in C++:
- arrays are mutuable (meaning you can change elements)
- however, you cannot change the size
- if you try to access an element that doesn't exist (e.g. the 10th element in an 8 element array), it won't stop you
- memory management is manual
*/

#include <algorithm>
#include <iostream>

bool arraysEqual(int arr1[], int size1, int arr2[], int size2) {

    // first determine if they are the same size
    if (size1 != size2) {
        return false;
    }

    // sort the arrays so that the elements can be compared 1 by 1
    // having calculated the size does help us here however,
    // sort requires two inputs:
    // 1. the first memory location
    // 2. the last memory location
    std::sort(arr1, arr1 + size1);
    std::sort(arr2, arr2 + size2);

    // now that they are sorted, we can go through element by element and compare
    for (int i = 0; i < size1; ++i) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    } 
    
    return true;
}

bool arraysEqualHash(int arr1[], int size1, int arr2[], int size2) {
    // if you are using arrays, you are probably worried about efficiency,
    // so it is probably more useful to use hash maps
    
    // first determine if they are the same size
    if (size1 != size2) {
        return false;
    }

    // Create a hash map to measure the number of times that each element appears in the array
    std::unordered_map<int, int> frequency_map;
    for (int i = 0; i < size1; ++i) {
        // Add each instance of an element to the correct index of the hash map
        frequency_map[arr1[i]]++;  // could also do "+= 1" if that is more logical to you
    }

    // Now go through arr2[] and find if each element is in the map for arr1[]
    for (int i = 0; i < size1; ++i) {
        // first check to see if the element in arr2[] is in the map
        if (frequency_map.find(arr2[i]) == frequency_map.end()) {
            return false;
        }

        // now we need to check to see if the elements have the same frequency
        // if an element appears in arr1[] but has zero instances remaining, 
        // then it is in arr2 more times than it is in arr1[],
        // thus the arrays are not equal
        if (frequency_map[arr2[i]] == 0) {
            return false;
        }

        // need to remove 1 instance of arr2[i] from the map's frequency counter
        frequency_map[arr2[i]]--;  // could also do "-= 1" if that is more logical to you
    }

    return true;
}

void printArray(int arr[], std::string name, int size) {
    std::cout << name << ": [ ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i];
        if (i < size - 1) {
            std::cout << ", ";
        }
    }
    std::cout << " ]" << std::endl;
}
 

int main() {

    // Define some arrays
    int array1[] = { 1, 2, 3, 4, 5 };
    int array2[] = { 5, 4, 3, 2, 1 };
    int array3[] = { 1, 2, 3, 4, 4 };
    int array4[] = { 4, 4, 3, 2, 1 };

    // note that you cannot measure the number of elements in an array
    // but since we know the data type, we can divide by the data types to see number of elements
    // this isn't strictly necessary: 
    //  we know the data types are the same and therefore could count the number of bytes directly
    // note that "sizeof()" counts bytes, not elements
    // so if you were to have an array of chars, it would be as many bytes as chars
    // could also measure against e.g. sizeof(array1[0])
    int size1 = sizeof(array1) / sizeof(int);
    int size2 = sizeof(array2) / sizeof(int);
    int size3 = sizeof(array3) / sizeof(int);
    int size4 = sizeof(array4) / sizeof(int);

    printArray(array1, "array1", size1);
    printArray(array2, "array2", size2);
    printArray(array3, "array3", size3);
    printArray(array4, "array4", size4);


// Compare using standard methods -----------------------------------------------------------------------

    std::cout << std::endl << "Comparing using linear methods..." << std::endl;

    // Compare 1 to all other arrays
    std::cout << "1 and 2: " << arraysEqual(array1, size1, array2, size2) << std::endl;
    std::cout << "1 and 3: " << arraysEqual(array1, size1, array3, size3) << std::endl;
    std::cout << "1 and 4: " << arraysEqual(array1, size1, array4, size4) << std::endl;

    // Compare 2 to all other arrays
    std::cout << "2 and 3: " << arraysEqual(array2, size2, array3, size4) << std::endl;
    std::cout << "2 and 4: " << arraysEqual(array2, size2, array4, size4) << std::endl;

    // Compare 3 to all other arrays
    std::cout << "3 and 4: " << arraysEqual(array3, size3, array4, size4) << std::endl;


// Using hash maps ----------------------------------------------------------------------------------------

    std::cout << std::endl << "Using hash maps..." << std::endl;

    // Compare 1 to all other arrays
    std::cout << "1 and 2: " << arraysEqualHash(array1, size1, array2, size2) << std::endl;
    std::cout << "1 and 3: " << arraysEqualHash(array1, size1, array3, size3) << std::endl;
    std::cout << "1 and 4: " << arraysEqualHash(array1, size1, array4, size4) << std::endl;

    // Compare 2 to all other arrays
    std::cout << "2 and 3: " << arraysEqualHash(array2, size2, array3, size4) << std::endl;
    std::cout << "2 and 4: " << arraysEqualHash(array2, size2, array4, size4) << std::endl;

    // Compare 3 to all other arrays
    std::cout << "3 and 4: " << arraysEqualHash(array3, size3, array4, size4) << std::endl;

// --------------------------------------------------------------------------------------------------------

    return 0;
}