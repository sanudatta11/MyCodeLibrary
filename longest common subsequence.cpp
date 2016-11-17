#include<bits/stdc++.h>
using namespace std;
deque<char> ans;
void find_seq(char *s1,char *s2,int n,int m)
{
	int **mat=new int*[n+1];
	for(int i=0;i<n+1;i++)
		mat[i]=new int[m+1];
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<m+1;j++)
		{
			if(i==0||j==0)
				mat[i][j]=0;
			else if(s1[i-1]==s2[j-1])
				mat[i][j]=mat[i-1][j-1]+1;
			else 
				mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
		}
	}
	/*
	return mat[n][m]; 			Uncomment for returning the maxmium subseuence count
	*/
	int ti=n,tj=m;
	while(1)
	{
		if(mat[ti][tj]==mat[ti-1][tj-1]+1)
		{	
			ans.push_front(mat[ti][tj]);
			ti--;tj--;
		}
		else if(mat[ti][tj]==mat[ti-1][tj])
			ti--;
		else
			tj--;
		if(!ti||!tj)
			break;
	}

}


int main()
{

}