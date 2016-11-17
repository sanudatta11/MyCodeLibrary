#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long int n;
    cin>>n;
    string sample;
    vector<string> a(n);
    for(int i=0;i<n;i++)
           { cin>>a[i];
           }
    long int q;
    cin>>q;
    int coun=0;
    vector<int> answers(q);
    vector<string> query(q);
    for(int i=0;i<q;i++)
           { cin>>query[i];
           }
    for(int i=0;i<q;i++)
        {
        answers[i]=0;
        for(int j=0;j<n;j++)
       // coun=instring(a[j],query[i]);
         if (find(a[j].begin(), a[j].end(), query[i]) != a[j].end())
            {
                coun=1;
            }
        if(coun)
            {
            answers[i]++;
        }
    }
    for(int i=0;i<q;i++)
        cout<<answers[i]<<"\n";

    return 0;
}
