/*

Given N activities with their start and finish day given in array start[ ] and end[ ]. Select the maximum number of activities that can be performed by a single 
person, assuming that a person can only work on a single activity at a given day.
Note : Duration of the activity includes both starting and ending day.

Input: N = 2, start[] = {2, 1}, end[] = {2, 2}
Output: 1
Explanation: A person can perform only one of the given activities.

Constraints: 1 ≤ N ≤ 2*10^5, 1 ≤ start[i] ≤ end[i] ≤ 10^9

Approaches: The greedy choice is to always pick the next activity whose finish time is least among the remaining activities and the start time is more than or 
equal to the finish time of previously selected activity. We can sort the activities according to their finishing time so that we always consider the next activity
as minimum finishing time activity.
    1) Sort the activities according to their finishing time 
    2) Select the first activity from the sorted array and print it. 
    3) Do following for remaining activities in the sorted array. 
    …….a) If the start time of this activity is greater than or equal to the finish time of previously selected activity then select this activity and print it.

How does Greedy Choice work for Activities sorted according to finish time? 
    Let the given set of activities be S = {1, 2, 3, ..n} and activities be sorted by finish time. The greedy choice is to always pick activity 1. How come the 
    activity 1 always provides one of the optimal solutions. We can prove it by showing that if there is another solution B with the first activity other than 1, 
    then there is also a solution A of the same size with activity 1 as the first activity. Let the first activity selected by B be k, then there always exist 
    A = {B – {k}} U {1}.(Note that the activities in B are independent and k has smallest finishing time among all. Since k is not 1, finish(k) >= finish(1)).

*/
using namespace std;
bool mycomp(pair<int,int> a,pair<int,int> b)
{
    return (a.second<b.second);
}
int main()
 {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n],b[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    for(int i=0;i<n;i++)
	    {
	        cin>>b[i];
	    }
	    vector<pair<int,int>> v;
	    for(int i=0;i<n;i++)
	    {
	        v.push_back(make_pair(a[i],b[i]));
	    }
	    sort(v.begin(),v.end(),mycomp);
	    vector<pair<int,int>>::iterator it;
	    int count=1,endtime=v[0].second;
	    for(int i=1;i<n;i++)
	    {
	        if(v[i].first>=endtime)
	        {
	            count++;
	            endtime=v[i].second;
	        }
	    }
	    cout<<count<<endl;
	}
	return 0;
}
