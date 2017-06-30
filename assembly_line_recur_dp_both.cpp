#include <bits/stdc++.h>
using namespace std;
#define MAX 5000

int s[2],E[2],J[MAX][MAX],D[MAX][MAX],limit;
int assembly(int counter,int line)
{
	if(counter==0 && line==-1)
	{
		return min(s[0]+assembly(counter+1,0),s[1]+assembly(counter+1,1));
	}
	else if(counter==limit)
	{
		return E[line];
	}
	else
		return min(J[line][counter-1]+assembly(counter+1,line),D[line][counter-1]+assembly(counter+1,!line));
}

int dpassembly()
{
    int dp_arr[2][limit+1];
    dp_arr[0][0] = s[0];
    dp_arr[1][0] = s[1];

    for(int i=1;i<=limit;++i)
    {
        dp_arr[0][i] = min (dp_arr[0][i-1] + J[0][i-1],dp_arr[1][i-1]+D[1][i-1]);
        dp_arr[1][i] = min (dp_arr[1][i-1] + J[1][i-1],dp_arr[0][i-1]+D[0][i-1]);
    }
    return min(E[0]+dp_arr[0][limit],E[1]+dp_arr[1][limit]);
}

int main() {

	// your code goes here
	cout<<"Enter 2 start times=";
	for(int i=0;i<2;++i)
	cin>>s[i];
	cout<<"Enter number of counters=";
	cin>>limit;
	assert(limit<MAX-1);
	cout<<"Enter weights for same assembly line 1=";
	for(int i=0;i<limit-1;++i)
		cin>>J[0][i];
	cout<<"Enter weights for same assembly line 2=";
	for(int i=0;i<limit-1;++i)
		cin>>J[1][i];
	cout<<"Enter time for cross assembly transfer\n";
	for(int i=0;i<limit-1;++i)
	{
		cout<<"Enter time line 1 counter "<<i+1<<" =";
		cin>>D[0][i];
		cout<<"Enter time line 2 counter "<<i+1<<" =";
		cin>>D[1][i];
	}
	cout<<"Enter two end times=";
	for(int i=0;i<2;i++)
        cin>>E[i];
	cout<<endl<<"Final Optimal Assembly time is="<<assembly(0,-1)<<" "<<dpassembly()<<endl;
	return 0;
}
