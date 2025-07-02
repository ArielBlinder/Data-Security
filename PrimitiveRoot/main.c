#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Function to calculate a^b mod p using modular exponentiation
long long mod_exp(long long a, long long b, long long p)
{
    long long result = 1;
    a = a % p;
    while (b > 0)
    {
        if (b & 1) // If b is odd
            result = (result * a) % p;
        b >>= 1; // b = b / 2
        a = (a * a) % p;
    }
    return result;
}

// Function to find gcd of two numbers
long long gcd(long long a, long long b)
{
    while (b != 0)
    {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to check if a number is prime
bool is_prime(long long n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (long long i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
        {
            return false;
        }
    }
    return true;
}

// Function to find prime factors of n efficiently
int find_prime_factors(long long n, long long factors[])
{
    int count = 0;

    // Check for factor 2
    if (n % 2 == 0)
    {
        factors[count++] = 2;
        while (n % 2 == 0)
        {
            n /= 2;
        }
    }

    // Check for odd factors
    for (long long i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
        {
            factors[count++] = i;
            while (n % i == 0)
            {
                n /= i;
            }
        }
    }

    // If n is a prime greater than 2
    if (n > 2)
    {
        factors[count++] = n;
    }

    return count;
}

// Function to check if a number is a primitive root of Zp
bool is_primitive_root(long long g, long long p)
{
    if (gcd(g, p) != 1)
        return false; // g must be coprime to p

    long long phi = p - 1;       // Euler's totient function for prime p
    long long prime_factors[64]; // Array to store prime factors
    int num_prime_factors;

    // Find prime factors of phi (p-1)
    num_prime_factors = find_prime_factors(phi, prime_factors);

    // Check if g^(phi/q) ≡ 1 (mod p) for any prime factor q of phi
    // If true for any q, then g is not a primitive root
    for (int i = 0; i < num_prime_factors; i++)
    {
        long long q = prime_factors[i];
        if (mod_exp(g, phi / q, p) == 1)
        {
            return false;
        }
    }
    return true;
}

// Function to find the first primitive root greater than X
long long find_primitive_root(long long p, long long X)
{
    if (!is_prime(p))
    {
        printf("Error: %lld is not a prime number!\n", p);
        return -1;
    }

    if (p == 2)
    {
        printf("Error: 2 has no primitive roots!\n");
        return -1;
    }

    for (long long g = X + 1; g < p; g++)
    {
        if (is_primitive_root(g, p))
        {
            return g;
        }
    }
    return -1; // No primitive root
}

int main()
{
    long long p, X;

    printf("Enter a prime number p: ");
    if (scanf("%lld", &p) != 1)
    {
        printf("Invalid input for p!\n");
        return 1;
    }

    printf("Enter a number X: ");
    if (scanf("%lld", &X) != 1)
    {
        printf("Invalid input for X!\n");
        return 1;
    }

    if (p <= 1 || X < 0)
    {
        printf("Invalid input: p must be > 1 and X must be >= 0\n");
        return 1;
    }

    if (X >= p)
    {
        printf("No primitive root exists greater than %lld in Z_%lld\n", X, p);
        return 0;
    }

    long long result = find_primitive_root(p, X);

    if (result != -1)
    {
        printf("The first primitive root of Z_%lld that is greater than %lld is: %lld\n", p, X, result);
    }
    else
    {
        printf("No primitive root found greater than %lld in Z_%lld\n", X, p);
    }

    return 0;
}
