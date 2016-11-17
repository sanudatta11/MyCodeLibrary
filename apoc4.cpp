#include<bits/stdc++.h>
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        vector<int> vec;
        for(int k=0;k<n;k++)
        {
            int temp;
            cin>>temp;
            while(temp)
            {
                int t1=temp%10;
                vec.push_back(t1);
                temp/=10;
            }
        }
        sort(vec.begin(),vec.end(),greater<int>());
        vector<int>::iterator itr=vec.begin();
        for(;itr!=vec.end();++itr)
            cout<<*itr;
        cout<<"\n";
        vec.clear();
    }
}

