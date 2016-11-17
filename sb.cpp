#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
        {
            int q;
            cin>>q;
            vector<int> x(q);
            vector<int> y(q);
            bool dot=true;
            forint j=0;j<q;j++)
                cin>>x[j]>>y[j];
        int var_x1=0,var_x2=0,var_y1=0,var_y2=0;
        bool bvar_x1=false,bvar_x2=false,bvar_y1=false,bvar_y2=false;
        for(int j=0;j<q;j++)
                {
                 if(!bvar_x1)
                     {
                    var_x1=x[j];
                    bvar_x1=true;
                    continue;
                     }
                if(!bvar_x2)
                     {
                       var_x2=x[j];
                       bvar_x2=true;
                       continue;
                    }
           if((x[j]!=var_x1)&&(x[j]!=var_x2))
               {
               dot=false;
                   break;
                   }
                 }
        if(dot)
            cout<<"YES";
        else
            cout<<"NO";
    }

    return 0;
}
