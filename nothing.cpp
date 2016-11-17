#include<iostream>
#include<vector>
using namespace std;
/*LRDU-L-Left,R-Right,D-Down,U-UP*/
int main()
{
    string inp;
    cin>>inp;
    long int x=0,y=0;
    for(int i=0;i<inp.size();i++)
    {
    if(inp[i]=='L')
        x--;
    else if(inp[i]=='R')
        x++;
    else if(inp[i]=='D')
        y--;
    else if(inp[i]=='U')
        y++;

    }
    cout<<x<<" "<<y;
    return 0;
}

(a>b)?((a>c)?a,c),((b>c)?b,c)
