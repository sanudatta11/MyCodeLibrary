/*
    Fenwick Tree Implementation
*/

#include<bits/stdc++.h>
using namespace std;

int getsum(int* BIT,int range)
{
    int sum=0;
    range++;
    while(range>0)
    {
        sum+=BIT[range];
        range-=(range&(-range));
    }
    return sum;
}

void update(int btree[],int n,int index,int val)
{
    index++;

    while(index<=n)
    {
        btree[index]+=val;
        index+=(index&(-index));
    }

}

int* constructbit(int arr[],int n)
{
    int *BIT = new int[n+1];

    for(int i=0;i<n;++i)
        BIT[i] = 0;

    for(int i=0;i<n;++i)
        update(BIT,n,i,arr[i]);

    return BIT;
}

int main()
{
    cout<<"Make it minimum 10 elements\n";
    cout<<"Enter number of elements you wanna enter=\n";
    int n;
    cin>>n;
    int arr[n];
    cout<<"Enter it=\n";
    for(int i=0;i<n;++i)
        cin>>arr[i];
    int *BIT = constructbit(arr,n);

    cout<<"The sum of first 4 elements="<<getsum(BIT,3)<<endl;
    cout<<"The sum of range 3 to 7 is="<<getsum(BIT,7)-(getsum(BIT,2))<<endl;
    return 0;
}
