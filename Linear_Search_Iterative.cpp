//Comment the rest of the code and run only one code at once.
//C++ Program to search a element in array using LINEAR SEARCH ( iterative code)

//TC = O(n)
//SC = O(n)  [ due to stack]

#include<iostream>
using namespace std;

bool linearSearch(int a[],int n, int key)
{
   for(int i=0;i<n;i++)
   {
      if(key == a[i])
         return true;
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
   if(linearSearch(a,n,key))
       cout<<key<<" is present\n";
   else
       cout<<key<<" is NOT present\n";
}
    
