#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is prime
bool is_prime(long long num)
{
    if (num <= 1)
        return false;
    if (num == 2)
        return true;
    if (num % 2 == 0)
        return false;
    if (num == 3)
        return true;
    if (num % 3 == 0)
        return false;

    // Check for factors of form 6k ± 1
    for (long long i = 5; i * i <= num; i += 6)
    {
        if (num % i == 0 || num % (i + 2) == 0)
        {
            return false;
        }
    }
    return true;
}

// Function to find the next prime number
long long next_prime(long long num)
{
    if (num < 2)
        return 2;

    // Start from the next number
    long long next = num + 1;

    // If next is even (and not 2), make it odd
    if (next > 2 && next % 2 == 0)
    {
        next++;
    }

    // Check odd numbers only (except for 2)
    while (!is_prime(next))
    {
        if (next == 2)
        {
            next = 3;
        }
        else
        {
            next += 2; // Skip even numbers
        }
    }
    return next;
}

int main()
{
    long long num;
    printf("Enter a number: ");

    if (scanf("%lld", &num) != 1)
    {
        printf("Invalid input! Please enter a valid number.\n");
        return 1;
    }

    if (num < 0)
    {
        printf("Please enter a non-negative number.\n");
        return 1;
    }

    long long result = next_prime(num);
    printf("The next prime number after %lld is %lld\n", num, result);

    return 0;
}
