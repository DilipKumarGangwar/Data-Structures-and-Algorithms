//Count ways to reach the n’th stair

//There are n stairs, a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time. Count the number of ways, 
//the person can reach the top.
//DP Sol( Memoization) :
//TC=O(2^n) 
// SC=O(n)  //stack space

#include <bits/stdc++.h>
using namespace std;
int climbStairsUtil(int n,vector<int> &dp)
{
   
    if(n==0)
        return 1;
    if(n==1)
        return 1;
    if(dp[n]!=0)
        return dp[n];
    return (dp[n]=climbStairsUtil(n-1,dp) + climbStairsUtil(n-2,dp));
   
}

int climbStairs(int n) 
{
      vector<int> dp(n+1);
      return climbStairsUtil(n,dp);
      
}

int main()
{
   int n,sum;
   cout<<"Enter no. of stairs: ";
   cin>>n;
   cout<<"Total Ways to reach stair= "<<climbStairs(n);
   return 0;
}