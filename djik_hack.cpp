#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
#define fastio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef map<int,int> MM;
typedef map<int,int>::iterator ITR;
typedef pair<int,int> PP;
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

int main() {
    fastio;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
        {
            MM final_dist;
            MM dist_map;
            Graph *g=new Graph;
            cin>>g->v>>g->e;
            g->adj=new int*[g->v];
            for(int j=0;j<g->v;++j)
                {g->adj[j]=new int[g->v];
                 dist_map.insert(make_pair(j,INT_MAX));
                }
            for(int k1=0;k1<g->v;++k1)
                for(int k2=0;k2<g->v;++k2)
                        g->adj[k1][k2]=-1;
            //memset(g->adj,-1,2*g->v*g->v);
            for(int j=0;j<g->e;j++)
            {
                int t1,t2,wt;
                cin>>t1>>t2>>wt;
                t1--;t2--;
                if(g->adj[t1][t2]==-1||g->adj[t1][t2]>wt)
                    g->adj[t1][t2]=wt;
            }
            int source,dest;
            cin>>source>>dest;
            source--;
            dest--;
            dist_map[source]=0;
           /* for(int j=0;j<g->v;j++)
            {    for(int j1=0;j1<g->v;j1++)
                    cout<<g->adj[j][j1]<<" ";
                cout<<"\n";
            }
            ITR itr1=dist_map.begin();
            for(;itr1!=dist_map.end();++itr1)
                cout<<itr1->first<<" "<<itr1->second<<"\n";
            cout<<"\n\n";
            cout<<"Is final dist empty="<<final_dist.empty()<<"\n";
            */
            while(!dist_map.empty())
            {
                ITR value=findmin(dist_map);
                final_dist.insert(make_pair(value->first,value->second));

                for(int j=0;j<g->v;j++)
                {
                    if(g->adj[value->first][j]!=-1)
                    {
                        ITR temp=dist_map.find(j);
                        if(temp!=dist_map.end())
                            {

                                int temp_wt=g->adj[value->first][j]+value->second;
                                if(temp_wt<temp->second)
                                    temp->second=temp_wt;
                            }
                    }
                }
                dist_map.erase(value);
            }


            if(dest!=source)
              {
                        ITR t2=final_dist.find(dest);
                        int use=t2->second;
                        if(use==INT_MAX||use==INT_MIN||use<0)
                            cout<<"NO"<<endl;
                        else
                            cout<<use<<endl;
              }
            else
                 cout<<"0"<<endl;
            for(int fr=0;fr<g->v;fr++)
                delete g->adj[fr];
            delete g->adj;
            delete g;

        }
    return 0;
}
