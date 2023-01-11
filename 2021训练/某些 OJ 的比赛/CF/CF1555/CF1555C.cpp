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
void cmin(int &a,int b)
{
	a=min(a,b);
}
void cmax(int &a,int b)
{
	a=max(a,b);
}
/*



*/
const int N=1e5+10;
int i,j,k,n,s,t,m;
int a[3][N],suf[3][N],pre[3][N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	{
		int ans=1ll*INF*INF;
		read(n);
		for(i=1;i<=2;i++)
		for(j=1;j<=n;j++)
		read(a[i][j]),pre[i][j]=pre[i][j-1]+a[i][j];
		
		suf[1][n+1]=suf[2][n+1]=0;
		for(i=1;i<=2;i++)
		for(j=n;j>=1;j--)
		suf[i][j]=suf[i][j+1]+a[i][j];
		
		for(i=1;i<=n;i++)
		ans=min(ans,max(suf[1][i+1],pre[2][i-1]));	
		
		cout<<ans<<endl;
	}

	return 0;
}

