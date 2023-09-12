/*
C++ Program To Find LCM of Two Numbers

https://www.geeksforgeeks.org/cpp-program-for-program-to-find-lcm-of-two-numbers/
*/

#include <iostream>
#include <vector>
#include <cmath>

// //---------------------------------------------------------------------------------------------------------------------------------------
// /*
//  Method 1
 
//  use the formula from https://en.wikipedia.org/wiki/Least_common_multiple#Using_the_greatest_common_divisor
 
//  That is:
//     lcm(a, b) = |ab| / gcd(a, b)
// */

// // First define the GCD function
// int gcd(int a, int b) {
//     // Use the Euclidean method
//     // Described here: https://en.wikipedia.org/wiki/Greatest_common_divisor#Euclidean_algorithm
    
//     if (b == 0) {
//         return a;
//     }

//     return gcd(b, a % b);
// }

// int lcm(int a, int b) {
//     if (a == 0 && b == 0) {
//         // deal with the case where both a and b are 0 and the formula will error
//         return 0;
//     }

//     // otherwise use the formula described above
//     return a * b / gcd(a, b);
// }
// //---------------------------------------------------------------------------------------------------------------------------------------


//---------------------------------------------------------------------------------------------------------------------------------------
/*
Method 2:
- find the prime factorization of each number
- take the larger of the two exponents from each prime number in the factorization
- multiply out

*/
// // Create a sieve
// std::vector<bool> sieveOfEratosthenes(int size) {
//     // Return a vector of true/false where sieve[i] checks if i is prime
    
//     std::vector<bool> sieve(size + 1, true);
//     sieve[0] = sieve[1] = false;

//     for (int i = 2; i <= size; ++i) {
//         if (sieve[i]) {
//             for (int j = 2 * i; j <= size; j += i) {
//                 sieve[j] = false;
//             }
//         }
//     }

//     return sieve;
// }

// // Extract primes from the sieve
// std::vector<int> getPrimes(int limit) {
//     // Return all primes <= limit
    
//     std::vector<bool> sieve = sieveOfEratosthenes(limit);
    
//     std::vector<int> primes;
//     for (int i = 0; i < sieve.size(); ++i) {
//         if (sieve[i]) {
//             primes.push_back(i);
//         }
//     }

//     return primes;
// }

// // Prime factor an integer given a vector of available primes
// std::vector<int> primeFactor(int n, const std::vector<int> & prime_numbers) {
//     // intialize factors with 0s
//     std::vector<int> factors(prime_numbers.size(), 0);

//     for (int i = 0; i < prime_numbers.size(); ++i) {
//         while (n % prime_numbers[i] == 0) {
//             factors[i] += 1;
//             n /= prime_numbers[i];
//         }
//     }

//     return factors;
// }

// // Determine the LCM of a and b
// int lcm(int a, int b) {
//     // get the prime numbers up to the larger of a and b
//     std::vector<int> primes = getPrimes(std::max(a, b));

//     // factor each number a and b based on the list of primes
//     std::vector<int> factors_a = primeFactor(a, primes);
//     std::vector<int> factors_b = primeFactor(b, primes);

//     // determine the max of each of the factors and add to the vector
//     std::vector<int> factors_max(primes.size());
//     for (int i = 0; i < primes.size(); ++i) {
//         factors_max[i] = std::max(factors_a[i], factors_b[i]);
//     }

//     // multiply the value of the prime by the max factor exponent
//     int lcm = 1;
//     for (int i = 0; i < primes.size(); ++i) {
//         int prime = primes[i];
//         int exp = factors_max[i];
//         lcm *= std::pow(prime, exp);
//     }

//     return lcm;
// }
//---------------------------------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------------------------------------
// Method 3: A Simple Algorithm
int lcm(int a, int b) {
    // This method compares a summation of a and a summation of b
    // If the summation of a is < summation of b, then summation of a += a
    // If the summation of b is < summation of a, then summation of b += b
    // If the sums are equal, then we have found the LCM!
    
    int a_val = a;
    int b_val = b;
    while (a != b) {
        if (a < b) {
            a += a_val;
        } else {
            b += b_val;
        }
    }

    return a;
}
//---------------------------------------------------------------------------------------------------------------------------------------



int main() {

    // Set the values to take LCM of 
    int a = 15;
    int b = 20;

    // Calculate and print result
    std::cout << "LCM(" << a << ", " << b << ") == " 
        << lcm(a, b) << std::endl;

    std::cout << a << std::endl;

    return 0;
}