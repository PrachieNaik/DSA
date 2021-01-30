/*

Write a function to check whether two given strings are anagram of each other or not. An anagram of a string is another string that contains the same characters, only the order of characters can be different. 



Method 1 (Use Sorting) : Sort both strings, Compare the sorted strings
Time Complexity: O(nLogn), Space Complexity: O(1)



Method 2 (count characters using one array) : In this method, it is assumed that the characters are stored using 8 bit and there can be 256 possible characters. Create count array of size 256. Initialize all values in count array as 0. Increment the value in count array for characters in str1 and decrement for characters in str2. Finally, if all count values are 0, then the two strings are anagram of each other. 
Time Complexity: O(n), Space Complexity: O(1) [auxiliary array of 256 characters]



Method 3 (Taking sum) : Initialize a variable say count to 0. Take the sum of all the characters of the first String and then decreasing the value of all the characters from the second String. If the Count value finally is 0 then its an anagram, else it is not.
Time Complexity: O(N), Space Complexity: O(1)

*/

// C++ program to check if two strings
// are anagrams of each other
#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string c, string d)
{
	if (c.size() != d.size())
		return false;
	int count = 0;

	// Take sum of all characters of first String
	for (int i = 0; i < c.size(); i++) {
		count += c[i];
	}

	// Subtract the Value of all the characters of second
	// String
	for (int i = 0; i < d.size(); i++) {
		count -= d[i];
	}

	// If Count = 0 then they are anagram
	// If count > 0 or count < 0 then they are not anagram
	return (count == 0);
}

// Driver code
int main()
{
	char str1[] = "geeksforgeeks";
	char str2[] = "forgeeksgeeks";

	// Function call
	if (isAnagram(str1, str2))
		cout << "The two strings are anagram of each other";
	else
		cout << "The two strings are not anagram of each "
				"other";

	return 0;
}
