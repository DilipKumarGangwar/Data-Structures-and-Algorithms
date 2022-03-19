//COMMENT the remaing program and run only one Logic at a time

//C++ Program to Print Natural No from 1 to N ( using Tail recursion)

#include<iostream>
using namespace std;

void print(int i, int N)
{
   if(i>N)     //Base Condition
      return;
   cout<<i<<" ";   
   print(i+1,N);//Recursive call 
}

main()
{
   int N; 
   cout<<"Enter the limit till which you want to print Natural No: ";
   cin>>N; 
   print(1, N);
}

//C++ Program to Print Natural No from 1 to N ( using Head recursion)
//Only Single Parameter is used
#include<iostream>
using namespace std;

void print(int N)
{
   if(N==0)      //Base Condition
      return;
   print(N-1);   //Recursive call
   cout<<N<<" ";
}

main()
{
   int N; 
   cout<<"Enter the limit till which you want to print Natural No: ";
   cin>>N; 
   print(N);
}    

