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
int n,id[200001],p[200001],f[200001];
double ans;
signed main()
{
	fileio("tree");
	n=read();
	for(int i=1;i<=n;i++)
		id[read()]=i;
	for(int i=1;i<=n;i++)
		p[i]=id[read()];
	for(int i=1;i<=n;i++)
		id[p[i]]=i;
	for(int i=1;i<n;i++)
		if(id[i]+1<id[i+1])
		{
			f[id[i]+1]++;
			f[id[i+1]+1]--;
		}
	for(int i=3;i<=n;i++)
	{
		f[i]+=f[i-1];
		if(p[i-1]>p[i])
			ans+=1.0;
		elif(!f[i])
			ans+=0.5;
	}
	printf("%.10f\n", ans+2.0);
	return 0;
}