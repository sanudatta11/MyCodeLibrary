#include <iostream>
#include<string>
using namespace std;

int main()
{
    int t;
    cin>>t;
    //vector<string> a;
    for(int i=0;i<t;i++)
    {
    	int d=1;
    	string s;
    	cin>>s;
    	int n=s.size();
    	for(int j=0;j<n-1;j++)
    	{
    		int k=s[j];
    		int l=s[j+1];
    		if(!((k-l)==1||(l-k)==1))
    		{
    			cout<<"NO\n";
    			d=0;
    			break;
    		}

    	}
    	if(d)
    	cout<<"YES\n";
    }
    return 0;
}
