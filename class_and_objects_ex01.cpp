/*
C++ Classes and Objects

https://www.geeksforgeeks.org/c-classes-and-objects/
*/

#include <iostream>

class Geeks
{
    // Access specificier: could be public or private or protected
    // public -- members are accessible from outside class
    // private -- members are not accessible from outside the class
    // protected -- members are not accessible from outside the class but can be accessed from inheritence (I haven't really seen these yet though)
    public:
        std::string geekname;
        int id;

        // can define functions inside of a class definition
        void printname() {
            std::cout << "Geekname is: " << geekname << std::endl;
        }

        // can also define functions outside of a class definition (you will have to define them!)
        void printid();

};

// defining functions outside of class is fine but need to use :: (like with std::) to show where it belongs
// otherwise, it writes like a standard function
// this should have the same permissions as if it were written inside the class definition
void Geeks::printid() {
    std::cout << "Geek id is: " << id << std::endl;
}

// classes can also be made using constructors
// this is probably the way you are used to thinking about creating objects
class GeeksForGeeks
{
    public:
        int id;
    
    GeeksForGeeks() {
        // having constructors allows you to implement any sort of logic within the {}
        std::cout << "Default constructor called!" << std::endl;
        id = -1;
    }

    GeeksForGeeks(int x) {
        std::cout << "Parameterized constructor called!" << std::endl;
        id = x;
    }
};

int main() {

    // Object declaration is the same with other variables: type and name
    Geeks obj1;
    // Geeks obj1("Nick", 13)  // will throw an error
    // accessing data -- can be assigned using assignment operator -- aka attributes
    obj1.geekname = "Nick";
    obj1.id = 13;
    // member functions (aka methods)
    obj1.printname();  // contained within class definition
    obj1.printid();  // outside of class definition
    

    // Using classes with constructors
    // this one will use default constructors
    GeeksForGeeks obj2;
    std::cout << "Geek id is: " << obj2.id << std::endl;

    GeeksForGeeks obj3(15);
    std::cout << "Geek id is: " << obj3.id << std::endl;

    return 0;
}