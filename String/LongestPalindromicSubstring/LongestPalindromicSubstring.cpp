/*

Given a string S, find the longest palindromic substring in S. Substring of string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S). Palindrome string: A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S. Incase of conflict, return the substring which occurs first ( with the least starting index ).

Method 1: Brute Force. 
Approach: The simple approach is to check each substring whether the substring is a palindrome or not. To do this first, run three nested loops, the outer two loops pick all substrings one by one by fixing the corner characters, the inner loop checks whether the picked substring is palindrome or not. 
Time complexity: O(n^3). Space complexity: O(1). 



Method 2: Dynamic Programming. 
Maintain a boolean table[n][n] that is filled in bottom up manner.
The value of table[i][j] is true, if the substring is palindrome, otherwise false.
To calculate table[i][j], check the value of table[i+1][j-1], if the value is true and str[i] is same as str[j], then we make table[i][j] true.
Otherwise, the value of table[i][j] is made false.
We have to fill table previously for substring of length = 1 and length =2 because 
as we are finding , if table[i+1][j-1] is true or false , so in case of 
(i) length == 1 , lets say i=2 , j=2 and i+1,j-1 doesn’t lies between [i , j] 
(ii) length == 2 ,lets say i=2 , j=3 and i+1,j-1 again doesn’t lies between [i , j].
Time complexity: O(n^2). Space complexity: O(n^2). 



Method 3: 
The idea is to generate all even length and odd length palindromes and keep track of the longest palindrome seen so far.
To generate odd length palindrome, Fix a centre and expand in both directions for longer palindromes, i.e. fix i (index) as center and two indices as i1 = i+1 and i2 = i-1
Compare i1 and i2 if equal then decrease i2 and increase i1 and find the maximum length.
Use a similar technique to find the even length palindrome.
Take two indices i1 = i and i2 = i-1 and compare characters at i1 and i2 and find the maximum length till all pair of compared characters are equal and store the maximum length.
Time complexity: O(n^2). Space complexity: O(1). 


*/


using namespace std;
int main()
 {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    int lo,hi,start=0;
	    int max=1;
	    int n=s.length();
	    for(int i=1;i<n;i++)
	    {
	        lo=i-1;
	        hi=i;
	        while(lo>=0 && hi<=n && s[lo]==s[hi])
	        {
	            if(hi-lo+1>max)
	            {
	                start=lo;
	                max=hi-lo+1;
	            }
	            lo--;
	            hi++;
	        }
	        lo=i-1;
	        hi=i+1;
	         while(lo>=0 && hi<=n && s[lo]==s[hi])
	        {
	            if(hi-lo+1>max)
	            {
	                start=lo;
	                max=hi-lo+1;
	            }
	            lo--;
	            hi++;
	        }
	        
	    }
	    for(int i=start;i<start+max;i++)
	    {
	        cout<<s[i];
	    }
	    cout<<endl;
	}
	return 0;
}
