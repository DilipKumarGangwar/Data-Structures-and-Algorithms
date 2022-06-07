// 0-1 Knapsack Problem (Using DP - tabulation)
//TC=O(n*W) 
// SC=O(n*W)  //Space taken by Table

#include <bits/stdc++.h>
using namespace std;


// This code also works fine
int knapSack(int W, int wt[], int val[],int n) 
{
    vector<vector<int>> dp(n+1,vector<int>(W+1));
    //or int dp[n+1][W+1];

    //initialise 0th row
    for(int j=0;j<=W;j++)  
       dp[0][j]=0;
    //initialise 0th column
    for(int i=0;i<=n;i++)
       dp[i][0]=0; 
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=W;j++)
        {
            if(wt[i-1] > j)  //if item  weight is more than bag capacity
               //exclude
               dp[i][j]= dp[i-1][j];
            else
            {
                int include = val[i-1] + dp[i-1][j-wt[i-1]];
                int exclude = dp[i-1][j];
                dp[i][j]= max(include,exclude);
            }   
             
        }
    } 
     
    cout<<"DP table:\n"; 
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=W;j++)
        {
            cout<<dp[i][j]<<" ";

        } 
      cout<<endl;
    }  
    return dp[n][W];
    
}

main()
{
    int n;
    cout<<"Enter no of items: ";
    cin>>n;
    int value[n],weight[n],W;
    cout<<"Enter Weights:\n";
    for(int i=0;i<n;i++)
      cin>>weight[i];
    cout<<"Enter Profits:\n";
    for(int i=0;i<n;i++)
      cin>>value[i];
    cout<<"Enter Knapsack Capacity: ";
    cin>>W;  
    cout<<"Max. profit Earned="<<knapSack(W,weight,value,n);
    
    return 0;
}