#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
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
void cmin(int &a,int b){a=min(a,b);}
void cmax(int &a,int b){a=max(a,b);}
const int N=5005;
int i,j,k,n,s,t,m,ans,v;
int dis[N],x[N],y[N],mp[N][N],pd[N];
void prime()
{
	dis[0]=1e18;
	for(i=1;i<=n;i++)
	dis[i]=mp[0][i];
	
	for(i=1;i<=n;i++)
	{
		int cho=0;
		for(j=1;j<=n;j++)
		if(dis[j]<dis[cho]&&pd[j]==0)
		cho=j;
		
		pd[cho]=1;ans+=dis[cho];
		for(j=1;j<=n;j++)
		cmin(dis[j],mp[cho][j]);
	}
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(v);
	for(i=1;i<=n;i++)
	{
		read(x[i]),read(y[i]);
		mp[0][i]=mp[i][0]=v;	
	}
	for(i=1;i<=n;i++)
	for(j=i+1;j<=n;j++)
	mp[i][j]=mp[j][i]=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
	
	prime();
	cout<<ans<<endl;
	return 0;
}

