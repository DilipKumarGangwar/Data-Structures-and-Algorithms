//Program to Print nth Fibonacci term using DP ( Tabulation)
//Without Space Optimization: TC=O(n) SC=O(n)
// With Space Optimization:  TC=O(n)   SC=O(1)

#include <bits/stdc++.h>
using namespace std;


int fib(int n)
{
    // dp[0]=0;
    // dp[1]=1; 
    // for(int i=2;i<=n;i++)
    //   dp[i]=dp[i-1] + dp[i-2];
    // return dp[n];  



    int x=0,y=1,curr;
    for(int i=2;i<=n;i++)
    {
        curr = x+ y;
        x=y;
        y=curr;        
    }
    return curr;
         
}

int main()
{
   int n;
   cout<<"Enter no. of term";
   cin>>n;
  // vector<int> dp(n+1);
   cout<<"Answer="<<fib(n);
   return 0;
}