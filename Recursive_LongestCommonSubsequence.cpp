//Longest Common Subsequence ( Recursive Sol)

//TC=O(2^n* 2^m) 


#include <bits/stdc++.h>
using namespace std;

int LCS(string text1,string text2,int n,int m )
{
   if(n==0 || m==0)   //any one string ends
     return 0;
   if(text1[n-1] == text2[m-1])
       return 1 + LCS(text1,text2,n-1,m-1);
  
  return max(LCS(text1,text2,n-1,m),LCS(text1,text2,n,m-1) );

}

int main()
{
   string text1,text2;
   cout<<"Enter 1st String: ";
   cin>>text1;
   cout<<"Enter 2nd String: ";
   cin>>text2;
   cout<<"LCS of both strings= "<<LCS(text1,text2, text1.size(), text2.size());
   return 0;
}