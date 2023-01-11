#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int i,j,n,t,m,ans;
string str[N];
set<int> st[N];
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>m;ans=0;
		for(i=1;i<=n;i++)
		{
			cin>>str[i];
			for(j=1;j<=m;j++)
			if(str[i][j-1]=='1')st[i+j].insert(i);
		}
		for(i=1;i<=n+m;i++)
		{
			if(st[i+1].size()==0)continue;
			int pos=i;ans++;
			for(j=1;j<=n;j++)
			{
				st[j+pos].erase(j);
				if(st[j+pos].rbegin()!=st[j+pos].rend()&&*st[j+pos].rbegin()>j)pos--;
				else pos++;
			}
		}
		cout<<ans<<endl;
	}
}

