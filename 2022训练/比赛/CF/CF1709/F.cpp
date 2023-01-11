#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
#define int long long
#define pii pair<int,int>
using namespace std;
template<typename _type>
inline void read(_type &x){
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
template<typename _type1,typename _type2>void cmin(_type1 &a,const _type2 b){if(a>b)a=b;}
template<typename _type1,typename _type2>void cmax(_type1 &a,const _type2 b){if(a<b)a=b;}
const int N=1<<19,mod=998244353;
namespace NTT{
	const int N=1<<20,mod=998244353,g=3,gi=332748118;
	int i,j,k,n,s,t,m;
	int a[N],b[N],rk[N];
	int quick(int a,int s,int ret=1){
		while(s){
			if(s&1)ret=ret*a%mod;
			a=a*a%mod,s>>=1;
		}
		return ret;
	}
	void NTT(int *a,int type)
	{
		for(i=0;i<1<<s;i++)
		if(rk[i]>i)swap(a[rk[i]],a[i]);
		for(int len=1;len<=s;len++)
		{
			int w=1,wn=quick(g,mod-1>>len);
			if(type==-1)wn=quick(wn,mod-2);
			for(j=0;j+(1<<len)<=1<<s;j+=1<<len,w=1)
			{
				for(k=j;k<j+(1<<len-1);k++,w=1ll*w*wn%mod)
				{
					int x=a[k],y=a[k+(1<<len-1)];
					a[k]=(x+1ll*w*y%mod)%mod,a[k+(1<<len-1)]=(x-1ll*w*y%mod)%mod;
				}
			}
		}
	}
	void init(int nn,int c[],int res[]){
		n=m=nn;
		memset(a,0,sizeof(a)),memset(b,0,sizeof(b));
		for(i=0;i<=n;i++)a[i]=c[i];
		for(i=0;i<=m;i++)b[i]=c[i];
		while(1<<s<=n+m)s++;
	
		for(i=1;i<1<<s;i++)rk[i]=rk[i>>1]>>1|(i%2?1<<s-1:0);
		NTT(a,1),NTT(b,1);
		for(i=0;i<1<<s;i++)a[i]=1ll*a[i]*b[i]%mod;
		NTT(a,-1);int inv=quick(1<<s,mod-2);
		for(i=0;i<=n+m;i++)
		res[i]=(1ll*a[i]*inv%mod+mod)%mod;
	}
}
int i,j,k,n,s,t,m,tp1,tp2,f;
void Inc(int &a,int b){
	a+=b;if(a>=mod)a-=mod;
}
int quick(int a,int s,int ret=1){
	while(s){
		if(s&1)ret=ret*a%mod;
		a=a*a%mod,s>>=1;
	}
	return ret;
}

int dp[16][N<<1],sum[16][N<<1],p[N];
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	read(n),read(k),read(f);
	for(i=0;i<=k;i++)dp[0][i]=1;
	for(i=1;i<=n;i++){
		NTT::init(k,dp[i-1],sum[i]);
		for(j=0;j<=2*k;j++){
			if(i!=n)dp[i][j]=sum[i][j]*(k-j+1)%mod;
			else dp[i][j]=sum[i][j];
		}
		if(i!=n)for(j=2*k-1;j>=0&&i!=n;j--){
			if(j<=k)Inc(dp[i][j],sum[i][j+1]);
			Inc(sum[i][j],sum[i][j+1]);
		}	
	}
	cout<<(dp[n][f]+mod)%mod;
	return 0;
}


