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
int i,j,k,n,s,t,m,flag=1,ans;
const int N=2e5+10,mod=1e9+7;
int fa[N],e[N][3],col[N],p[N],type[N];
int find(int x)
{
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
} 
void merge(int u,int v)
{
	u=find(u),v=find(v);
	if(v>u)swap(u,v);
	if(u==v)return;
	fa[u]=v;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	memset(type,-1,sizeof(type));
	read(n),read(m);
	for(i=1;i<=n;i++)
	fa[i]=i,fa[i+n]=i+n;
	for(i=1;i<=m;i++)
	{
		read(e[i][1]),read(e[i][2]),read(col[i]);
		if(e[i][1]>e[i][2])swap(e[i][1],e[i][2]);
		if(e[i][1]==1)
		{
			type[e[i][2]]=col[i];
			continue;
		}
		if(col[i]==1)
		merge(e[i][1],e[i][2]),merge(e[i][1]+n,e[i][2]+n);
		else
		merge(e[i][1],e[i][2]+n),merge(e[i][1]+n,e[i][2]);
	}	
	for(i=1;i<=n;i++)
	{
		if(type[i]==-1)continue;
		if(type[find(i+n)]==-1)type[find(i+n)]=type[i]^1;
		if(type[find(i+n)]==type[i])flag=0;
		if(type[find(i)]==-1)type[find(i)]=type[i];
		if(type[find(i)]!=type[i])flag=0;
	}
	for(i=1;i<=n;i++)
	{
		if(find(i)==find(i+n))
		flag=0;
	}
	for(i=2;i<=n;i++)
	{
		if(find(i)!=i)continue;
		ans++;
		if(type[find(i+n)]!=-1||type[i]!=-1)
		ans--;
		type[i]=1;
	}
	if(flag==0)
	{
		printf("0\n");
		return 0;
	}
	int now=1;
	for(i=1;i<=ans;i++)
	now=now*2%mod;
	cout<<now<<endl;
	return 0;
}


