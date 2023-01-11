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
const int mod=1e9+7;
int i,j,k,n,s,t,m;
int f[35][505],a[35],C[505][505];
void Inc(int &x,const int &y){x+=y;if(x>=mod)x-=mod;}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	for(i=1;i<=26;i++)read(a[i]);
	C[0][0]=f[0][0]=1;int now=0;
	for(i=1;i<=500;i++)
	{
		C[i][0]=1;
		for(j=1;j<=i;j++)
		C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	for(i=1;i<=26;i++)
	if(a[i])break;
	
	f[i][a[i]-1]=1;
	for(;i<26;i++)
	{
		now+=a[i];
		for(j=0;j<=now;j++)
		{
			if(a[i+1]==0)f[i+1][j]=f[i][j];
			for(int s1=0;s1<=j&&s1<=a[i+1];s1++)
			for(int s2=0;s2+s1<=now+1&&s1+s2<=a[i+1];s2++)
			{
				if(s1+s2==0)continue;
				int to=j+a[i+1]-s1-s2-s1;
				Inc(f[i+1][to],1ll*C[j][s1]*f[i][j]%mod*C[a[i+1]-1][s1+s2-1]%mod*C[now-j+1][s2]%mod);
			}
		}
	}
	cout<<f[26][0]<<endl;
	return 0;
}

