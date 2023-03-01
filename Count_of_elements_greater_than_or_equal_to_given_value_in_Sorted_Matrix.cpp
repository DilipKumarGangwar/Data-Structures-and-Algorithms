// Find number of elements greater than or equal to given value in Sorted Matrix
//TC = O(n+m)  
//SC = O(1)

#include<bits/stdc++.h>
#include<unistd.h>  //for sleep()
using namespace std;

int countGreaterThan(vector<vector<int>> &matrix,int element,int rows,int col)
{
    int i=0,j=col-1;
    int count = 0;
    while(i<rows && j>=0)
    {
       if(matrix[i][j] >= element)
       {
           //count all elements in that jth col
           count =  count + (rows - i);
           j--;  // go to previous col now
       }      
       // if current ele is lesser than asked element, then go to next row (below ) 
       else
          i++;   
         
    }
    return count;
}

int main()
{
    int rows,col,element;
    cout<<"Enter rows and column of matrix: ";
    cin>>rows>>col;
    cout<<"Enter the element: ";
    cin>>element;
    vector<vector<int>> matrix(rows,vector<int> (col));
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cin>> matrix[i][j];
        }
    }
    cout<<"Total Numbers Greater than "<<element<<" are : " <<countGreaterThan(matrix,element,rows,col);
    return 0;
}