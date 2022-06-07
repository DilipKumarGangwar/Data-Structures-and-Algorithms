//Longest Common Subsequence ( DP: Memoized + Tabulation Sol)

//TC=O(n*m)  SC=O(n*m) 


#include <bits/stdc++.h>
using namespace std;

int LCS(string text1,string text2,int n,int m,vector<vector<int>> &dp )
{
    if(n==0 || m==0)   //any one string id of zero length
     return 0;
   
    //fill 0th row
    for(int j=0;j<=m;j++)
        dp[0][j] = 0;
    for(int i=0;i<=n;i++)
        dp[i][0] = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
             if(text1[i-1] == text2[j-1])
                 dp[i][j] = dp[i-1][j-1] +1 ; //add 1 to diagonal entry
             else
                 dp[i][j] = max( dp[i-1][j] , dp[i][j-1]); 
        }
    }
    cout<<"DP table:\n";
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    return dp[n][m] ;
}

//Memoized Code 

// int LCS(string text1,string text2,int n,int m, vector<vector<int>> &dp)
// {
//    if(n==0 || m==0)   //any one string ends
//      return 0;
  
//    if(text1[n-1] == text2[m-1])
//        return (dp[n][m]=1 + LCS(text1,text2,n-1,m-1,dp));
//      if(dp[n][m]!=-1)
//        return dp[n][m];
  
//   return dp[n][m]=max( LCS(text1,text2,n-1,m,dp), LCS(text1,text2,n,m-1,dp) ) ;

// }
     
int main()
{
   string text1,text2;
   cout<<"Enter 1st String: ";
   cin>>text1;
   cout<<"Enter 2nd String: ";
   cin>>text2;
   int n= text1.size();
   int m=text2.size();
   vector<vector<int>> dp((n+1),vector<int> (m+1));
   int ans= LCS(text1,text2, n,m,dp);
   cout<<"\nLCS of both strings= "<<ans;
   return 0;
}