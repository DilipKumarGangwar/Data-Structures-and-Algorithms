//COMMENT the remaing program and run only one Logic at a time

//C++ Program to Print Natural No from N to 1 ( using Tail recursion and 2 parameters)

#include<iostream>
using namespace std;

void print(int N, int i)
{
   if(N<i)     //Base Condition
      return;
   cout<<N<<" ";   
   print(N-1,i);//Recursive call  or print(--N,i)
}

main()
{
   int N; 
   cout<<"Enter the limit  from where you want to start printing Natural No: ";
   cin>>N; 
   print(N, 1);
}

//C++ Program to Print Natural No from N to 1 ( using Tail recursion and single parameter)

#include<iostream>
using namespace std;

void print(int N)
{
   if(N<1)     //Base Condition or if( N==0)
      return;
   cout<<N<<" ";   
   print(N-1);//Recursive call  or print(--N,i)
}

main()
{
   int N; 
   cout<<"Enter the limit where you want to start printing Natural No: ";
   cin>>N; 
   print(N);
}

//C++ Program to Print Natural No from N to 1 ( using Head recursion)

#include<iostream>
using namespace std;

void print(int i,int N)
{
   if(i>N)      //Base Condition
      return;
   print(i+1,N);   //Recursive call  ( or print(++i,N-1))
   cout<<i<<" ";
}

main()
{
   int N; 
   cout<<"Enter the limit where you want to start printing Natural No: ";
   cin>>N; 
   print(1,N);
}    

