//Count All  Subsequences whose elements sum =k

//Given an array arr[] of length N and a number K, 
//the task is to Count total how many subsequences are there whose sum of elements is K
//With Recursion :
//TC=O(2^n) 
// SC=O(n) for storing subseqeunces


#include <bits/stdc++.h>
using namespace std;

void printsubsequences(vector<int> &arr,int sum,int n,int index,int s,int *count)
{
   if(index ==n)
   {
       if(s==sum) //if true count subsequence  
       {
           (*count)++;
       }
       return ; 
   }
   //otherwise
   //take the element
   s=s+arr[index];
   //subsequences.push_back(arr[index]);

   printsubsequences(arr,sum,n,index+1,s,count);
   
   //Undo to previous stage
   s=s- arr[index];
   //subsequences.pop_back();
   printsubsequences(arr,sum,n,index+1,s,count);
  return ;
}
int main()
{
   int n,sum;
   cout<<"Enter size of array";
   cin>>n;
   vector<int> arr(n);
 
   int count=0;
   for(int i=0;i<n;i++)
      cin>>arr[i];
   cout<<"Enter sum: ";
   cin>>sum; 
   
   printsubsequences(arr,sum,n,0,0,&count);
   cout<<"Total Subsequences count="<<count;
   return 0;
}