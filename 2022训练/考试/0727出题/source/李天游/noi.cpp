#include<bits/stdc++.h>
using namespace std;
const int N=160,M=510;
int n,m,s[N][M];
int f[2][M][N][N],g[M][N][N],h[N][N];
void work1()
{
	memset(f,~0x3f,sizeof(f)),memset(g,~0x3f,sizeof(g));
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			f[0][0][i][j]=0;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			for(int k=j;k<=n;k++)
				f[0][i][j][k]=max(f[0][i-1][j][k],0)+s[k][i]-s[k][i-1]-s[j-1][i]+s[j-1][i-1];
	for(int i=2;i<=m;i++)
		for(int j=1;j<=n;j++)
			for(int k=n-1;k>=j;k--)
				g[i][j][k]=max(g[i][j][k+1],f[0][i-1][j][k+1]);
	for(int i=1;i<=m;i++)
	{
		memset(h,~0x3f,sizeof(h));
        for(int k=n;k>=1;k--)
			for(int j=1;j<=k;j++)
				h[j][k]=max(h[j-1][k],f[1][i-1][j][k]);
        for(int j=1;j<=n;j++)
        {
            int mx=h[j-1][j-1];
            for(int k=j;k<=n;k++)
                mx=max(mx,h[j][k]),f[1][i][j][k]=max(g[i][j][k],mx)+s[k][i]-s[k][i-1]-s[j-1][i]+s[j-1][i-1];
        }
	}
}
void work2()
{
	memset(f[0],~0x3f,sizeof(f[0]));memset(g,~0x3f,sizeof(g));
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            for(int k=j-1;k>=1;k--)
                g[i][k][j]=max(g[i][k+1][j],f[1][i-1][k+1][j]);
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            for(int k=j;k<=n;k++)
                f[0][i][j][k]=max(g[i][j][k],f[0][i-1][j][k])+s[k][i]-s[k][i-1]-s[j-1][i]+s[j-1][i-1];
    memset(f[1],~0x3f,sizeof(f[1]));
    int mx=f[0][0][0][0];
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
            for(int k=j+2;k<=n;k++)
                f[1][i][j][k]=mx+s[k][i]-s[k][i-1]-s[j-1][i]+s[j-1][i-1];
        for(int j=1;j<=n;j++)
            for(int k=j;k<=n;k++)
                mx=max(mx,f[0][i-1][j][k]);
    }
}
void work3()
{
	memset(f[0],~0x3f,sizeof(f[0]));
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            for(int k=j+2;k<=n;k++)
                f[0][i][j][k]=max(f[0][i-1][j][k],f[1][i-1][j][k])+s[k][i]-s[k][i-1]-s[j-1][i]+s[j-1][i-1]-s[k-1][i]+s[k-1][i-1]+s[j][i]-s[j][i-1];
    memset(f[1],~0x3f,sizeof(f[1]));
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            for(int k=j+2;k<=n;k++)
                f[1][i][j][k]=f[0][i-1][j][k]+s[k][i]-s[k][i-1]-s[j-1][i]+s[j-1][i-1];
    memset(f[0],~0x3f,sizeof(f[0]));
    int mx=f[0][0][0][0];
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
            for(int k=j+2;k<=n;k++)
                f[0][i][j][k]=max(mx,f[0][i-1][j][k])+s[k][i]-s[k][i-1]-s[j-1][i]+s[j-1][i-1]-s[k-1][i]+s[k-1][i-1]+s[j][i]-s[j][i-1];
        for(int j=1;j<=n;j++)
            for(int k=j;k<=n;k++)
                mx=max(mx,f[1][i-1][j][k]);
    }
    memset(f[1],~0x3f,sizeof(f[1]));
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            for(int k=j+2;k<=n;k++)
                f[1][i][j][k]=max(f[1][i-1][j][k],f[0][i-1][j][k])+s[k][i]-s[k][i-1]-s[j-1][i]+s[j-1][i-1];
}
int main()
{
	freopen("noi.in","r",stdin);
	freopen("noi.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&s[i][j]),s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
	work1(),work2(),work3();
    memset(f[0],~0x3f,sizeof(f[0]));
    int ans=f[0][0][0][0];
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            for(int k=j+2;k<=n;k++)
            {
                f[0][i][j][k]=max(f[0][i-1][j][k],f[1][i-1][j][k])+s[k][i]-s[k][i-1]-s[j-1][i]+s[j-1][i-1]-s[k-1][i]+s[k-1][i-1]+s[j][i]-s[j][i-1];
        		ans=max(ans,f[0][i][j][k]);
            }
    printf("%d",ans);
	return 0;
}

