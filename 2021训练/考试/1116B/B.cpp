#include<bits/stdc++.h>
#define int long long
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
const int N=1e6+10,mod=1e9+7;
int i,j,k,m,n,s,t,d,g=1;
int sum[N],dp[N][2],cnt[N][2],r[N];
char ch[N];
void Inc(int &x,const int &y){x+=y;if(x>=mod)x-=mod;if(x<0)x+=mod;}
signed main()
{
//	freopen("division.in","r",stdin);
//	freopen("division.out","w",stdout);
	scanf("%s",ch+1);read(d);
	while(d%2==0)d/=2,g*=2;
	while(d%5==0)d/=5,g*=5;
	n=strlen(ch+1);
	dp[0][1]=1;int base=1;sum[0]=1;
	for(i=n;i>=1;i--)
	r[i]=(r[i+1]+base*(ch[i]-'0'))%d,base=base*10%d;
	
	for(i=1;i<=n;i++)
	{
		int now=0,base=1;
		dp[i][0]=sum[i-1];
		for(j=i;j>=1&&j>=i-25;j--)
		{
			now=(now+base*(ch[j]-'0'))%(g*d);
			if(now==0)Inc(dp[i][1],dp[j-1][1]);
			base=base*10%(g*d);
		}
		if(now%g==0)Inc(dp[i][1],cnt[r[i+1]][1]);
		Inc(dp[i][0],-dp[i][1]);
		if(i-25>=1)Inc(cnt[r[i-25]][1],dp[i-26][1]);
		now=0,base=1;
		for(j=i;j>=1&&j>=i-25;j--)
		{
			now=(now+base*(ch[j]-'0'))%(g*d);
			if(now==0)Inc(dp[i][1],dp[j-1][0]);
			base=base*10%(g*d);
		}
		if(now%g==0)Inc(dp[i][1],cnt[r[i+1]][0]);
		if(i-25>=1)Inc(cnt[r[i-25]][0],dp[i-26][0]);
		sum[i]=sum[i-1];Inc(sum[i],dp[i][1]);
	}
	cout<<(dp[n][0]+dp[n][1])%mod<<endl;
	return 0;
}

