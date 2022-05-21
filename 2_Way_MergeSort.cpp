//C++ Program to implement Merge Sort
//TC= O(nlogn)
//SC= O(n)

#include<iostream>
using namespace std;

void merge(int a[], int l, int mid,int h)
{
   // cout<<"sds ";
   // cout<<l<<" "<<mid<< " "<<h<<endl;
    int i=l,j=mid+1,k=0;
    int size=h-l+1;
    int b[size];
    while(i<=mid && j<=h)
    {  
        //comp++; 
        if(a[i]<a[j])
            b[k++]=a[i++];
        else 
            b[k++]=a[j++];   
    } 

    //copy remaining part of first part of a[]
    while(i<=mid)
       b[k++]=a[i++];
    //copy remaining part of second part of a[]   
    while(j<=h)
       b[k++]=a[j++];    

    //Finally copy b[] into a[]
    j=0;
    for(int i=l;i<=h;i++)
      a[i]=b[j];
}

void mergeSort(int a[],int l,int h)
{
    if(l<h)
    {
       int mid = (l+h)/2;
       mergeSort(a,l,mid); //first half
       mergeSort(a,mid+1,h);  //second half
       merge(a,l,mid,h);    //merge first and second half
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
      cin>>a[i];
    mergeSort(a,0,n-1);  //call mergesort
    for(int i=0;i<n;i++)
      cout<<a[i]<< " ";
}