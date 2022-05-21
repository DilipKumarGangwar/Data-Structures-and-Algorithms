//C++ Program to implement Prims Algo using Adj. List
//MST weight is not PRINTED. IT WILL BE UPDATED after sometime

#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<pair<int,int>> adj[],int u,int v,int weight){
    adj[u].push_back({v,weight});
    adj[v].push_back({u,weight});  //remove this line for Directed graph
}

void initialise(int weight[],int parent[],int V)
{
    weight[0]=0;
    for(int i=1;i<V;i++)
      weight[i]=INT_MAX;
    for(int i=1;i<V;i++)
      parent[i]=-1;
}

int selectMinWeightVertex(int weight[],bool isIncluded[],int V)
{
    int minVertex, min=INT_MAX;
    for(int i=0;i<V;i++)
    {
       if(isIncluded[i]==false && weight[i]<min)
       {
           min=weight[i];
           minVertex=i;
       }
    }
    return minVertex;
}

void prims(vector<pair<int,int>> adj[],int weight[],int parent[],bool isIncluded[],int source,int V)
{
    for(int i=0;i<V-1;i++)
    {
        int u = selectMinWeightVertex(weight,isIncluded,V); 
        cout<<u;
        isIncluded[u]=true;
        //Relax all neighbours of u
        for(auto it: adj[u])
        {  
            int v=it.first;  // gives neighbour vertex
            int w=it.second;
            if(isIncluded[v]==false && w < weight[v])
            {
                //update or relax the v
                weight[v]= w;
                parent[v]= u;
            }
        }
    }

}


int main(){
    int V,E,w,source;
	cout<<"Enter no of Vertices/nodes in Graph: ";
	cin>>V;
    cout<<"Enter no of Edges in Graph: ";
	cin>>E;
    vector<pair<int,int>> adj[V];
    
    for(int i=0;i<E;i++)
    {
        int u,v;
        cin>>u>>v>>w;
        addEdge(adj,u,v,w);
    }
    cout<<"Enter source Vertex";
    cin>>source;
    int weight[V],parent[V];
    bool isIncluded[V]={false};
    initialise(weight,parent,V);

    prims(adj,weight,parent,isIncluded,source,V);
    cout<<"\nMST=\n";

    for(int i=1;i<V;i++)
      cout<<parent[i]<<","<< i<<endl;
     
    return 0;
}  //end of main()