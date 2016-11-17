#include<bits/stdc++.h>
using namespace std;

int maximum(int x, int y, int z) {
	int max = x;

	if (y > max) {
		max = y;
	}

	if (z > max) {
		max = z;
	}

	return max;
}
int main()
{
	int n;
	cin>>n;
	int **mat;
	mat=new int*[n];
	for(int i=0;i<n;i++)
		mat[i]=new int[n];
	for(int i=0;i<n;i++)
	{
		for (int j = 0; j < n; ++j)
		{
			cin>>mat[i][j];
		}

	}
	int sti=n-1;
	int stj=0;
	long long ans=0;
	ans+=mat[sti][stj];
	int level=0;
	while(level++<n)
	{
		int t1=0;
		int t2=0;
		int t3=0;
		//int max1=0;
		if(sti-1>=0)
			t1=mat[sti-1][stj];
		if(sti-1>=0&&stj+1<n)
			t2=mat[sti-1][stj+1];
		if(sti-1>=0&&stj-1>=0)
			t3=mat[sti-1][stj-1];
		int max1=maximum(t1,t2,t3);
		if(max1==t1)
		{
            sti=sti-1;
		}
		else if(max1==t2)
		{
            sti=sti-1;
            stj=stj+1;
		}
		else
		{
            sti-=1;
            stj-=1;
		}
	//	cout<<"This is max-"<<max1<<"\n";
		ans+=max1;

	}
	cout<<ans;
	return 0;
}
