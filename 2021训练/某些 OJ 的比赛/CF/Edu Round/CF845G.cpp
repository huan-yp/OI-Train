#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
using namespace std;
inline void read(int &x)
{
	x=0;int f=1;
	char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}
	x*=f;
}
const int N=1e5+10;
int i,j,k,n,s,t,m;
int p[N],val[N];
struct edge{
	int v,val;
};
vector<edge> a[N];
void add(int x)
{
	for(i=30;i>=0;i--)
	{
		if(x&(1<<i))
		{
			if(p[i]==0)
			p[i]=x;
			x^=p[i];
		}
	}
}
void dfs(int u,int now)
{
	val[u]=now;
	for(edge tmp:a[u])
	{
		int v=tmp.v;
		if(val[v]!=-1)
		{
			add(val[u]^val[v]^tmp.val);
			continue;
		}
		dfs(v,now^tmp.val);
	}
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	memset(val,-1,sizeof(val));
	read(n),read(m);
	for(i=1;i<=m;i++)
	{
		int x,y,z;
		read(x),read(y),read(z);
		a[x].push_back((edge){y,z});
		a[y].push_back((edge){x,z});
	}	
	dfs(1,0);
	int ans=val[n];
	for(i=30;i>=0;i--)
	if(ans&(1<<i))
	ans^=p[i];
	
	cout<<ans;
	return 0;
}

