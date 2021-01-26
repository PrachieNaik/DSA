/**
WAP to find the Missing Number in array.

Assuptions: Only positive numbers, Unsorted array


Method 1: The length of the array is n-1. So the sum of all n elements, i.e sum of numbers from 1 to n can be calculated using the formula n*(n+1)/2. Now find the sum of all the elements in the array and subtract it from the sum of first n natural numbers, it will be the value of the missing element. However, there can be overflow if n is large. In order to avoid integer overflow, pick one number from known numbers and subtract one number from given numbers. This way there won’t have Integer Overflow ever.

**/



#include <bits/stdc++.h>
using namespace std;
 
// a represents the array
// n : Number of elements in array a
int getMissingNo(int a[], int n) 
{ 
    int i, total=1; 
     
    for ( i = 2; i<= (n+1); i++)
    {
        total+=i;
        total -= a[i-2];
    }
    return total; 
} 
 
//Driver Program
int main() {
    int arr[] = {1, 2, 3, 5};
    cout<<getMissingNo(arr,sizeof(arr)/sizeof(arr[0]));
    return 0;
}


// time complexity: O(N), auxiliary space complexity O(1)



/**

Method 2: This method uses the technique of XOR to solve the problem.  
XOR has certain properties:
Assume a1 ^ a2 ^ a3 ^ …^ an = a and a1 ^ a2 ^ a3 ^ …^ an-1 = b
Then a ^ b = an
time complexity: O(N), auxiliary space complexity O(1)

**/
