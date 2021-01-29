/*

WAP to reverse words in a given string
Example: Let the input string be “i like this program very much”. The function should change the string to “much very program this like i”

Method: Reverse the whole string. Reverse individual words in reversed string.

Time Complexity: O(n), Space Complexity: O(1)

*/



using namespace std;
int main()
 {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    reverse(s.begin(),s.end());
	    int prev=0;
	    for(int i=0;i<s.length();i++)
	    {
	        if(s[i]=='.')
	        {
	           
	           reverse(s.begin()+prev,s.begin()+i);
	            prev=i+1;
	            
	        }
	        
	    }
	    reverse(s.begin()+prev,s.end());
	    cout<<s<<endl;
	}
	return 0;
}
