/*

Problem statement: Sieve of Eratosthenes
Given a number N, calculate the prime numbers up to N using Sieve of Eratosthenes.  

Example 1:

Input:
N = 10

Output:
2 3 5 7

Explanation:
Prime numbers less than equal to N 
are 2 3 5 and 7.

Time Complexity: O(NloglogN)
Auxiliary Space: O(N)

*/

void SieveOfEratosthenes(int n)
{
    // Create a boolean array "prime[0..n]" and initialize all entries it as true. A value in prime[i] will finally be false if i is Not a prime, else true.
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= n; p++)
    {
        // If prime[p] is not changed,then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p greater than or equal to the square of it numbers which are multiple of p and are less than p^2 are already been marked.
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
 
    // Print all prime numbers
    for (int p = 2; p <= n; p++)
        if (prime[p])
            cout << p << " ";
}
