#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
#define pii pair<int,int>
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
const int N=20,mod=998244353;
int i,j,k,n,s,t,m;
int a[N],b[N],c[N];
int quick(int a,int s,int ret=1){
	while(s){
		if(s&1)ret=ret*a%mod;
		s>>=1;
		a=a*a%mod;
	}
	return ret;
}
signed main()
{
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	read(n),read(m);
	for(i=1;i<=n;i++)read(a[i]),read(b[i]);
	for(i=1;i<=n;i++){
		int x=quick(a[i],mod-2),product=1;
		for(j=1;j<=n;j++){
			if(i==j)continue;
			product=product*(1-a[j]*x%mod)%mod;
		}
		c[i]=quick(product,mod-2);
	}
	int ans=0;
	for(int mask=0;mask<1<<n;mask++){
		int p=0,product=1;
		for(i=1;i<=n;i++){
			if((1<<i-1)&mask)p+=b[i]+1,product=product*(-quick(a[i],b[i]+1))%mod;
			else continue;
		}
		if(p>m)continue;
		for(i=1;i<=n;i++){
			ans+=product*c[i]%mod*quick(a[i],m-p)%mod;
			ans%=mod;
		}
	}
	ans=(ans+mod)%mod;
	cout<<ans<<endl;
	return 0;
}

