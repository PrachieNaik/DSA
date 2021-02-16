/*

Problem statement: Suppose you have N eggs and you want to determine from which floor in a K-floor building you can drop an egg such that it doesn't break. 
    You have to determine the minimum number of attempts you need in order find the critical floor in the worst case while using the best strategy.
    There are few rules given below. 

    An egg that survives a fall can be used again.
    A broken egg must be discarded.
    The effect of a fall is the same for all eggs.
    If the egg doesn't break at a certain floor, it will not break at any floor below.
    If the eggs breaks at a certain floor, it will break at any floor above.

Constraints:
1<=N<=10
1<=K<=50

Approach: When we drop an egg from a floor x, there can be two cases (1) The egg breaks (2) The egg doesn’t break.

    If the egg breaks after dropping from ‘xth’ floor, then we only need to check for floors lower than ‘x’ with remaining eggs as some floor should exist lower than ‘x’ in which egg would not break; so the problem reduces to x-1 floors and n-1 eggs.
    If the egg doesn’t break after dropping from the ‘xth’ floor, then we only need to check for floors higher than ‘x’; so the problem reduces to ‘k-x’ floors and n eggs.
    Since we need to minimize the number of trials in worst case, we take the maximum of two cases. We consider the max of above two cases for every floor and choose the floor which yields minimum number of trials.

Complexity Analysis:

Time Complexity: As there is a case of overlapping sub-problems the time complexity is exponential.
Auxiliary Space :O(1). As there was no use of any data structure for storing values.

*/
int eggDrop(int eggs, int floors) 
{
    // your code here
    if(floors == 1 || floors == 0)
    return k;
    
    if(eggs == 1)
    return k;
    
    int ans = INT_MAX;
    for(int i = 1;i <= floors;i++) {
        int temp = 1 + max(eggDrop(eggs - 1,i - 1), eggDrop(eggs, floors - i));
        ans = min(temp,ans);
    }
    
    return ans;
}
