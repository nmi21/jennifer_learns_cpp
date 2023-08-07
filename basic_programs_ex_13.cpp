/*
C++ Program To Find Area And Perimeter Of Rectangle

https://www.geeksforgeeks.org/cpp-program-to-find-area-and-perimeter-of-rectangle/

A rectangle is a flat figure in a plane. It has four sides and four equal angles of 90 degrees each. 
In a rectangle all four sides are not of equal length like squares, sides opposite to each other have equal length. 
Both diagonals of the rectangle have equal lengths.


Examples:  

Input: 4 5
Output: Area = 20
        Perimeter = 18

Input: 2 3
Output: Area = 6
        Perimeter = 10
*/

#include <iostream>

// Write a function that calculates the area
int rectangleArea(int a, int b) {
    return a * b;
}

// Write a function that calculates the perimeter
int rectanglePerimeter(int a, int b) {
    return 2 * (a + b);
}

int main() {
    //set the leg lengths for the rectangle
    int a = 4;
    int b = 5;
    
    // calculate the area
    int area = rectangleArea(a, b);

    // calculate the perimeter
    int perimeter = rectanglePerimeter(a, b);

    // print out area and perimeter
    std::cout << "Area == " << area << std::endl;
    std::cout << "Perimeter == " << perimeter << std::endl;

    return 0;
}