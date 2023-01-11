#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pii pair<long long,long long>
#define mp make_pair
#define pb push_back
int mod;
const int inf=0x3f3f3f3f;
const int INF=1e18;
int fpow(int x,int b){
	if(x==0) return 0;
	if(b==0) return 1;
	int res=1;
	while(b>0){
		if(b&1)	res=res*x%mod;
		x=x*x%mod;
		b>>=1;
	}
	return res;
}
int fac[300005];
int C(int x,int y)
{
	if(x==0||x==y) return 1;
	return fac[y]*fpow(fac[y-x],mod-2)%mod*fpow(fac[x],mod-2)%mod;
}
int n,m;
int ans[100005];
void chk(int x)
{
//	cout<<x<<endl;
	mod=x;
	if(x<=n-1)
	{
		int c=1;
		for(int i=0;i<=n;i++) fac[i]=0;
		for(int i=x;i<=n;i+=x) 
		{
			c=0;
			int t=i;
			while(t%x==0) t/=x,c++;
			fac[i]=c;
		}
		for(int i=1;i<=n;i++) fac[i]+=fac[i-1];
		for(int i=0;i<n;i++)
		{
			int c=fac[n-1];
			c-=fac[i],c-=fac[n-1-i];
			if(c==0) ans[i]=0;
		}
		return;
	}
	fac[0]=fac[1]=1;
	for(int i=2;i<=n;i++) fac[i]=(fac[i-1]*i)%mod;
	for(int i=0;i<n;i++)
	{
		int val=C(i,n-1);
	//	cout<<i<<" "<<val<<endl;
		if(val) ans[i]=0;
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=0;i<n;i++) ans[i]=1;
	if(m==1)
	{
		printf("%lld\n",n);
		for(int i=1;i<=n;i++) printf("%lld ",i);
		return;
	}
	if(n==1)
	{
		puts("0");
		return;
	}
	for(int i=2;i*i<=m;i++) if(m%i==0)
	{
		while(m%i==0) m/=i;
		chk(i);
	}
	if(m!=1) chk(m);
//	for(int j=0;j<n;j++) cout<<ans[j]<<" ";
//	puts("");
	vector <int> v;
	v.clear();
	for(int i=0;i<n;i++) if(ans[i]) v.pb(i);
	cout<<v.size()<<endl;
	for(int i=0;i<v.size();i++) printf("%lld ",v[i]+1);
	
}
signed main()
{
	freopen("random.in","r",stdin);
	freopen("random.out","w",stdout);
	int _=1;
	//cin>>_;
	while(_--) solve();
	return 0;
}
