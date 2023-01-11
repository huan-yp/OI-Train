#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
#define size siz
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
const int N=1e6+10,mod=998244353;
int i,j,k,n,s,t,m;
int fa[N],cnt[N],size[N];
int find(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	x=find(x),y=find(y);
	if(x==y)return ;
	fa[x]=y;size[y]+=size[x];
}
int quick(int a,int s)
{
	int ret=1;
	while(s)
	{
		if(s&1)ret=1ll*ret*a%mod;
		a=1ll*a*a%mod;
		s>>=1;
	}
	return ret;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(m);
	for(i=1;i<=n;i++)
	{
		fa[i]=i;
		size[i]=1;
	}
	for(i=1;i<=m;i++)
	{
		int x,y;read(x),read(y);
		cnt[x]++;
		merge(x,y);
	}
	
	int flag=0,ans=0;
	for(i=1;i<=n;i++)
	if(find(i)!=i)
	cnt[find(i)]+=cnt[i];
	for(i=1;i<=n;i++)
	if(size[find(i)]!=cnt[find(i)])
	flag=1;
	if(flag)
	{
		puts("0");
		return 0;
	}
	for(i=1;i<=n;i++)
	if(find(i)==i)ans++;
	cout<<quick(2,ans);
	return 0;
}

