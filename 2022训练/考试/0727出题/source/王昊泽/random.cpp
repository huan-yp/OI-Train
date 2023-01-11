#include<bits/stdc++.h>
using namespace std;
long long n,m,ft[101010],a[101010];
vector<pair<long long,long long> >v;
bool vis[101010];
int main()
{
	freopen("random.in","r",stdin);
	freopen("random.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		vis[i]=1;
	}
	for(long long i=2;i*i<=m;i++)
	{
		if(m%i!=0)
		{
			continue;
		}
		int cnt=0;
		while(m%i==0)
		{
			m/=i;
			cnt++;
		}
		v.push_back(make_pair(i,cnt));
	}
	if(m>1)
	{
		v.push_back(make_pair(m,1));
	}
	for(int i=0;i<v.size();i++)
	{
		a[0]=0;
		for(int j=1;j<=n;j++)
		{
			if(j%v[i].first==0)
			{
				a[j]=a[j/v[i].first]+1;
			}
			else
			{
				a[j]=0;
			}
		}
		ft[0]=0;
		for(int j=1;j<=n;j++)
		{
			ft[j]=ft[j-1]+a[j];
		}
		for(int j=1;j<=n;j++)
		{
			if((ft[n-1]-ft[j-1]-ft[n-j])<v[i].second)
			{
				vis[j]=0;
			}
		}
	}
	vector<int>ans;
	for(int i=1;i<=n;i++)
	{
		if(vis[i])
		{
			ans.push_back(i);
		}
	}
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<' ';
	}
	cout<<endl;
	return 0;
}
