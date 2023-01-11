#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
const int INF=4e18;
inline int read()
{
	int x=0;
	bool flag=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			flag=0;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return (flag?x:~(x-1));
}
int n,m,N,O,I,a[201][601],b[201][601],f[10][200][600],g[600];
int sum(int i,int l,int r)
{
	return b[r][i]-b[l-1][i];
}
signed main()
{
	fileio("noi");
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
		for(int l=1;l<=m;l++)
		{
			a[i][l]=read();
			b[i][l]=b[i-1][l]+a[i][l];
		}
	memset(f,192,sizeof(f));
	N=O=I=f[0][0][0];
	for(int i=1;i<=m+1;i++)
	{
		for(int l=1;l<=n;l++)
			for(int j=l;j<=n;j++)
				I=max(I,f[9][l][j]);
		for(int l=1;l<=n;l++)
			for(int j=l;j<=n;j++)
				f[9][l][j]=max(f[9][l][j],f[8][l][j])+a[l][i]+a[j][i];
		for(int l=1;l<=n;l++)
			for(int j=l;j<=n;j++)
				f[8][l][j]=max(f[8][l][j],f[7][l][j])+sum(i,l,j);
		for(int l=1;l<=n;l++)
			for(int j=l+2;j<=n;j++)
				f[7][l][j]=max(O,f[7][l][j])+a[l][i]+a[j][i];

		for(int l=1;l<=n;l++)
			for(int j=l;j<=n;j++)
				O=max(O,f[6][l][j]);
		for(int l=1;l<=n;l++)
			for(int j=l;j<=n;j++)
				f[6][l][j]=f[5][l][j]+sum(i,l,j);
		for(int l=1;l<=n;l++)
			for(int j=l;j<=n;j++)
				f[5][l][j]=max(f[5][l][j],f[4][l][j])+a[l][i]+a[j][i];
		for(int l=1;l<=n;l++)
			for(int j=l+2;j<=n;j++)
				f[4][l][j]=N+sum(i,l,j);

		memcpy(f[0],f[3],sizeof(f[3]));
		for(int l=1;l<=n;l++)
			for(int j=l;j<=n;j++)
				N=max(N,f[3][l][j]);
		for(int len=1;len<=n;len++)
			for(int l=1;l+len-1<=n;l++)
				f[3][l][l+len-1]=max(f[3][l+1][l+len-1],f[2][l+1][l+len-1]);
		for(int l=1;l<=n;l++)
			for(int j=1;j<=n;j++)
				f[3][l][j]=max(f[3][l][j],f[0][l][j])+sum(i,l,j);
		memcpy(f[0],f[2],sizeof(f[2]));
		memset(g,192,sizeof(g));
		for(int l=1;l<=n;l++)
		{
			int mx=g[l-1];
			for(int j=l;j<=n;j++)
			{
				g[j]=max(g[j],f[2][l][j]);
				mx=max(mx,g[j]);
				f[2][l][j]=mx;
			}
		}
		for(int len=n;len;len--)
			for(int l=1;l+len-1<=n;l++)
				f[0][l][l+len-1]=max(f[0][l][len+l],f[1][l][l+len]);
		for(int l=1;l<=n;l++)
			for(int j=l;j<=n;j++)
				f[2][l][j]=max(f[0][l][j],f[2][l][j])+sum(i,l,j);
		for(int l=1;l<=n;l++)
			for(int j=l;j<=n;j++)
				f[1][l][j]=max(f[1][l][j],0ll)+sum(i,l,j);
		// cout<<N<<" "<<O<<" "<<I<<endl;
	}
	cout<<I;
	return 0;
}