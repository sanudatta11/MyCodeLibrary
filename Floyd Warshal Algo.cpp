#include<bits/stdc++.h>
using namespace std;
//typedef vector<pair<int,int> >::iterator ITR;
//typedef vector<pair<int,int> > VEC;

struct Graph{
int v;
int e;
int **adj;
};

int proper_add(int a,int b)
{
    if(a==INT_MAX||b==INT_MAX)
        return INT_MAX;
    else
        return (a+b);
}


int **path;

void FloydWarshal(Graph *g)
{                       //Time complexitity is O(V^3)
path=new int*[g->v];
for(int i=0;i<g->v;i++)
    path[i]=new int[g->v];      //Making a global dyamic array of path

for(int i=0;i<g->v;i++)
    {
        for(int j=0;j<g->v;j++)
        {
            if(g->adj[i][j]!=0&&g->adj[i][j]!=INT_MAX)
                path[i][j]=i;
            else
                path[i][j]=g->v;
        }
    }

for(int k=0;k<g->v;k++)             //Main Floyd Warshal Algorithm
{
    for(int i=0;i<g->v;i++)
    {
        for(int j=0;j<g->v;j++)
        {
        int temp=g->adj[i][j];
        int temp1=proper_add(g->adj[i][k],g->adj[k][j]);    //Using Proper add so that the value doesnt increase than integer max
        if(temp>temp1)                                      //Traversing and finding is their a node that can be used to reach the destination making it the shortest route.
            {
                g->adj[i][j]=temp1;
                path[i][j]=k;                               //If shortest path is found then make that path the real one and then note its path.
            }
        }

    }

}

}

int main()
{
 Graph *g=new Graph;
 cout<<"Enter the number of vertices=";
 cin>>g->v;
 cout<<"Enter the number of edges=";
 cin>>g->e;
 g->adj=new int*[g->v];
 for(int i=0;i<g->v;i++)
    g->adj[i]=new int[g->v];     //The adjacent matrix holding the distance of all vertices

for(int i=0;i<g->v;i++)
    for(int j=0;j<g->v;j++)
        {  if(i!=j)
            g->adj[i][j]=INT_MAX;
           else
            g->adj[i][j]=0;
        }
for(int i=0;i<g->e;i++)
{
    int p1,p2,dist=0;
    cout<<"Enter the vertice (0-> (n-1)) (source->destination) and distance";
    cin>>p1>>p2>>dist;
   // cout<<"Enter the distance of the vertice "<<p1<<" and "<<p2<<" =";
    //cin>>dist;
    g->adj[p1][p2]=dist;
    //g->adj[p2][p1]=dist;
    p1=p2=0;
}

/*
int *dist_t;
dist_t=new int[g->v];*/
int source,destination;
cout<<"Enter the source=";
cin>>source;
FloydWarshal(g); //Used for making the path and distance table so that we can find the minimum distance of
                  //each vertex to the other ones.

bool negc=false;                             //Checking negative weight cycles in the given graph
 for(int t=0;t<g->v;t++)
 {
    if(g->adj[t][t]!=0)
        {

            cout<<"Adjoint at "<<t<<" "<<t<<"\n";
            cout<<g->adj[t][t]<<" ";
            negc=true;
            break;
        }
 }
 /*

if(negc)                                //if found its getting out and printing it has a negative weight cycle
{
    cout<<"There is a negative cycle in the graph \n Thus finding out the path in it is impossible\n";
    //getchar();
    cout<<"\n";
   // return 0;
}*/
cout<<"Enter the destination to reach=";
cin>>destination;
deque<int> path_final;
path_final.push_front(destination);
int temp=destination;
while(1)
 {
     if(temp==path[source][temp])
     {
         path_final.push_front(source);
         break;
     }
     temp=path[source][temp];
     path_final.push_front(temp);
 }

 cout<<"The Path is=\n";
 deque<int>::iterator itr=path_final.begin();
 for(;itr!=path_final.end();++itr)
     cout<<*itr<<"-->";

//Removing all dynamically allocated memory

 for(int i=0;i<g->v;i++)
    delete path[i];
 delete path;
  for(int i=0;i<g->v;i++)
    delete g->adj[i];
delete g;
 cout<<"\nSo that is the shortest path using Floyd Warshal";
 return 0;
}
