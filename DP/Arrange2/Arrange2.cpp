/*

Problem statement: You are given a sequence of black and white horses, and a set of K stables numbered 1 to K. You have to accommodate the horses into the
stables in such a way that the following conditions are satisfied:

You fill the horses into the stables preserving the relative order of horses. For instance, you cannot put horse 1 into stable 2 and horse 2 into stable 1.
You have to preserve the ordering of the horses.
No stable should be empty and no horse should be left unaccommodated.
Take the product (number of white horses * number of black horses) for each stable and take the sum of all these products. This value should be the minimum
among all possible accommodation arrangements

Example:
Input: {WWWB} , K = 2
Output: 0

Explanation:
We have 3 choices {W, WWB}, {WW, WB}, {WWW, B}
for first choice we will get 1*0 + 2*1 = 2.
for second choice we will get 2*0 + 1*1 = 1.
for third choice we will get 3*0 + 0*1 = 0.

Of the 3 choices, the third choice is the best option. 

If a solution is not possible, then return -1

*/

int dp[1000][1000];
int check(int i,string a,int b)
{
    if(i==a.length())
    {
        return 0;
    }
    else if(dp[i][b]!=-1)
    {
        return dp[i][b];
    }
    else
    {
        if(b==1)
        {
            int black=0;
            int white=0;
            for(int k=i;k<a.length();k++)
            {
                if(a[k]=='W')
                {
                    white++;
                }
                else
                {
                    black++;
                }
            }
            dp[i][b]=white*black;
            return white*black;
        }
        else
        {
            int black=0;
            int white=0;
            int minl=INT_MAX;
            for(int k=i;k<a.length();k++)
            {
                if(a[k]=='W')
                {
                    white++;
                }
                else
                {
                    black++;
                }
                minl=min(minl,(black*white)+check(k+1,a,b-1));
            }
            dp[i][b]=minl;
            return minl;
        }
    }
}
int Solution::arrange(string a, int b) {
    if(b>a.size())
    {
        return -1;
    }
    memset(dp,-1,sizeof(dp)); 
    return check(0,a,b);
}

