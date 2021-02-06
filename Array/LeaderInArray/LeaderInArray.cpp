/*

Given an array A of positive integers. WAP to find the leaders in the array. An element of array is leader if it is greater than or equal to all the elements to its right side. The rightmost element is always a leader. 

Assumption: If there are two equal numbers, they both can be leader
Edge case: Last number will always be leader

*/


#include <iostream> 
using namespace std; 

/* C++ Function to print leaders in an array */
void printLeaders(int arr[], int size) 
{ 
	int max_from_right = arr[size-1]; 

	/* Rightmost element is always leader */
	cout << max_from_right << " "; 
	
	for (int i = size-2; i >= 0; i--) 
	{ 
		if (max_from_right <= arr[i]) 
		{		 
			max_from_right = arr[i]; 
			cout << max_from_right << " "; 
		} 
	}	 
} 

/* Driver program to test above function*/
int main() 
{ 
	int arr[] = {16, 17, 4, 3, 5, 2}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	printLeaders(arr, n); 
	return 0; 
}

//Time complexity: O(n), Space complexity: O(1)
