/*

Check if a string can be obtained by rotating another string d places

Method 1: Reversal algorithm
Reverse A to get ArB, where Ar is reverse of A.
Reverse B to get ArBr, where Br is reverse of B.
Reverse all to get (ArBr) r = BA.

Assumption: String length > No of rotating places

Time Complexity : O(n), Space Complexity : O(1)

*/

#include <string>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

string rotate(string s,int d)
{
    reverse(s.begin(), s.begin() + d);
    reverse(s.begin() + d, s.end());
    reverse(s.begin(), s.end());
    return s;
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int flag=0;
	    string string1, string2;
	    cin >> string1 >> string2;
	    int places;
	    cin >> places;
	    
	    string1 = rotate(string1,places);        //for anti clockwise rotation
	    
      if(string1 == string2) {
          flag=1;
      }
      else {
          string1 = rotate(string1, string1.length() - (places * 2));     //for clockwise rotation (*2 since string is already rotated once)
          if(string1 == string2) {
              flag=1;
          }

      }
	    cout<<flag<<endl;
	}
	return 0;
}
