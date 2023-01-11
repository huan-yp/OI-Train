#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100005
ll c[N],n,p,cnt;
ll exgcd(ll a,ll b,ll &x,ll &y){
    if(!b){x=1;y=0;return a;}
    ll res=exgcd(b,a%b,x,y),t;
    t=x;x=y;y=t-a/b*y;
    return res;
}
ll power(ll a,ll b,ll mod){
    ll sm=1;
    while(b){
    	if(b&1) sm=sm*a%mod;
    	b>>=1;
    	a=a*a%mod;
	}
    return sm;
}
ll fac(ll n,ll pi,ll pk){
    if(!n)return 1;
    ll res=1;
    for(ll i=2;i<=pk;++i)
        if(i%pi)res=res*i%pk;
    res=power(res,n/pk,pk);
    for(ll i=2;i<=n%pk;++i)
        if(i%pi)res=res*i%pk;
    return res*fac(n/pi,pi,pk)%pk;
}
ll inv(ll n,ll mod){
    ll x,y;
    exgcd(n,mod,x,y);
    return (x+=mod)>mod?x-mod:x;
}
ll CRT(ll b,ll mod){return b*inv(p/mod,mod)%p*(p/mod)%p;}
ll C(ll n,ll m,ll pi,ll pk){
    ll up=fac(n,pi,pk),d1=fac(m,pi,pk),d2=fac(n-m,pi,pk);
    ll k=0;
    for(ll i=n;i;i/=pi)k+=i/pi;
    for(ll i=m;i;i/=pi)k-=i/pi;
    for(ll i=n-m;i;i/=pi)k-=i/pi;
    return up*inv(d1,pk)%pk*inv(d2,pk)%pk*power(pi,k,pk)%pk;
}
ll exlucus(ll n,ll m){
    ll res=0,tmp=p,pk;
	static int lim=sqrt(p)+5;
    for(int i=2;i<=lim;++i)if(tmp%i==0){
        pk=1;
		while(tmp%i==0)pk*=i,tmp/=i;
        (res+=CRT(C(n,m,i,pk),pk))%=p;
    }
	if(tmp>1)(res+=CRT(C(n,m,tmp,tmp),tmp))%=p;
    return res;
}
int main(){
	freopen("random.in","r",stdin);
	freopen("random.out","w",stdout);
	cin>>n>>p;
	n--;
	c[0]=1%p;c[n]=1%p;
	for(int i=1;i<n;i++) c[i]=exlucus(n,i);
	for(int i=0;i<=n;i++)
		if(c[i]==0)
			cnt++;
	cout<<cnt<<endl;
	for(int i=0;i<=n;i++)
		if(c[i]==0)
			cout<<i+1<<" ";
	fclose(stdin);fclose(stdout);
	return 0;
} 
