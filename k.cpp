#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    int test;
    string s;
    cin>>test;
    while(test--)
    {
        cin>>s;
        for(int i=0; i<s.size()/2; i++)
        {
            if(s[i]=='.')
            {
                if(s[i]==s[s.size()-1-i])
                {
                    s[i]='a';
                    s[s.size()-1-i]='a';
                }
            }
        }
        if(s.size()%2) if(s[s.size()/2]=='.')s[s.size()/2]='a';
        //cout<<"s = "<<s<<endl;


        for(int i=0; i<s.size()/2; i++)//left string checking
        {
            if(s[i]=='.')
            {
                s[i]=s[s.size()-1-i];
            }
            if(s[s.size()-1-i]=='.')
            {
                s[s.size()-1-i]=s[i];
            }
        }

/*        for(int i=s.size()-1,k=0; i>s.size()/2; i--,k++)//Right string checking
        {
            if(s[i]=='.')
            {
                s[i]=s[k];
            }
        }*/


        //cout<<" ss = "<<s<<endl;

        bool flag=true;
        for(int i=0; i<s.size()/2; i++)
        {
            if(s[i]!=s[s.size()-1-i])
            {
                flag=false;
                break;
            }
        }

        if(flag==false) cout<<"-1"<<endl;
        else cout<<s<<endl;

    }
}
