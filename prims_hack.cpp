#include<bits/stdc++.h>
using namespace std;
typedef map<int,int> MM;
//typedef map<int,pair<int,int>> NN;
typedef map<int,int>::iterator ITR;
struct Graph{
    int v;
    int e;
    int **adj;
};
ITR findmin(MM &dist_map)
{
    ITR ans=dist_map.begin();
    ITR itr=dist_map.begin();
    for(;itr!=dist_map.end();++itr)
        if(itr->second<ans->second)
                ans=itr;

    return ans;
}

int main()
{
    Graph *g=new Graph;
    MM dist;
    MM edge;
    MM result;
    cin>>g->v>>g->e;
    g->adj=new int*[g->v];
    for(int i=0;i<g->v;i++)
    {   dist.insert(make_pair(i,0));
        g->adj[i]=new int[g->v];
        for(int j=0;j<g->v;j++)
            {
                dist.insert(make_pair(j,INT_MAX));
                g->adj[i][j]=-1;
            }
    }
    for(int i=0;i<g->e;i++)
    {
        int t1,t2,wt;
        cin>>t1>>t2>>wt;
        t1--;t2--;
        if(g->adj[t1][t2]==-1||g->adj[t1][t2]>wt)
        g->adj[t1][t2]=wt;
        if(g->adj[t2][t1]==-1||g->adj[t2][t1]>wt)
        g->adj[t2][t1]=wt;
    }
    int source;
    cin>>source;
    source--;
    dist[source]=0;
    while(!dist.empty())
    {
        ITR value=findmin(dist);
        for(int j=0;j<g->v;j++)
        {
            if(g->adj[value->first][j]!=-1)
            {
                ITR temp=dist.find(j);
                if(temp!=dist.end())
                    {

                        int temp_wt=g->adj[value->first][j]+value->second;
                        if(temp_wt<temp->second)
                            temp->second=temp_wt;
                        edge.insert(make_pair(value->first,j));
                    }
            }
        }
        //final_dist.insert(make_pair(value->first,value->second));
        if(value->first!=source)
        {
        ITR use1=edge.begin();
        for(;use1!=edge.end();++use1)
         {
            if(use1->second==value->first)
            {    result.insert(make_pair(use1->first,use1->second));
                 break;
            }
         }
        }
        dist.erase(value);
    }
    int ans_weight=0;
    ITR finalone=result.begin();
    for(;finalone!=result.end();++finalone)
        ans_weight+=g->adj[finalone->first][finalone->second];
    cout<<ans_weight;
    delete g;

}
