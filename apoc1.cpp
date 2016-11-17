#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> vec;
    for(int i=0;i<n;i++)
    {
    	int temp=0;
    	cin>>temp;
    	vec.push_back(temp);
    }
    sort(vec.begin(),vec.end());
   // for(int i=0;i<n;i++)
    //    cout<<vec[i]<<"\n";
    vector<int>::iterator itr=vec.begin();
    int lower=*vec.begin();
    int upper=*(vec.end()-1);
    bool doing=true;
    for(;itr!=vec.end();++itr)
    {
    	if(*itr!=lower)
    	{	doing=false;
    		break;
    	}
    	//cout<<doing<<"\n";
    	lower++;
    }
    if(doing)
    	cout<<"YES\n";
   	else
   		cout<<"NO\n";
    return 0;
}
