#include<bits/stdc++.h>
#define y1 y3647
#define next nxt
#define LL long long
using namespace std;
inline void read(int &x)
{
	scanf("%d",&x);
}
const int N=4e5+10,mod=1e9+7;
int i,j,k,n,s,t,m;
int a[N],p[N],pos[N],b[N];
void solve()
{
	int ans=1;
	read(n);
	for(i=1;i<=n;i++)p[i]=0;
	for(i=1;i<=n;++i)read(a[i]);
	for(i=1;i<=n;i++)pos[a[i]]=i;
	for(i=1;i<=n;++i)read(b[i]);
	for(i=1;i<=n;i++)
	{
		if(p[i])continue;
		int now=i;
		while(p[now]==0)
		{
			p[now]=1;
			now=pos[b[now]];
		}
		p[now]=1;
		ans=1ll*ans*2%mod;
	}
	cout<<ans<<endl;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	solve();
	return 0;
}


