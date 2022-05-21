//C++ Program to Perform BFS( Breadth First Traversal - ITERATIVE VERSION) on a Undirected graph/ Directed graph
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

//Function to Perform BFS()
//Print the BFS traversal
void bfs(vector<int> adj[],int u,bool visited[]){
    queue<int> q;  //Create a Queue  for Processing Vertices
    q.push(u);     //Push the Source Vertex
    visited[u]=true;  //Mark the vertex as Visited
    while(!q.empty()){  //Run the loop till Queue is NOT Empty
      int u=q.front();   //Access the front vertex from queue and save 
      q.pop();           //Delete the Front Vertex
      cout<<u<<" ";      //Print the vertex, You can Store this also and print later
      
      //scan all neighbours of the popped Vertex, u   
      for(auto it = adj[u].begin();it!=adj[u].end();it++) {
        //If neighbour is NOT Already Visited, then push that into queue and mark that as visited
        // else  move to next neighbour
        if(!visited[*it]){   
           q.push(*it);
           visited[*it]=true;
        }
      }
      //Alternate way to write above code
    //   for(auto it:adj[u]){
    //       if(!visited[it]){   
    //        q.push(it);
    //        visited[it]=true;
    //     }
    //   }
    }  // end of bfs()
}

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
    cout<<"Vertices in BFS Traversal: ";
    for(int i=0;i<V;i++){
        if(!visited[i]){  //send the vertex as source if that is NOT Already Visited
            bfs(adj,i,visited);
        }
    }

    return 0;
}  //end of main()