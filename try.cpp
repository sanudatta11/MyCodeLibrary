#include<bits/stdc++.h>
using namespace std;
int *cost;
//int counter=0;
int optimal(int n)
{
    if(!n)
        return 0;
    if(n==1)
        return cost[0];
    int q=INT_MIN;
   // cout<<counter++<<"\n";
    for(int i=1;i<=n;i++)
        q=max(q,cost[i]+optimal(n-i));
    return q;
}
int main()
{

    int length=0;
    cout<<"Enter the length of the rod that is to be cut";
    cin>>length;
    cost=new int[length+1];
    cost[0]=INT_MIN;
    for(int i=1;i<=length;i++)
    {
        cout<<"Enter the cost of "<<i<<" length=";
        cin>>cost[i];
    }
    int ans=optimal(length);
    cout<<"The answer is="<<ans<<"\n";
    delete cost;
    return 0;
}
