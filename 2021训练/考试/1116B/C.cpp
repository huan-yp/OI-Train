#include<bits/stdc++.h>
using namespace std;
void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while((ch>'9'||ch<'0')&&ch!=45)ch=getchar();
	if(ch==45)ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	x*=f;
}
template<typename _type>
void cmax(_type &a,_type b){a=max(a,b);}
template<typename _type>
void cmin(_type &a,_type b){a=min(a,b);}
const int N=3005,mod=1e9+7;
int i,j,k,m,n,s,t;
int f[N][N],g[N][N<<1],fs[N][N],gs[N][N];
char ch[N][N];
void Inc(int &x,const int &y){x+=y;if(x>=mod)x-=mod;if(x<0)x+=mod;}
int main()
{
//	freopen("matrix.in","r",stdin);
//	freopen("matrix.out","w",stdout);
	read(n),read(m),read(k);
	for(i=1;i<=n;i++)
	scanf("%s",ch[i]+1);
	for(i=1;i<=m;i++)
	{
		f[1][i]=1,g[1][i]=ch[1][i]!=ch[1][i-1];
		fs[1][i]=fs[1][i-1]+f[1][i],gs[1][i]=gs[1][i-1]+g[1][i];
	}
	for(i=2;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			int l=max(1,j-k),r=min(j+k,m);
			f[i][j]=f[i-1][l];
			Inc(f[i][j],gs[i-1][r]-gs[i-1][l]);
			if(ch[i][j]==ch[i][j-1])g[i][j]=g[i-1][j+k];
			else g[i][j]=f[i][j];
		}
		for(j=1;j<=m;j++)
		{
			fs[i][j]=fs[i][j-1],Inc(fs[i][j],f[i][j]);
			gs[i][j]=gs[i][j-1],Inc(gs[i][j],g[i][j]);
		}
	}
	int ans=f[n][1];
	for(i=2;i<=m;i++)
	Inc(ans,g[n][i]);
	cout<<ans<<endl;
	return 0;
}

