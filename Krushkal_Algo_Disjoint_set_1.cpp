//C++ Program to Perform Cycle Detection using Disjoint Set
//MST weight is not PRINTED. IT WILL BE UPDATED after sometime

#include<bits/stdc++.h>
using namespace std;

struct node
{
    int u,v,weight;
    node(int firstVertex,int secondVertex,int w)
    {
        u=firstVertex;
        v=secondVertex;
        weight=w;
    }
};

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
void makeSet(vector<node> edges,int parent[],int V)
{
    memset(parent,-1,sizeof(int)*V);
}
int krushkal(vector<node> edges,int parent[],vector<node> &mst)
{
    
    //Iterate through edges
    int sum=0;
    for(auto edge: edges)
    {
        int fromVertex=find(edge.u,parent);
        int toVertex=find(edge.v,parent);
       // cout<<fromVertex<<" "<<toVertex<<endl;
        if(fromVertex!=toVertex)
        {
           union_op(fromVertex,toVertex,parent);
           mst.push_back(edge);   
           sum=sum+edge.weight;
        }
    }
    return sum;
}


bool comparator(node a, node b)
{
    return a.weight<b.weight;
}
int main(){
    int V,E,weight;
	cout<<"Enter no of Vertices/nodes in Graph: ";
	cin>>V;
    cout<<"Enter no of Edges in Graph: ";
	cin>>E;
    vector<node> edges; //stores edges with weight
    bool visited[V];
    for(int i=0;i<E;i++)
    {
        int u,v;
        cin>>u>>v>>weight;
        edges.push_back(node(u,v,weight));
    }
    //sort edges
    sort(edges.begin(),edges.end(),comparator);
    int parent[V];
    vector<node> mst; 
    makeSet(edges,parent,V);
    cout<<"Weight of MST= "<<krushkal(edges,parent,mst);
     cout<<"\nMST=\n";
    for(auto e:mst)
      cout<<e.u<<" "<<e.v<<" "<<e.weight<<"\n";
    return 0;
}  //end of main()