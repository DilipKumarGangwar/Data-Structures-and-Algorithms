//Print any one  Subsequences whose elements sum =k

//Given an array arr[] of length N and a number K, 
//the task is to find all the subsequences of the array whose sum of elements is K
//With Recursion :
//TC=O(2^n) 
// SC=O(n) for storing subseqeunces


#include <bits/stdc++.h>
using namespace std;

void printsubsequences(vector<int> &arr,int sum,int n,int index,int s, vector<int> &subsequences)
{
   if(index ==n)
   {
       if(s==sum) //if true print subsequence and return else return doing nothing
       {
           //print subsequence
           for(auto i: subsequences)
             cout<<i<<" ";
           cout<<endl;  
       }
       return ; 
   }
   //otherwise
   //take the element
   s=s+arr[index];
   subsequences.push_back(arr[index]);

   printsubsequences(arr,sum,n,index+1,s,subsequences);
   
   //Undo to previous stage
   s=s- arr[index];
   subsequences.pop_back();
   printsubsequences(arr,sum,n,index+1,s,subsequences);
  return ;
}
int main()
{
   int n,sum;
   cout<<"Enter size of array";
   cin>>n;
   vector<int> arr(n);
   vector<int> subsequences;
   for(int i=0;i<n;i++)
      cin>>arr[i];
   cout<<"Enter sum: ";
   cin>>sum; 
   cout<<"All Subsequences:\n" ;
   printsubsequences(arr,sum,n,0,0,subsequences);
   return 0;
}