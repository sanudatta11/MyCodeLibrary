#include<bits/stdc++.h>
using namespace std;
//int mat[][5]={{1,2,9,10,25},{4,3,8,11,24},{5,6,7,12,23},{16,15,14,13,22},{17,18,19,20,21}};

typedef vector<long long> VECT;
typedef vector<long long>::iterator ITR;
#define MOD 1000000007

ITR doit(VECT &vec)
{
    ITR temp=vec.end();
    ITR it1=vec.begin();
    long long minm=INT_MAX;
    for(;it1!=vec.end();++it1)
        if(*it1%2)
            if(minm>*it1)
                {
                    minm=*it1;
                    temp=it1;
                }
    return temp;

}

int main()
{

        long long n;
        cin>>n;
        VECT vec;
        for(long long k=0;k<n;k++)
        {
         long long temp;
         cin>>temp;
         vec.push_back(temp);
        }
        sort(vec.begin(),vec.end(),greater<long long>());
        while(1){
        long long sum=accumulate(vec.begin(),vec.end(),0);
        sum%=MOD;
        if(!((sum)%2))
           { cout<<sum<<"\n";break;}
        else
            {
                ITR temp=doit(vec);
                vec.erase(temp);
            }
        }

}
