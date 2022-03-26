//C++ Program to search a element in array using BINARY SEARCH (RECURSIVE)

//TC = O(log n)
//SC = O(log n)  [ due to stack]  

#include<iostream>
using namespace std;

bool binarySearch(int a[],int low,int high,int key)
{
    if(low > high)
      return false;    / //key is not present
    unisgned int mid = low + (high -low)/2; // (low+high)/2 can lead to overflow of mid
    if(a[mid] == key)
       return true;
    else if(key > a[mid])
       binarySearch(a,mid+1,high,key);  //changing low
    else if(key < a[mid])
       binarySearch(a,low,mid-1,key);  // changing high   
}

main()
{
   int n,key;
   cout<<"\nEnter array size: ";
   cin>>n;
   int a[n];
   cout<<"Enter Array elements\n";
   for(int i=0;i<n;i++)
      cin>>a[i];
   cout<<"Enter the element to search in array: ";  
   cin>>key; 
   if(binarySearch(a,0,n-1,key))
       cout<<key<<" is present\n";
   else
       cout<<key<<" is NOT present\n";
}