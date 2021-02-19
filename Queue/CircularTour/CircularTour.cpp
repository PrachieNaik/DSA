/*

Problem statement: Suppose there is a circle. There are N petrol pumps on that circle. You will be given two sets of data.
1. The amount of petrol that every petrol pump has.
2. Distance from that petrol pump to the next petrol pump.
Find a starting point where the truck can start to get through the complete circle without exhausting its petrol in between.
Note :  Assume for 1 litre petrol, the truck can go 1 unit of distance.

Approaches:

Method 1: A Simple Solution is to consider every petrol pumps as a starting point and see if there is a possible tour. If we find a starting point with a feasible 
solution, we return that starting point. 

    Time Complexity: O(n^2)
    Space Complexity: O(1)

Method 2: An efficient approach is to use a Queue to store the current tour. We first enqueue first petrol pump to the queue, we keep enqueueing petrol pumps till
we either complete the tour, or the current amount of petrol becomes negative. If the amount becomes negative, then we keep dequeuing petrol pumps until the queue 
becomes empty.

    Time Complexity: O(N)
    Space Complexity: O(1)

*/

#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

int tour(petrolPump [],int );

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        cout<<tour(p,n)<<endl;
    }
}

int tour(petrolPump p[],int n)
{
   int start = 0, end = 1;
   int curPertrol = p[start].petrol - p[start].distance;
   
   while(start!=end || curPertrol < 0) {
       while(curPertrol < 0 && start!=end) {
           curPertrol -= (p[start].petrol - p[start].distance);
           start = (start+1) % n;
           
           if(start == 0)
           return -1;
       }
       curPertrol += (p[end].petrol - p[end].distance);
       end = (end + 1) % n;
   }
   return start;
}
