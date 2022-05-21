//C++ Program to implement Selection Sort
//TC= O(n^2)
//SC= O(1)

#include<iostream>
#include<climits>
using namespace std;
//2 5 1 7 6 3
int find_min_index(int a[],int &start,int &end,int &comp)
{
    int min=INT_MAX;
    for(int i=start;i<=end;i++)
    {   
        comp++;
        if(a[i]<a[min])
           min=i;
    }
    return min;
}

void selectionSort(int a[],int n)
{
   int start=0,end=n-1,comp=0,swap_op=0; 
   while(start<end)
   {
       int min_index =find_min_index(a,start,end,comp);
       if(min_index!=start)
       {   
           swap_op++;
           swap(a[start],a[min_index]);
       }
       start++;
   } 
   cout<<"Comparision="<<comp<<endl;
   cout<<"Swap Operation="<<swap_op<<endl;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
      cin>>a[i];
    selectionSort(a,n);  //call Selction sort
    for(int i=0;i<n;i++)
      cout<<a[i]<< " ";
}