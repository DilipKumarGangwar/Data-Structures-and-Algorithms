#include <bits/stdc++.h>
using namespace std;
void dfs(vector<pair<int,int>> adj[],int u,int label,int *no_of_cities,bool visited[],int distanceThreshold)
{
     
    cout<<"cit = "<<*no_of_cities;
    visited[u]=true;
    cout<<"City Visit= "<<u<<endl;
    for(auto it=adj[u].begin();it!=adj[u].end();it++)
    {
        cout<<"label= "<<label<<endl;
        if((label + it->second  <= distanceThreshold )&& visited[it->first]==false)
        {
            cout<<"inside\n";
            label=label+it->second;
            (*no_of_cities)++;
            dfs(adj,it->first,label,no_of_cities,visited,distanceThreshold);
        }
    }
    cout<<"sds ";
   
}


    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
         
        vector<pair<int,int>> adj[n];
        int ans;
        int e=edges.size();
        for(int i=0;i<e;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
            
        }
        for(int i=0;i<n;i++)
        {
            int label=0;
            int no_of_cities=0,max=INT_MIN;
            bool visited[n];
            memset(visited,false,sizeof(visited));
            dfs(adj,i,label,&no_of_cities,visited,distanceThreshold);
            cout<<"main= "<<no_of_cities<<endl;
            if(no_of_cities>=max)
            {
                ans=i;
                max=no_of_cities;
            }
        }
        return ans;
        
    }
int main()
{
   vector<vector<int>> edges {{0,1,3},{1,2,1},{1,3,4},{2,3,1}}; 
   cout<<findTheCity(4,edges,4);
}  