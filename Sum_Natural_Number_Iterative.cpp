
#include<iostream>
using namespace std;

int sum;
int findSum(int n)
{
   
   if(n == 0)    //Base Condition
      return sum;
   sum=sum+n;
   print(n-1);//Recursive call
   return sum; 
}

main()
{
   int n; 
   cout<<"Enter value of n"
   cin>>n; 
   cout<<"Final sum="<<findSum(n);
}
    
