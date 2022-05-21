//C++ Program to Detect Cycle in Undirected Graph using DFS
//TC= O(V+E)
//SC = O(V) //due to visited array

#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);  
}

bool dfs(vector<int> adj[],int u,bool visited[],int parent){
    visited[u]=true;
    //cout<<"u="<<u<<" parent="<<parent<<endl;
    for(auto v:adj[u]){  
        cout<<"V="<<v<<endl;      
        if(!visited[v]){             
           if( dfs(adj,v,visited,u)){
           return true; // Cycle is present
           }
        }
        else if(v!=parent){
            return true; // Cycle is present
        }
    }
    return false; // Cycle is present till current point of time
}

int main(){
    int V,E;
	cout<<"Enter no of Vertices/nodes in Graph: ";
	cin>>V;
    cout<<"Enter no of Edges in Graph: ";
	cin>>E;
    vector<int> adj[V];
    bool visited[V],flag=false;
    for(int i=0;i<E;i++)
    {
        int u,v;
        cin>>u>>v;
        addEdge(adj,u,v);
    }
    for(int i=0;i<V;i++){
        cout<<"ok ";
        if(!visited[i]){
            if(dfs(adj,i,visited,-1)){
               cout<<"Cycle is present";
               flag=true;
               break;
            }
        }
    }
    if(flag==false)
      cout<<"Cycle is NOT present";
    return 0;
}
   