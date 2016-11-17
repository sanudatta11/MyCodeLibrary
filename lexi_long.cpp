#include<iostream>
#include<vector>
#include<iterator>
#include<stdlib.h>
#include<cstdio>
#include<string>

using namespace std;
string def="-1";
int main()
{
    int t;
    cin>>t;
    vector<string> out(t);
    for(int i=0;i<t;i++)
    {
        string inp;
        cin>>inp;
        if(inp.size()%2)
        {
            int counter=inp.size()/2;
            int counter_back=counter-1;
            int counter_front=counter+1;
            if(inp[counter]=='.')
            inp[counter]='a';
            int not_fa=0;
            while(counter_back>=0&&counter_front<inp.size())
            {
                if(inp[counter_back]==inp[counter_front])
                  {counter_back--;counter_front++;}
                else if(inp[counter_back]=='.'&&inp[counter_front=='.']){
                inp[counter_back]=inp[counter_front]='a';
                counter_back--;counter_front++;
                }
                else if(inp[counter_back]=='.'){
                inp[counter_back]=inp[counter_front];
                counter_back--;counter_front++;
                }
                else if(inp[counter_front]=='.'){
                inp[counter_front]=inp[counter_back];
                counter_back--;counter_front++;
                }
                else{
                    not_fa=1;
                    break;
                }
            }
            if(not_fa)
                out.push_back(def);
            else
                out.push_back(inp);
        }
        else{
            //cout<<inp.size();
            int counter_front=(inp.size())/2;
            //cout<<counter_front;
            int counter_back=counter_front-1;
            //cout<<counter_back;
            //int counter_front=counter+1;
            int not_fa=0;
            while(counter_back>=0&&counter_front<inp.size())
            {
                if(inp[counter_back]==inp[counter_front])
                  {counter_back--;counter_front++;}
                else if(inp[counter_back]=='.'&&inp[counter_front=='.']){
                inp[counter_back]=inp[counter_front]='a';
                counter_back--;counter_front++;
                }
                else if(inp[counter_back]=='.'){
                inp[counter_back]=inp[counter_front];
                counter_back--;counter_front++;
                }
                else if(inp[counter_front]=='.'){
                inp[counter_front]=inp[counter_back];
                counter_back--;counter_front++;
                }
                else{
                    not_fa=1;
                    break;
                }
            }
            if(not_fa)
                out.push_back(def);
            else
                out.push_back(inp);

        }
    }
    vector<string>::iterator itr;
    for(itr=out.begin();itr!=out.end();itr++)
        {

        cout<<*itr<<endl;

        }

    return 0;
}
