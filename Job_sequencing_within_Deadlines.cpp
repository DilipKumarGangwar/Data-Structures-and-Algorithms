//C++ Program to implement Job Scheuling Problem
//TC= O(nlogn) + O(nm)  [ n= no of jobs,m = max deadline or slots]
//SC = O(m) for slot[]

#include<bits/stdc++.h>
using namespace std;

struct Jobs 
{
    int jobid,deadline,profit;
};

bool comparator(Jobs j1, Jobs j2)
{
   return (j1.profit > j2.profit);
}

int findMaxDeadline(Jobs job_info[],int n)
{
     int maximum=INT_MIN;
     for(int i=0;i<n;i++)
         maximum=max(maximum,job_info[i].deadline);  
     return maximum; //max value of deadline    
}

bool putJob(Jobs job,vector<int> &slot)
{
    int deadline=job.deadline;
    for(int i=deadline;i>0;i--)
    {
        
        if(slot[i] == -1)
        {
          slot[i]=job.jobid;
          return true;
        }
    }
    return false;
}
pair<int,int> findMaxProfit(Jobs job_info[],int n)
{
    int job_finish=0,maxProfitEarned=0;
    //sort array on the basis of profit
    sort(job_info,job_info+n,comparator);
    //Make a array of size of max deadline
    int maxDeadline=findMaxDeadline(job_info,n);
    
    //create a slot array of max deadline size
    vector<int> slot((maxDeadline+1), -1);
    
    //Iterate through sorted job_info
    for(int i=0;i<n;i++)
    {
       //try to put ith job in slot[] and return success if done
         if(putJob(job_info[i],slot))
         {
             
             job_finish++; 
             maxProfitEarned += job_info[i].profit;  
         }
        
    }
    cout<<"Sequence of Jobs finished( shown in terms of Job Ids)\n";
    for(int i=1;i<=maxDeadline;i++)
      cout<<slot[i]<<" ";
    cout<<endl;  
    return make_pair(job_finish, maxProfitEarned);
}

int main(){
      
    int n;
    cout<<"Enter no of jobs to schedule";
    cin>>n;
	Jobs job_info[n];
    pair<int,int> answer;
    cout<<"Enter jobid,deadline , profit of each job\n";
    for(int i=0;i<n;i++)
        cin>>job_info[i].jobid>>job_info[i].deadline>>job_info[i].profit;
    answer=findMaxProfit(job_info,n);
    cout<<"Maximum Jobs Finished="<<answer.first<<endl;
    cout<<"Maximum Profit Earned="<<answer.second<<endl;
    return 0;
}
   