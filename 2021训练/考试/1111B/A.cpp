#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
#define low(x) ((x)&(-x))
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
const int N=55,T=20;
int i,j,k,n,s,t,m,ans;
int f[1<<T],sum[1<<T],a[N],fa[1<<T][N];
int find(int x,int op)
{
	if(fa[op][x]==x)return x;
	return fa[op][x]=find(fa[op][x],op);
}
void merge(int mask,int u,int v)
{
	u=find(u,mask),v=find(v,mask);
	if(u==v)return ;
	fa[mask][u]=v;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n);s=-1;
	for(i=1;i<=n;i++)
	read(a[i]),s&=a[i],fa[0][i]=i;
	for(i=1;i<=n;i++)a[i]^=s;
	
	ans=(1ll<<n)-2;
	for(int mask=1;mask<1<<T;mask++)
	{
		sum[mask]=sum[mask-low(mask)]+1;
		int lst=0,cnt=0,frommask=mask-low(mask);
		for(i=1;i<=n;i++)fa[mask][i]=fa[frommask][i];
		for(i=1;i<=n;i++)
		{
			if((low(mask)&a[i]))continue;
			if(lst)merge(mask,lst,i);
			lst=i;
		}
		for(i=1;i<=n;i++)if(find(i,mask)==i)cnt++;
		
		f[mask]=(1ll<<cnt)-2;
		if(sum[mask]%2)ans-=f[mask];
		else ans+=f[mask];
	}
	cout<<ans<<endl;
	return 0;
}

