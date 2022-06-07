//C++ Program to implement 
//TC= 

#include<bits/stdc++.h>
using namespace std;

int minCoins(vector<int>& coins,int index, int amount)
{
    if(index==0)
    {
     if(coins[index]<amount)
       return 1e9;
     else 
       return amount/coins[index];
    }
    
    int take= 1 + minCoins(coins,index, amount-coins[index]);
    int not_take = minCoins(coins,index-1, amount);
    return min(take,not_take);
}

int main(){
      
    int n,amount;  
    cout<<"Enter Amount to make: ";  
    cin>> amount;
    cout<<"Enter no of denominations ";
    cin>>n;
    vector<int> coins(n);
    cout<<"Enter actual denominations ";
    for(int i=0;i<n;i++)
    {
       int deno;
       cin>>coins[i];
    }
    cout << "Minimum coins required is "<< minCoins(coins, n-1, amount);
    return 0;
    return 0;
}
   