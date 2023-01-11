#include<bits/stdc++.h>
#define debug(...) std::cerr<<#__VA_ARGS__<<" : "<<__VA_ARGS__<<std::endl

using ll=long long;
ll n,m,M,len;
ll num[35],cnt[35],A[35],B[35];
ll fac[100005][35];

int main() {
	freopen("random.in","r",stdin);
	freopen("random.out","w",stdout);
	scanf("%lld%lld",&n,&m); M=m;
	for(ll i=2;i*i<=m;i++) {
		if(m%i==0) {
			num[++len]=i;
			while(m%i==0) {
				m/=i;
				cnt[len]++;
			}
		}
	}
	if(m!=1) num[++len]=m,cnt[len]=1;	
	for(ll i=2;i<=n;i++) {
		for(ll j=1;j<=len;j++) fac[i][j]+=fac[i-1][j];
		for(ll j=1;j<=len;j++) {
			ll k=i;
			while(k%num[j]==0) {
				fac[i][j]++;
				k/=num[j];
			}
		}	
	}
	std::vector<ll> ans;
	for(ll i=0;i<=n-1;i++) {
		for(ll j=1;j<=len;j++) A[j]=fac[n-1][j],B[j]=fac[i][j]+fac[n-1-i][j];
		ll t=1;
		for(ll j=1;j<=len;j++) if(A[j]-B[j]<cnt[j]) t=0;
		if(t==1) ans.push_back(i+1ll);
	}
	printf("%lld\n",(ll)ans.size());
	for(ll i=0;i<(ll)ans.size();i++) printf("%lld ",ans[i]); 
	return 0;
}
