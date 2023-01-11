#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
#define c1 c[1]
#define c2 c[2]
#define c3 c[3]
#define c4 c[4]
#define c5 c[5]
#define c6 c[6]
#define c7 c[7]
#define c8 c[8]
#define c9 c[9]
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
/*
	sum;
	c[x];
	val[]c[x]*C(sum,c[x])*f[sum-c[x]]/¦°f[c[y]]/sum

*/
const int mod=500500573,N=10005;
int i,j,k,n,s,t,m,prod,sum;
int f[N]={1},inv[N]={1},c[10],val[N][10];
int quick(int a,int s,int ret=1)
{
	while(s)
	{
		if(s&1)
		ret=1ll*ret*a%mod;
		a=1ll*a*a%mod;
		s>>=1;
	}
	return ret;
}
void init()
{
	for(i=1;i<N;i++)
	f[i]=1ll*f[i-1]*i%mod,inv[i]=quick(f[i],mod-2);
	for(i=1;i<=9;i++)
	for(j=1;j<N;j++)
	val[j][i]=(1ll*val[j-1][i]*10%mod+i)%mod;
}
int calc(int x)
{
	int cnt=1ll*f[sum-1]*prod%mod*c[x]%mod;
	return 1ll*cnt*val[sum][x]%mod;
}
class ProductAndSum{
	public:
	int getSum(int p2,int p3,int p5,int p7,int S)
	{
		init();
		int ans=0;
		for(c9=p3/2+1;c9>=0;c9--)
		for(c8=p2/3+1;c8>=0;c8--)
		for(c6=100;c6>=0;c6--)
		for(c4=p2/2+1;c4>=0;c4--)
		{
			c2=p2-c8*3-c4*2-c6,c3=p3-c9*2-c6,c7=p7,c5=p5;
			c1=S-c2*2-c3*3-c4*4-c5*5-c6*6-c7*7-c8*8-c9*9;
			if(c2<0||c3<0||c1<0)continue;
			sum=0,prod=1;
			for(i=1;i<=9;i++)
			sum+=c[i],prod=1ll*prod*inv[c[i]]%mod;
			for(i=1;i<=9;i++)
			ans+=calc(i),ans%=mod;
		}
		return ans;
	}
}; 
//signed main()
//{
//	//freopen(".in","r",stdin);
//	//freopen(".out","w",stdout);
//	//freopen(".ans","w",sdtout);
//	ProductAndSum solve;
//	cout<<solve.getSum(5,5,5,5,100);
//	
//	return 0;
//}

