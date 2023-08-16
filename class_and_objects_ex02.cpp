/*
Encapsulation in C++

https://www.geeksforgeeks.org/encapsulation-in-cpp/
*/

#include <iostream>
#include <cmath>

class temp
{
    // default access is 'private' if you don't specify
    // I personally consider that to be bad practice because it isn't explicit
    private:  // so technically this line isn't required
        int a;
        int b;

    public:
        int solve(int input) {
            a = input;
            b = a / 2;

            return b;
        }
};

class Person
{
    private:
        std::string name;
        int age;

    public:
        // constructor
        Person(std::string name, int age) {
            // this-> means that we are referring to the member variable
            // helps disambiguate between member variables and input variables when named the same
            this->name = name; 
            this->age = age;
        }

        void setName(std::string name) {
            this->name = name;
        }

        void setAge(int age) {
            this-> age = age;
        }

        std::string getName() {
            return name;
        }

        int getAge() {
            return age;
        }
};

void printVars(Person pp) {
    std::cout << "Name: " << pp.getName() << std::endl;
    std::cout << "Age: " << pp.getAge() << std::endl;
}

class Encapsulation
{
    private:
        int x;

    public:
        void set(int a) {
            x = a;
        }

        int get() {
            return x;
        }
};

class Circle
{
    private:
        float area;
        float radius;

    public:
        void getRadius() {
            std::cout << "Enter radius:" << std::endl;
            std::cin >> radius;
        }

        void findArea() {
            area = 3.14 * radius * radius;
            std::cout << "Area of circle == " << area << std::endl;
        }
};

int main() {

    int n;
    std::cout << "Enter an integer: ";
    std::cin >> n;

    temp half;
    int ans = half.solve(n);
    std::cout << ans << std::endl;

    std::cout << std::endl;

// -------------------------------------------------------------------

    // objects of Person class
    // constructor as defined in class (requires two inputs)
    Person person("John Doe", 30); 

    // show variables by calling functions (see print function)
    printVars(person);

    // change variables
    person.setName("Jane Doe");
    person.setAge(32);

    // show changed variables
    printVars(person);

    std::cout << std::endl;


// -------------------------------------------------------------------

    Encapsulation obj;
    obj.set(5);
    std::cout << obj.get() << std::endl;

    std::cout << std::endl;

// -------------------------------------------------------------------

    Circle cir;
    cir.getRadius();
    cir.findArea();

    std::cout << std::endl;


// -------------------------------------------------------------------

    return 0;
}