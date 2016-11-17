#include <bits/stdc++.h>
using namespace std;
struct node{
	int parent;
	int data;
	int rank;

};

struct Graph {
	int v;
	int e;
	int **adj;
};

Graph *g;
node *n;						//Global variables for holding the graph and node


node findparent(node &u)				//For finding the set which the node belongs to
	{
		
		if(u.data==n[(u.parent)].data)
			return u;
		u.parent=findparent(u).parent;
		return n[u.parent];
	}

void _union(node u,node v)					//Making union of two sets such that they can have a single same parent
	{
		u.parent=findparent(u).data;
		v.parent=findparent(v).data;
		if(n[(u.parent)].rank>=n[(v.parent)].rank)
		{
			if(n[(u.parent)].data==n[(v.parent)].data)
				return;
			n[(v.parent)].parent=u.parent;
			n[(u.parent)].rank++;
		}
		else
		{
			n[(u.parent)].parent=v.parent;
			n[(v.parent)].rank++;
		}
	}


int main()
{
	int ans=0;
	g=new Graph;
	cin>>g->v;
	cin>>g->e;
	g->adj=new int*[g->v];				//Creating a weight table so that to store the distances
	n=new node[g->v];					// Creating an array of nodes because we are gonna use adjoint sets here.Initilally
										// all elements point to itself only.
	for(int i=0;i<g->v;i++)
		{
			g->adj[i]=new int[g->v];
			n[i].data=i;
			n[i].parent=i;
			n[i].rank=0;
		}
	vector<int> weight;						//The table for keeping the weight of the different edge
	map<int,pair<int,int> > edge_table;		//The map which will map the weight to the pair of vertices
	for(int i=0;i<g->e;i++)
	{
		int t1,t2,wt;
		cin>>t1>>t2>>wt;
		t1--;t2--;
		weight.push_back(wt);
		//pair<int,int> take;
		//edge_table.insert(wt,make_pair(t1,t2));
		edge_table[wt]=make_pair(t1,t2);
		g->adj[t1][t2]=g->adj[t2][t1]=wt;
	}
	cout<<"Level 1 Crossed\n";
	sort(weight.begin(),weight.end());
	while(!edge_table.empty())
	{
		map<int,pair<int,int> >::iterator itr=edge_table.end();
		itr=edge_table.find(*weight.begin());
		if(itr!=edge_table.end())
		{
			cout<<"In Level 2\n"<<(itr->second).first<<" "<<(itr->second).second<<"\n";
			node &u=n[((itr->second).first)];
			node &v=n[((itr->second).second)];

			if(findparent(u).data!=findparent(v).data)
				{	cout<<"Level 3 reached\n";
					_union(u,v);
					
					ans+=g->adj[u.data][v.data];
				}
			weight.erase(weight.begin());
			edge_table.erase(itr);
		}
	}
	cout<<ans;
    delete g;
    delete n;
	return 2;
}
