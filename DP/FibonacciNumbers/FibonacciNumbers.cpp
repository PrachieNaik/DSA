/*

Problem statement: The Fibonacci numbers are the numbers in the following integer sequence.
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ……..

In mathematical terms, the sequence Fn of Fibonacci numbers is defined by the recurrence relation 

Fn = Fn-1 + Fn-2
with seed values 

F0 = 0 and F1 = 1.

Examples: 

Input  : n = 2
Output : 1

Input  : n = 9
Output : 34

Approach 1: Recursion

int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n-1) + fib(n-2);
}

Approach 2: Dynamic programming

*/

long long int nthFibonacci(long long int n){
    long long one = 0;
    long long two = 1;
    for(int i = 2; i <= n;i++) {
        long long three = (one + two) % 1000000007;
        one = two;
        two = three;
    }
    return two;
}
