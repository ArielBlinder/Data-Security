#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Function to check if a single number is prime (for small ranges)
bool isPrime(int num)
{
    if (num <= 1)
        return false;
    if (num <= 3)
        return true;
    if (num % 2 == 0 || num % 3 == 0)
        return false;

    for (int i = 5; i * i <= num; i += 6)
    {
        if (num % i == 0 || num % (i + 2) == 0)
        {
            return false;
        }
    }
    return true;
}

// Function to count primes using trial division (for small ranges)
int countPrimesSimple(int start, int end)
{
    int count = 0;
    for (int i = start; i <= end; i++)
    {
        if (isPrime(i))
        {
            count++;
        }
    }
    return count;
}

// Function to count primes using Sieve of Eratosthenes (for larger ranges)
int countPrimesSieve(int start, int end)
{
    if (end < 2)
        return 0;

    // Allocate memory for sieve
    bool *is_prime = (bool *)malloc((end + 1) * sizeof(bool));
    if (!is_prime)
    {
        printf("Memory allocation failed!\n");
        return -1;
    }

    // Initialize all numbers as prime
    memset(is_prime, true, (end + 1) * sizeof(bool));
    is_prime[0] = is_prime[1] = false;

    // Sieve of Eratosthenes
    for (int i = 2; i * i <= end; i++)
    {
        if (is_prime[i])
        {
            // Mark all multiples of i as non-prime
            for (int j = i * i; j <= end; j += i)
            {
                is_prime[j] = false;
            }
        }
    }

    // Count primes in the range
    int count = 0;
    for (int i = start; i <= end; i++)
    {
        if (is_prime[i])
        {
            count++;
        }
    }

    free(is_prime);
    return count;
}

// Function to count the number of primes in a range (chooses optimal method)
int countPrimesInRange(int start, int end)
{
    if (start > end)
    {
        int temp = start;
        start = end;
        end = temp;
    }

    // Use sieve for larger ranges, simple method for smaller ones
    int range_size = end - start + 1;
    if (range_size > 10000 || end > 100000)
    {
        return countPrimesSieve(start, end);
    }
    else
    {
        return countPrimesSimple(start, end);
    }
}

int main()
{
    int start, end;

    // Input the range with validation
    printf("Enter the range start first and the end, without ',' (start end): ");
    if (scanf("%d %d", &start, &end) != 2)
    {
        printf("Invalid input! Please enter two integers.\n");
        return 1;
    }

    if (start < 0 || end < 0)
    {
        printf("Please enter non-negative numbers.\n");
        return 1;
    }

    // Count and display the number of primes
    int primeCount = countPrimesInRange(start, end);
    if (primeCount >= 0)
    {
        printf("Number of prime numbers between %d and %d: %d\n",
               (start <= end) ? start : end,
               (start <= end) ? end : start,
               primeCount);
    }

    return 0;
}