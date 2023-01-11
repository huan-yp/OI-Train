#include<bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &x)
{
	x=0;T f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-')f=-1;
	for(;isdigit(c);c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	x*=f;
}
template <typename T,typename ...Args>void read(T &x,Args&...args){read(x),read(args...);}
template <typename T> void print(T x)
{
	if(x<0) x=-x,putchar('-');
	if(x>9) print(x/10);
	putchar(x%10+48);
}
template <typename T> void print(T x,char c){print(x); putchar(c);}
const int N=157,M=507;
int n,m,sum[N][M],f[2][M][N][N],g[M][N][N],h[N][N];
void work1()//N 的转移
{
	memset(f,~0x3f,sizeof f);
	memset(g,~0x3f,sizeof g);
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			f[0][0][i][j]=0;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			for(int k=j;k<=n;k++)
				f[0][i][j][k]=max(f[0][i-1][j][k],0)+sum[k][i]-sum[j-1][i];
	for(int i=2;i<=m;i++)
		for(int j=1;j<=n;j++)
			for(int k=n-1;k>=j;k--)
				g[i][j][k]=max(g[i][j][k+1],f[0][i-1][j][k+1]);
	for(int i=1;i<=m;i++)
	{
		memset(h,~0x3f,sizeof h);
		for(int k=n;k>=1;k--)
			for(int j=1;j<=k;j++)
				h[j][k]=max(h[j-1][k],f[1][i-1][j][k]);
		for(int j=1;j<=n;j++)
		{
			int tmp=h[j-1][j-1];
			for(int k=j;k<=n;k++)
				tmp=max(tmp,h[j][k]),
				f[1][i][j][k]=max(g[i][j][k],tmp)+sum[k][i]-sum[j-1][i];
		}
	}
}
void work2()
{
	memset(f[0],~0x3f,sizeof f[0]);
	memset(g,~0x3f,sizeof g);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			for(int k=j-1;k>=1;k--)
				g[i][k][j]=max(g[i][k+1][j],f[1][i-1][k+1][j]);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			for(int k=j;k<=n;k++)
				f[0][i][j][k]=max(g[i][j][k],f[0][i-1][j][k])+sum[k][i]-sum[j-1][i];
	memset(f[1],~0x3f,sizeof f[1]);
	int tmp=f[0][0][0][0];
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
			for(int k=j+2;k<=n;k++)
				f[1][i][j][k]=tmp+sum[k][i]-sum[j-1][i];
		for(int j=1;j<=n;j++)
			for(int k=j;k<=n;k++)
				tmp=max(tmp,f[0][i-1][j][k]);
	}
}
void work3()
{
	memset(f[0],~0x3f,sizeof f[0]);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			for(int k=j+2;k<=n;k++)
				f[0][i][j][k]=max(f[0][i-1][j][k],f[1][i-1][j][k])+sum[k][i]-sum[j-1][i]-sum[k-1][i]+sum[j][i];
	memset(f[1],~0x3f,sizeof f[1]);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			for(int k=j+2;k<=n;k++)
				f[1][i][j][k]=f[0][i-1][j][k]+sum[k][i]-sum[j-1][i];
	memset(f[0],~0x3f,sizeof f[0]);
	int tmp=f[0][0][0][0];
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
			for(int k=j+2;k<=n;k++)
				f[0][i][j][k]=max(tmp,f[0][i-1][j][k])+sum[k][i]-sum[j-1][i]-sum[k-1][i]+sum[j][i];
		for(int j=1;j<=n;j++)
			for(int k=j;k<=n;k++)
				tmp=max(tmp,f[1][i-1][j][k]);
	}
	memset(f[1],~0x3f,sizeof f[1]);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			for(int k=j+2;k<=n;k++)
				f[1][i][j][k]=max(f[1][i-1][j][k],f[0][i-1][j][k])+sum[k][i]-sum[j-1][i];
}
int main()
{
	freopen("NOI.in","r",stdin);
	freopen("NOI.out","w",stdout);
	read(n,m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			read(sum[i][j]),sum[i][j]+=sum[i-1][j];
	work1(); work2(); work3();
	memset(f[0],~0x3f,sizeof f[0]);
	int ans=f[0][0][0][0];
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			for(int k=j+2;k<=n;k++)
			{
				f[0][i][j][k]=max(f[0][i-1][j][k],f[1][i-1][j][k])+sum[k][i]-sum[j-1][i]-sum[k-1][i]+sum[j][i];
				ans=max(ans,f[0][i][j][k]);
			}
	print(ans,'\n');
	return 0;
}
