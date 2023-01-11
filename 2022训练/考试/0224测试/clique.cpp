#include<bits/stdc++.h>
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
const int N=1000005,mod=1e9+7;
int i,j,k,n,s,t,m,ans;
int d[N],f[N],inv[N],cnt[N]; 
int quick(int a,int s,int ret=1){
	while(s){
		if(s&1)ret=1ll*ret*a%mod;
		a=1ll*a*a%mod;
		s>>=1;
	}
	return ret;
}
int C(int n,int m){
	return 1ll*f[n]*inv[m]%mod*inv[n-m]%mod;
}
signed main()
{
 	freopen("clique.in","r",stdin);
	freopen("clique.out","w",stdout);
	read(t);f[0]=inv[0]=1;
	for(i=1;i<N;i++)f[i]=1ll*f[i-1]*i%mod,inv[i]=quick(f[i],mod-2);
	while(t--){
		read(n),read(m);
		for(i=1;i<=n;i++)cnt[i]=0,d[i]=0;
		for(i=1;i<=m;i++){
			int x,y;read(x),read(y);
			d[x]--,d[y]--;
		}
		int ans=0,lst=n+1,p=0;
		sort(d+1,d+n+1);
		for(i=1;i<=n;i++)d[i]=-d[i];
		for(i=1;i<=n;i++)cnt[d[i]]++;
		for(i=1;i<=n;i++){
			if(d[i]!=d[i-1])lst=i-1;
			p+=d[i];
			if(2*p==i*(i-1)+2*m)
			ans+=C(cnt[d[i]],i-lst),ans%=mod;
		}
		printf("%d\n",ans);
	}
	return 0;
}

