//C++ Program to Perform DFS( Depth First Traversal - RECURSIVE VERSION) on a Undirected graph/ Directed graph
//This code works well for UNDIRECTED GRAPH
//For DIRECTED GRAPH, Just Remove 2nd line in addEdge() as mentioned in code
//TC= O(V+E)
//SC = O(V) For visited []

#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);  //remove this line for Directed graph
}

//Function to Perform DFS()
//Print the DFS traversal
void dfs(vector<int> adj[],int u,bool visited[]){
    
    visited[u]=true;  //Mark the vertex as Visited
    cout<<u<<" "; //Print the vertex, You can Store this also and print later
   
    //scan all neighbours of the  Vertex, u   
      for(auto it = adj[u].begin();it!=adj[u].end();it++) {
        //If neighbour is NOT Already Visited, then call DFS(that vertex) 
        // else  move to next neighbour
        if(!visited[*it])  
           dfs(adj,*it,visited);
      }
    // for(auto v:adj[u]){ 
    //     if(!visited[v])
    //         dfs(adj,v,visited);
    // }
}  //end of dfs()

int main(){
    int V,E;
	cout<<"Enter no of Vertices/nodes in Graph: ";
	cin>>V;
    cout<<"Enter no of Edges in Graph: ";
	cin>>E;
    vector<int> adj[V];
    bool visited[V];
    for(int i=0;i<E;i++)
    {
        int u,v;
        cin>>u>>v;
        addEdge(adj,u,v);
    }
    cout<<"Vertices in DFS Traversal: ";
    for(int i=0;i<V;i++){
        if(!visited[i]){  //send the vertex as source if that is NOT Already Visited
            dfs(adj,i,visited);
        }
    }

    return 0;
}  //end of main()