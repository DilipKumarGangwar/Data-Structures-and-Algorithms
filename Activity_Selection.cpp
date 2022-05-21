//C++ Program to implement Activity Selection Problem
//TC= O(nlogn + n )
//SC=O(n) for storing answer

#include<bits/stdc++.h>
using namespace std;

struct Activity
{
    int start_time,finish_time;
};

bool comparator(Activity I1, Activity I2)
{
   return (I1.finish_time<I2.finish_time);
}

void findmaxSize_ActivitySelectionSet_Util(Activity activity_record[],int i,int j,int n,vector<Activity> &answer)
{
   if(j<n)
   {
       while(activity_record[j].start_time < activity_record[i].finish_time)
           j++;
       answer.push_back(activity_record[j]);
       findmaxSize_ActivitySelectionSet_Util( activity_record,j,j+1,n,answer);

   }
}
void findmaxSize_ActivitySelectionSet(Activity activity_record[],int n,vector<Activity> &answer)
{
   //sort the activities according to finsih times
   sort(activity_record,activity_record+n,comparator);
   answer.push_back(activity_record[0]);
   findmaxSize_ActivitySelectionSet_Util( activity_record,0,1,n,answer);
}   


int main(){
    int n;
    cin>>n;
	Activity activity_record[n];
    vector<Activity> answer;
    cout<<"Enter start time and finish time of activities\n";
    for(int i=0;i<n;i++)
        cin>>activity_record[i].start_time>>activity_record[i].finish_time;
    
    findmaxSize_ActivitySelectionSet(activity_record,n,answer);  
   
    for(auto it:answer)
       cout<<it.start_time<<" "<<it.finish_time<<endl;
    return 0;
}
   