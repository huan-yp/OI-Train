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
const int N=1e6+10;
int i,j,k,n,s,t,m,now=INF,last=0;
int val[N];
vector<int> a[N];
void dfs(int u)
{
	for(int v:a[u])
	{
		if(val[v])continue;
		val[v]=min(v,val[u]);
		dfs(v);
	}
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(m);
	for(i=1;i<n;i++)
	{
		int x,y;
		read(x),read(y);
		a[x].push_back(y);
		a[y].push_back(x);
	} 
	read(t),read(t);
	t=t%n+1;
	val[t]=t;
	dfs(t);
	for(i=2;i<=m;i++)
	{
		int op,x;
		read(op),read(x);
		x=(last+x)%n+1;
		if(op==1)
		now=min(now,val[x]);
		else
		printf("%d\n",last=min(now,val[x]));
	}
	return 0;
}


