// 0-1 Knapsack Problem (Using Recursion)
//TC=O(2^n) 
// SC=O(logn)  //stack space

#include <bits/stdc++.h>
using namespace std;

int knapSackUtil(int W, int wt[], int val[], int i,int n) 
{
    if(i==n) // if no more items remaining
        return 0;
    if( W == 0) // if bag has become full 
        return 0;
    //if item weight > bag capacity, then discard that item and go with next item    
    if(W-wt[i] < 0)    //or W < wt[i]
        return knapSackUtil( W , wt,val,i+1,n) ;
    //Include the item
    int leftProfit = val[i]+ knapSackUtil( W -wt[i], wt,val,i+1,n);  
    //Exclude the item
    int rightProfit = knapSackUtil( W , wt,val,i+1,n);  
    return max(leftProfit,rightProfit);
}
    
//Function to return max value that can be put in knapsack of capacity W.
int knapSack(int W, int wt[], int val[], int n) 
{ 
    // Your code here
    return knapSackUtil(W,wt,val,0,n);
}

// This code also works fine
int knapSack2(int W, int wt[], int val[],int n) 
    {
        if(n==0)
           return 0;
        if( W == 0)
           return 0;
        if(W-wt[n-1] < 0)
           return knapSack2( W , wt,val,n-1) ;
        int leftProfit = val[n-1]+ knapSack2( W -wt[n-1], wt,val,n-1);  
       // cout<<"left= "<<leftProfit<<" ";
        int rightProfit = knapSack2( W , wt,val,n-1);  
       // cout<<"right= "<<rightProfit<<" ";
        return max(leftProfit,rightProfit);
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
    //cout<<"Max. profit Earned="<<knapSack2(W,weight,value,n);
    return 0;
}