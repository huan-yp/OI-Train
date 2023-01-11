#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
using namespace std;
inline void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
void cmin(int &a,int b){a=min(a,b);}
void cmax(int &a,int b){a=max(a,b);}
const int N=2e5+10;
int i,j,k,n,s,t,m,flag,top;
int fr[N],to[N],now[N],st[N];
vector<int> e[N];
void dfs(int u)
{
	for(;now[u]<e[u].size();)
	{
		int v=e[u][now[u]++];
		dfs(v);
	}
	st[++top]=u;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(m);
	for(i=1;i<=m;i++)
	{
		int x,y;read(x),read(y);
		e[x].push_back(y);
		fr[x]++,to[y]++;
	}
	for(i=1;i<=n;i++)
	{
		sort(e[i].begin(),e[i].end());
		if(fr[i]==to[i])continue;
		if(abs(fr[i]-to[i])>1)flag=1;
		if(fr[i]>to[i])
		{
			if(s)flag=1;
			else s=i;
		}
		else
		{
			if(t)flag=1;
			else t=i;
		}
	}
	if(s==0)s=t=1;
	if(flag)
	{
		puts("No");
		return 0;
	}
	dfs(s);
	while(top)printf("%d ",st[top--]);
	return 0;
}

