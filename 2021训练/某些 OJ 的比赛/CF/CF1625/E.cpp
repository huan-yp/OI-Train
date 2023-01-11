#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
#define size sz
#define low(x) (x)&(-x)
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
const int N=3e5+10;
int i,j,k,n,s,t=1,m,top,q,all;
int st[N],rb[N],lb[N],fa[N],son[N],dfn[N],c[2][N],size[N];
char ch[N];
vector<int> e[N];
int quert(int x,int op,int ret=1)
{
	for(;x>=1;x-=low(x))ret+=c[op][x];
	return ret;
}
void updata(int x,int op,int cc)
{
	for(;x<=n;x+=low(x))c[op][x]+=cc;
}
void dfs(int u)
{
	dfn[u]=++s;size[u]=1;
	if(u!=1)updata(dfn[u],1,1),updata(fa[dfn[u]],1,-1);
	for(int v:e[u])
	{
		if(fa[u]==v)continue;
		dfs(v);size[u]+=size[v];
		son[u]++;updata(dfn[u],0,son[u]);
	}
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(q);
	scanf("%s",ch+1);int now=1;
	for(i=1;i<=n;i++)
	{
		if(ch[i]=='(')st[++top]=i,e[now].push_back(lb[i]=++t),fa[t]=now,now=t;
		else 
		{
			if(top)rb[i]=lb[st[top--]],now=fa[now];
			else continue;
		}
	}
	dfs(1);
	for(i=1;i<=q;i++)
	{
		int op,l,r;
		read(op),read(l),read(r);
		if(op==1)
		{
			int x=lb[l];
			updata(dfn[fa[x]],0,-(son[fa[x]]));son[fa[x]]--;	
			updata(dfn[x],1,-1);updata(dfn[fa[x]],1,1);
		}
		else	
		{
//			if(rb[r]<lb[l])printf("boom");
			top=quert(dfn[rb[r]]+size[rb[r]]-1,1)-quert(dfn[lb[l]]-1,1);
			all=quert(dfn[rb[r]]+size[rb[r]]-1,0)-quert(dfn[lb[l]]-1,0);
			printf("%lld\n",all+top*(top+1)/2);
		}
	}
	return 0;
}

