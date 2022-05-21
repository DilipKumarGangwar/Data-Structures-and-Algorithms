//C++ Program to Perform Cycle Detection using Disjoint Set

#include<bits/stdc++.h>
using namespace std;

int find(int v,int parent[])
{
    if(parent[v]==-1)
       return v;
    return find(parent[v],parent);   
}

void union_op(int from,int to,int parent[])
{
    parent[from]=to;
}
bool isCyclic(vector<pair<int,int>> edges,int parent[])
{
    for(auto e: edges)
    {
        int fromVertex=find(e.first,parent);
        int toVertex=find(e.second,parent);
        // cout<<fromVertex<<" "<<toVertex<<endl;
        if(fromVertex==toVertex)
           return true; //cycle present   
        union_op(fromVertex,toVertex,parent);

    }
    return false;
}

void makeSet(int parent[],int V)
{
    memset(parent,-1,sizeof(int)*V);
}

int main()
{
	int E;	//No of edges
	int V;	//No of vertices 
    cout<<"Enter No of Vertices and Edges";
	cin>>V>>E;
    
    vector<pair<int,int>> edges;	//Adjacency list
	int parent[V];
    makeSet(parent,V);
    for(int i=0;i<E;i++)
	{
		int from,to;
		cin>>from>>to;
		edges.push_back({from,to});
	}
    if(isCyclic(edges,parent))
		cout<<"Cycle is Present\n";
	else
		cout<<"Cycle is NOT Present\n";
	
	return 0;
}