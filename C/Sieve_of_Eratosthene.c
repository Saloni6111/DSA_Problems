#include <stdio.h>
#include <stdbool.h>

void sieveOfEratosthenes(int n)
{
    bool prime[n + 1]; // Create a boolean array to mark prime numbers
    for (int i = 0; i <= n; i++)
    {
        prime[i] = true; // Initialize all entries as true
    }

    // marking non-prime numbers from 2 to n 
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        { // If prime[p] is still true, it's a prime number
            for (int i = p * p; i <= n; i += p)
            {
                prime[i] = false; // Mark all multiples of p as non-prime
            }
        }
    }

    // Print all prime numbers
    printf("Prime numbers up to %d are: ", n);
    for (int p = 2; p <= n; p++)
    {
        if (prime[p] == true)
        {
            printf("%d ", p);
        }
    }
    printf("\n");
}

int main()
{
    int n;
    printf("prime to the n: ");
    scanf("%d", &n);

    sieveOfEratosthenes(n);

    return 0;
}
