//Count ways to reach the n’th stair

//There are n stairs, a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time. Count the number of ways, 
//the person can reach the top.//With Recursion :
//TC=O(2^n) 
// SC=O(n)  //stack space


#include <bits/stdc++.h>
using namespace std;

int countWays(int n)
{
   int left,right; 
   if(n==0)
     return 0;
   if(n==1)
     return 1;
   left = countWays(n-1);
   right = countWays(n-2);
   return left+right;
}
int main()
{
   int n,sum;
   cout<<"Enter no. of stairs";
   cin>>n;
   cout<<"Total Ways to reach stair= "<<countWays(n);
   return 0;
}