#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define sz(x) (int)x.size()
#define pii pair<int,int>
using namespace std;
template<typename T>inline void chmax(T &a,T b){a=max(a,b);}
template<typename T>inline void chmin(T &a,T b){a=min(a,b);}
inline void exgcd(int a,int b,int &x,int &y){
	if(!b){
		x=1,y=0;
		return;
	}
    exgcd(b,a%b,x,y);
    int t=x;
    x=y;
	y=t-(a/b)*y;
}
inline int inv(int a,int b){
    int x,y;
    exgcd(a,b,x,y);
	return (x%b+b)%b;
}
inline int qpow(int a,int b,int p){
    int ans=1;
    while(b){
        if(b%2)
            ans=a*ans%p;
        a=a*a%p;
        b/=2;
    }
    return ans%p;
}
inline int crt(int x,int p,int mod){
    return inv(p/mod,mod)*(p/mod)*x;
}
inline int fac(int x,int a,int b){
    if(!x)return 1;
    int ans=1;
    for(int i=1;i<=b;i++){
    	if(i%a){
    		ans*=i;
			ans%=b;
		}
	}
    ans=qpow(ans,x/b,b);
    for(int i=1;i<=x%b;i++){
    	if(i%a){
    		ans*=i;
			ans%=b;
		}
	}
    return ans*fac(x/a,a,b)%b;
}
inline int C(int n,int m,int a,int b){
    int N=fac(n,a,b),M=fac(m,a,b),Z=fac(n-m,a,b),sum=0;
    for(int i=n;i;i=i/a)
        sum+=i/a;
    for(int i=m;i;i=i/a)
        sum-=i/a;
    for(int i=n-m;i;i=i/a)
        sum-=i/a;
    return N*qpow(a,sum,b)%b*inv(M,b)%b*inv(Z,b)%b;
}
inline int exLucas(int n,int m,int p){
    int t=p,ans=0;
    for(int i=2;i*i<=p;i++){
        int k=1;
        while(t%i==0){
        	k*=i;
			t/=i;
		}
        ans+=crt(C(n,m,i,k),p,k);
		ans%=p;
    }
    if(t>1){
    	ans+=crt(C(n,m,t,t),p,t);
		ans%=p;
	}
    return ans%p;
}
int F[100005],I[100005];
int CC(int x,int y,int p){
	return F[x]*I[y]%p*I[x-y]%p;
}
signed main(){
	freopen("random.in","r",stdin);
	freopen("random.out","w",stdout);
	int n,m;
	vector<int>ans;
	scanf("%lld%lld",&n,&m);
	if(m==1){
		printf("%lld\n",n);
		for(int i=1;i<=n;i++){
			printf("%lld\n",i);
		}
		return 0;
	}
	if(m<n){
		for(int i=2;i<n;i++){
			if(!exLucas(n-1,i-1,m)){
				ans.pb(i);
			}
		}
	}
	else{
		F[0]=I[0]=1;
		for(int i=1;i<n;i++){
			F[i]=F[i-1]*i%m;
			I[i]=qpow(F[i],m-2,m);
		}
		for(int i=2;i<n;i++){
			if(!CC(n-1,i-1,m)){
				ans.pb(i);
			}
		}
	}
	printf("%lld\n",sz(ans));
	for(int i=0;i<sz(ans);i++){
		printf("%lld\n",ans[i]);
	}
	return 0;
}
/*
Basic:
1. int or long long?
2. freopen?
3. memory limits?
Advanced:
1. use more functions
2. write carefully and check
3. think twice before writing
4. debug quickly
5. never copy others' codes
*/
