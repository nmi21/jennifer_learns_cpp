#include <iostream>
#include <vector>

std::vector<bool> sieve_of_eratosthenes(int limit) {
    // Creates a vector that has true false for every value based on is it a prime?
    // Assume all numbers are prime
    // Then find a prime, add 
    
    std::vector<bool> sieve(limit + 1, true);
    
    // Handle the small numbers
    sieve[0] = false;
    sieve[1] = false;

    // Handle the even numbers > 2
    for (int i = 4; i < limit + 1; i += 2) {
        sieve[i] = false;
    }

    // Handle the odd numbers
    for (int i = 3; i < limit + 1; i += 2) {
        if (sieve[i]) {
            for (int j = 3*i; j < limit + 1; j += 2*i) {
                sieve[j] = false;
            }
        }
    }

    return sieve;
}

std::vector<int> primes_in_range(int left, int right, std::vector<bool> sieve) {

    if (right > sieve.size()) {
        throw std::runtime_error("Sieve not large enough!");
    }

    std::vector<int> primes;

    for (int i = left; i <= right; ++i) {
        if (sieve[i]) {
            primes.push_back(i);
        }
    }

    return primes;
}

int main() {

    // Define limit and create sieve
    int limit = 100;
    std::vector<bool> prime_sieve = sieve_of_eratosthenes(limit);

    // Grab the primes between left and right
    int left = 10;
    int right = 100;

    // Get the vector of primes
    std::vector<int> primes = primes_in_range(left, right, prime_sieve);

    std::cout << "There are " << primes.size() << " primes between " << left << " and " << right << "." << std::endl;
    if (primes.size() > 0) {
        std::cout << "They are as follows:" << std::endl;
        for (auto prime : primes) {
            std::cout << prime << std::endl;
        }
    }    

    return 0;
}