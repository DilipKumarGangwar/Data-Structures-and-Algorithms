//Comment the rest of the code and run only one code at once.
//C++ Program to search a element in array using LINEAR SEARCH ( RECURSIVE code)
//2 Methdods are given 

//For both Methods
//TC = O(n)
//SC = O(n)  [ due to stack]

//1st method: Checking from index 0 to N-1
#include<iostream>
using namespace std;

bool linearSearch(int a[],int i,int n, int key)
{
   if(i > n)
      return false;
   if(a[i]==key)   
      return true;
   return (linearSearch(a,i+1,n,key)); 
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
   if(linearSearch(a,0,n-1,key))
       cout<<key<<" is present\n";
   else
       cout<<key<<" is NOT present\n";
}
    
//2nd method: Checking from index N-1  to 0
#include<iostream>
using namespace std;

bool linearSearch(int a[],int n, int key)
{
   if(n<0)
      return false;
   if(a[n]==key)   
      return true;
   return (linearSearch(a,n-1,key)); 
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
   if(linearSearch(a,n-1,key))
       cout<<key<<" is present\n";
   else
       cout<<key<<" is NOT present\n";
}