#include <stdio.h>
#include <stdbool.h>

// GCD using iterative approach
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

// Iterative modular exponentiation (b^exp mod n)
long long power(long long base, long long exp, long long mod)
{
    long long result = 1;
    base = base % mod;
    while (exp > 0)
    {
        if (exp & 1)
        { // Use bitwise AND instead of modulo
            result = (result * base) % mod;
        }
        exp >>= 1;
        base = (base * base) % mod;
    }
    return result;
}

// Composite check without floating point sqrt
bool isComposite(long long n)
{
    if (n < 4)
        return false; // 0, 1, 2, 3 are not composite
    if (n % 2 == 0)
        return true; // Even numbers > 2 are composite
    if (n % 3 == 0)
        return true; // Divisible by 3

    // Check for factors of form 6k ± 1
    for (long long i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
        {
            return true; // n is composite
        }
    }
    return false; // n is prime
}

// Carmichael number check
bool checkCarmichael(long long n)
{
    if (!isComposite(n))
        return false; // Must be composite

    // Early exit for even numbers (Carmichael numbers are almost always odd)
    if (n % 2 == 0)
        return false;

    // Check Fermat's condition for selected bases
    long long check_limit = (n > 1000) ? 1000 : n;

    for (long long b = 2; b < check_limit; b++)
    {
        if (gcd(b, n) == 1)
        {
            if (power(b, n - 1, n) != 1)
            {
                return false; // Not a Carmichael number
            }
        }
    }

    // Additional sampling for large numbers
    if (n > 1000)
    {
        for (long long b = 1001; b < n && b <= 10000; b += 100)
        {
            if (gcd(b, n) == 1)
            {
                if (power(b, n - 1, n) != 1)
                {
                    return false;
                }
            }
        }
    }

    return true; // Likely Carmichael number
}

// Function to find the next Carmichael number
long long nextCarmichael(long long n)
{
    // Start from the next odd number if n is even
    long long start = (n % 2 == 0) ? n + 1 : n + 2;

    for (long long candidate = start;; candidate += 2)
    { // Check only odd numbers
        if (checkCarmichael(candidate))
        {
            return candidate;
        }

        // Safety check to prevent infinite loops with very large numbers
        if (candidate > n + 1000000)
        {
            printf("Search limit reached. No Carmichael number found in reasonable range.\n");
            return -1;
        }
    }
}

int main()
{
    long long n;
    printf("Enter the Number: ");
    if (scanf("%lld", &n) != 1)
    {
        printf("Invalid input!\n");
        return 1;
    }

    if (n < 0)
    {
        printf("Please enter a non-negative number.\n");
        return 1;
    }

    long long next = nextCarmichael(n);
    if (next != -1)
    {
        printf("The next Carmichael number after %lld is %lld.\n", n, next);
    }

    return 0;
}
