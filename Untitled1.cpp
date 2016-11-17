#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void print(vector<long int> a1[],long int start,long int n)
{
    cout<<a1[start];
    long int present=start+1;
    while(present!=start)
    {
        cout<<a1[present];
        present=((present+1)%(n-1));
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long int n,k;
    vector<long int> a(n);
    cin>>n;
    cin>>k;
    for(long int i=0;i<n;i++)
         cin>>a[i];
cout<<"s"<<"n="<<n<<"k="<<k;
    print(a,k,n);

    return 0;
}

