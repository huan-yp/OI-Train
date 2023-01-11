#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
const int INF=4e18;
inline int read()
{
	int x=0;
	bool flag=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			flag=0;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return (flag?x:~(x-1));
}
int n,m,num[20],lim[20];
std::vector<int> v,ans;
signed main()
{
	fileio("random");
	n=read();
	m=read();
	if(m==1)
		ans.push_back(1);
	for(int i=2;i*i<=m;i++)
		if(m%i==0)
		{
			while(m%i==0)
			{
				lim[v.size()]++;
				m/=i;
			}
			v.push_back(i);
		}
	if(m!=1)
	{
		lim[v.size()]++;
		v.push_back(m);
	}
	for(int i=n-1;i;i--)//*i/(n-i)
	{
		int x=i;
		for(int l=0;l<v.size();l++)
			while(x%v[l]==0)
			{
				num[l]++;
				x/=v[l];
			}
		x=n-i;
		for(int l=0;l<v.size();l++)
			while(x%v[l]==0)
			{
				num[l]--;
				x/=v[l];
			}
		bool ok=1;
		for(int l=0;l<v.size();l++)
			if(lim[l]>num[l])
			{
				ok=0;
				break;
			}
		if(ok)
			ans.push_back(n-i+1);
	}
	cout<<ans.size()<<'\n';
	for(int i:ans)
		cout<<i<<" ";
	return 0;
}