//C++ Program to search a element in array using BINARY SEARCH (ITERATIVE)

//TC = O(log n)
//SC = O(1)  


#include<iostream>
using namespace std;

bool binarySearch(int a[],int n,int key)
{
   int low=0,high=n-1;
   while(low<=high)
   {
      int mid = low + (high -low)/2; // (low+high)/2 can lead to overflow of mid
      if(a[mid] == key)
        return true;
      else if(key > a[mid])
        low = mid + 1;
      else if(key < a[mid])
        high = mid - 1;  
   }
   return false;  
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
   if(binarySearch(a,n,key))
       cout<<key<<" is present\n";
   else
       cout<<key<<" is NOT present\n";
}