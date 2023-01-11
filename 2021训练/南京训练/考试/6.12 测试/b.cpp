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
const int N=5005,mod=998244353;
int i,j,k,n,s,t,m;
int dp[N][N],a[N],p[N];
signed main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	//freopen(".ans","w",sdtout);
	//consider add numbers to array pos
	read(n);
	for(i=1;i<=n;i++)
	read(a[i]),p[a[i]]=i;
	for(i=1;i<=n;i++)
	if(p[i]==0||p[i]==n)
	dp[i][i]=1;
	for(i=1;i<n;i++)
	for(int l=1;l+i-1<=n;l++)
	{
		int r=l+i-1;
		if(l!=1&&(p[l-1]==0||p[l-1]==n-i))
		dp[l-1][r]+=dp[l][r],dp[l-1][r]%=mod;
		if(r!=n&&(p[r+1]==0||p[r+1]==n-i))
		dp[l][r+1]+=dp[l][r],dp[l][r+1]%=mod;
	}
	printf("%d\n",dp[1][n]);
	return 0;
}


