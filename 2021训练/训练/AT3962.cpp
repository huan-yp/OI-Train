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
const int N=305;
int i,j,k,n,s,t,m,mod;
int f[N][N],g[N][N],c[N][N];
void Inc(int &x,const int &y){x+=y;if(x>=mod)x-=mod;}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(k),read(mod);
	c[0][0]=1;
	for(i=1;i<=n;i++)
	{
		c[i][0]=1;
		for(j=1;j<=n;j++)
		c[i][j]=c[i-1][j],Inc(c[i][j],c[i-1][j-1]);
	}
	for(i=1;i<=k;i++)f[0][i]=1;
	for(i=1;i<=n;i++)
	for(int p=1;p<=i;p++)
	for(t=i-p+1;t<=i;t++)
	Inc(g[i][p],c[t-1][i-p]);
	
	for(i=1;i<=n;i++)
	{
		f[i][1]=1;
		for(j=2;j<=k;j++)
		{
			f[i][j]=f[i][j-1];
			for(int p=1;p<=i;p++)
			Inc(f[i][j],1ll*f[p-1][j-1]*f[i-p][j]%mod*g[i][p]%mod);
		}
	}
	cout<<f[n][k]<<endl;
	return 0;
}

