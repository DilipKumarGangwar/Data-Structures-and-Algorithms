//Comment the rest of the code and run only one code at once.
//C++ Program to Print the Sum of  first N natural Numbers 

//For all 3 Methods
   //TC = O(n)
   //SC = O(n)  [ due to stack]
   
//1st Method : Using Global Varible sum
//TC = O(n)
//SC = O(n)
#include<iostream>
using namespace std;

int sum;   //Global variable
int findSum(int n)
{
   
   if(n == 0)    //Base Condition
      return sum;
   sum=sum+n;
   findSum(n-1);//Recursive call
   return sum; 
}

main()
{
   int n; 
   cout<<"Enter value of n: ";
   cin>>n; 
   cout<<"Final sum="<<findSum(n);
}


// //2nd Method ( Using Static Variable Sum)

#include<iostream>
using namespace std;


int findSum(int n)
{
   static int sum;   //static variable
   if(n == 0)    //Base Condition
      return sum;
   sum=sum+n;
   findSum(n-1);//Recursive call
   return sum; 
}

main()
{
   int n;  
   cout<<"Enter value of n: ";
   cin>>n; 
   cout<<"Final sum="<<findSum(n);
}
    
//3rd Method ( Using Global /Static Variable)

#include<iostream>
using namespace std;

int findSum(int n)
{
  
   if(n == 0)    //Base Condition
      return 0;
   return n+ findSum(n-1);//Recursive call
}

main()
{
   int n;  
   cout<<"Enter value of n: ";
   cin>>n; 
   cout<<"Final sum="<<findSum(n);
}