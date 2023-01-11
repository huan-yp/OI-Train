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
const int N=100005,T=550;
int i,j,k,n,s,t,m;
int a[N],sum[N],suf[N][T];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	{
		//dp[i][k]=dp[i+k][]
		read(n);
		
		for(i=1;i<=n;i++)
		read(a[i]),sum[i]=sum[i-1]+a[i];
		for(i=1;i<=n+1;i++)
		for(j=0;j<T;j++)
		suf[i][j]=0;
	
		suf[n+1][0]=1ll*INF*INF;
		for(i=n;i>=1;i--)
		{
			suf[i][0]=suf[i+1][0];
			for(k=1;i+k-1<=n&&k<T;k++)
			{
				suf[i][k]=suf[i+1][k];
				if(sum[i+k-1]-sum[i-1]<suf[i+k][k-1])
				suf[i][k]=max(suf[i+1][k],sum[i+k-1]-sum[i-1]);
			}
		}
		for(i=T-1;i>=0;i--)
		if(suf[1][i])
		{
			printf("%lld\n",i);
			break;
		}
	}
	return 0;
}

