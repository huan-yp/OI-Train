#include<bits/stdc++.h>
#define y1 y3647
#define next nxt
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
const int N=505,M=N*N;
int i,j,k,n,s,t,m;
int fa[M],p[N][N],rk[N][N];
int a[N][N];
int find(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void merge(int u,int v)
{
	u=find(u),v=find(v);
	if(u==v)return;
	fa[u]=v;
} 
int check(int x)
{
	int pd=0;
	for(i=1;i<=n*m;i++)
	fa[i]=i;
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	{
		if(i!=1&&abs(a[i][j]-a[i-1][j])<=x)
		merge(rk[i][j],rk[i-1][j]);
		if(i!=n&&abs(a[i][j]-a[i+1][j])<=x)
		merge(rk[i][j],rk[i+1][j]);
		if(j!=1&&abs(a[i][j]-a[i][j-1])<=x)
		merge(rk[i][j],rk[i][j-1]); 
		if(j!=m&&abs(a[i][j]-a[i][j+1])<=x) 
		merge(rk[i][j],rk[i][j+1]);
	}
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	{
		if(p[i][j]==0)continue;
		if(pd==0)
		pd=find(rk[i][j]);
		if(find(rk[i][j])!=pd)
		return 0;
	}
	return 1;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(m);
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	read(a[i][j]),rk[i][j]=++t;
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	read(p[i][j]);
	int l=0,r=1e9,ans;
	while(r>=l)
	{
		int mid=(l+r)/2;
		if(check(mid))
		r=mid-1,ans=mid;
		else
		l=mid+1;
	}
	cout<<ans;
	return 0;
}


