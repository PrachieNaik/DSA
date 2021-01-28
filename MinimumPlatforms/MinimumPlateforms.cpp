/*

Given arrival and departure times of all trains that reach a railway station, WAP to find the minimum number of platforms required for the railway station so that no train waits.We are given two arrays which represent arrival and departure times of trains that stop.


Assumptions: All the trains arrive on the same day and leave on the same day. Arrival and departure time can never be the same for a train but we can have arrival time of one train equal to departure time of the other. At any given instance of time, same platform can not be used for both departure of a train and arrival of another train. In such cases, we need different platforms,


Method 1:  The idea is to take every interval one by one and find the number of intervals that overlap with it. Keep track of the maximum number of intervals that overlap with an interval. Finally, return the maximum value. Time complexity : O(n*n) , Space complexity : O(1)
if ((arr[i] >= arr[j] && arr[i] <= dep[j]) ||  (arr[j] >= arr[i] && arr[j] <= dep[i])) then plat_needed++; 


Method 2: The idea is to consider all events in sorted order. Once the events are in sorted order, trace the number of trains at any time keeping track of trains that have arrived, but not departed. Time complexity : O(nlogn) , Space complexity : O(1)


Method 3: Multimap in c++ keeps the values always in sorted order in their keys, also it supports repeatative keys. Based on these properties, if we insert all the arrival and departure times in a multimap. The first value of element in multimap tells the arrival/departure time and second value tells whether it’s arrival or departure represented by ‘a’ or ‘d’ respectively. If its arrival then do increment by 1 otherwise decrease value by 1. Time complexity : O(nlogn) (Insert function for multimap takes this much time), Space Complexity : O(n)


Method 4: Using auxiliary array.Whenever an arrival occurs we increase the count of the required platform when a departure occurs we decrease the required platform at that point of time, after that, we take the cumulative sum, which would provide the required number of platform for all point of time, out of these values maximum value is our answer. Time complexity : O(n) , Space complexity : O(n)

*/

// C++ program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;

int minPlatform(int arrival[], int departure[], int n)
{

	// as time range from 0 to 2359 in 24 hour clock,
	// we declare an array for values from 0 to 2360
	int platform[2361] = {0};
	int requiredPlatform = 1;
	for (int i = 0; i < n; i++) {

		// increment the platforms for arrival
		++platform[arrival[i]]; 

		// once train departs we decrease the platform count
		--platform[departure[i] + 1];
	}

	// We are running loop till 2361 because maximum time value
	// in a day can be 23:60
	for (int i = 1; i < 2361; i++) {

		// taking cumulative sum of platform give us required
		// number of platform fro every minute
		platform[i] = platform[i] + platform[i - 1]; 
		requiredPlatform = max(requiredPlatform, platform[i]);
	}
	return requiredPlatform;
}

// Driver code
int main()
{
	int arr[] = { 900, 940, 950, 1100, 1500, 1800 };
	int dep[] = { 910, 1200, 1120, 1130, 1900, 2000 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Minimum Number of Platforms Required = "
		<< minPlatform(arr, dep, n);
	return 0;
}
