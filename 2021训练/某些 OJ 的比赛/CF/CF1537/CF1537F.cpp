#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
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
const int N=2e5+10;
int i,j,k,n,s,t,m,flag;
int col[N],v[N],w[N];
vector<int> a[N];
void dfs(int u)
{
	for(int v:a[u])
	{
		if(col[v]!=-1)
		{
			if(col[v]==col[u])
			flag=0;
			continue;
		}
		col[v]=col[u]^1;
		dfs(v);
	}
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	{
		LL sum=0,sum2=0;
		flag=1;
		read(n),read(m);
		for(i=1;i<=n;i++)
		read(v[i]),sum+=v[i],col[i]=-1;
		for(i=1;i<=n;i++)
		read(w[i]),sum-=w[i],a[i].clear();
		for(i=1;i<=m;i++)
		{
			int x,y;
			read(x),read(y);
			a[x].push_back(y);
			a[y].push_back(x);
		}
		col[1]=0;
		dfs(1);
		for(i=1;i<=n;i++)
		{
			if(col[i])
			sum2+=w[i]-v[i];
			else
			sum2+=v[i]-w[i];
		}
		if(sum%2||(flag==1&&sum2))
		printf("NO\n");
		else
		printf("YES\n");
	}
	return 0;
}


