//Program to Print nth Fibonacci term using DP ( Memoization)
//TC=O(n)
//Sc=O(n)

#include <bits/stdc++.h>
using namespace std;

//0 1 1 2 3 5 8 13
int fib(int n,int dp[])
{
    if(n<=1) // if(n==0|| n==1)
      return n;
    if(dp[n]!=-1) // checking the stored result
       return dp[n];
    return (dp[n]=fib(n-1,dp)+fib(n-2,dp));     
}
int main()
{
   int n;
   cout<<"Enter no. of term";
   cin>>n;
   int dp[n+1];
   memset(dp,-1,sizeof(dp)); //fill array with -1 
   cout<<"Answer="<<fib(n,dp);
   return 0;
}






// //Program to Print nth Fibonacci term using DP ( Memoization)
// //TC=O(n)
// //Sc=O(n)

// #include <bits/stdc++.h>
// using namespace std;


int fib(int n,vector<int> &dp)
{
    if(n<=1) // if(n==0|| n==1)
      return n;
    if(dp[n]!=-1) // checking the stored result
       return dp[n];
    return (dp[n]=fib(n-1,dp)+fib(n-2,dp));     
}
int main()
{
   int n;
   cout<<"Enter no. of term";
   cin>>n;
   vector<int> dp(n+1,-1);
   cout<<"Answer="<<fib(n,dp);
   return 0;
}

