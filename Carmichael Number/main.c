#include <stdio.h>
#include <stdbool.h>

// Function to calculate the GCD of two numbers
int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate (base^exp) % mod using modular exponentiation
long long modPow(long long base, long long exp, long long mod)
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

// Function to check if a number is composite
bool isComposite(int num)
{
    if (num <= 1)
        return false;
    if (num <= 3)
        return false; // 2 and 3 are prime
    if (num % 2 == 0 || num % 3 == 0)
        return true; // Even or divisible by 3

    // Check for factors of form 6k ± 1
    for (int i = 5; i * i <= num; i += 6)
    {
        if (num % i == 0 || num % (i + 2) == 0)
        {
            return true; // Composite
        }
    }
    return false; // Prime
}

    // Function to check if a number is a Carmichael number
bool isCarmichael(int num)
{
    if (!isComposite(num))
    {
        return false; // Carmichael numbers are composite
    }

    // Early exit for even numbers (except for very specific cases)
    if (num % 2 == 0)
    {
        return false; // Almost all Carmichael numbers are odd
    }

    // Check Fermat's condition for bases co-prime to num
    for (int a = 2; a < num && a <= 100; a++)
    { // Limit checking for efficiency
        if (gcd(a, num) == 1)
        {
            if (modPow(a, num - 1, num) != 1)
            {
                return false; // Not a Carmichael number
            }
        }
    }

    // Additional verification with more bases for numbers that passed initial test
    if (num > 100)
    {
        for (int a = 101; a < num && a <= 1000; a += 10)
        { // Sample every 10th number
            if (gcd(a, num) == 1)
            {
                if (modPow(a, num - 1, num) != 1)
                {
                    return false;
                }
            }
        }
    }

    return true; // Likely Carmichael number
}

int main()
{
    int num;

    // Input number to check
    printf("Enter a number: ");
    if (scanf("%d", &num) != 1)
    {
        printf("Invalid input!\n");
        return 1;
    }

    // Check if it's a Carmichael number
    if (isCarmichael(num))
    {
        printf("%d is a Carmichael number.\n", num);
    }
    else
    {
        printf("%d is not a Carmichael number.\n", num);
    }

    return 0;
}