#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

long long ans=-1;
bool done(vector<long long> &vec)
{
    vector<long long>::iterator itr=vec.begin();
    int count1=0;
    int index1=-1;
    for(;itr!=vec.end();++itr)
    {
        if(*itr!=0)
         {  index1=itr-vec.begin()+1;
            count1++;
         }
    }
    if(count1==1)
     {   ans=index1;
        return true;
    }
    else
        return false;

}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        ll num=0;
        ll use_max=0;
        vector<long long> vec;
        cin>>num>>use_max;
        for(int i=0;i<num;i++)
        {
            ll temp;
            cin>>temp;
            vec.push_back(temp);
        }
        vector<long long>::iterator itr=vec.begin();
        while(!done(vec))
        {
            if((*itr-use_max)>0)
                *itr=(*itr-use_max);
            else
                *itr=0;
            ++itr;
            if(itr==vec.end())
                itr=vec.begin();
        }
        cout<<ans<<"\n";
        ans=0;

    }
}
