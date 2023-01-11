#include<bits/stdc++.h>
#define int long long
#define N 200005
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
int n,m,vis[N],pr[N],prcnt,minp[N],fac[N],ifac[N];
int cn1[N],cn2[N]; vector<int>ans;
int Fast(int x,int y){
	int ret=1;
	while(y){
		if(y&1) ret=ret*x%m;
		x=x*x%m,y>>=1;
	}return ret;
}void init(){
	vis[0]=vis[1]=1;
	for(int i=2;i<=N-5;i++){
		if(!vis[i]) pr[++prcnt]=i,minp[i]=i;
		for(int j=1;j<=prcnt&&i*pr[j]<=N-5;j++){
			vis[i*pr[j]]=1,minp[i*pr[j]]=min(minp[i],pr[j]);
			if(i%pr[j]==0) break;
		}
	}
}void add1(int u,int d){
	while(u>1){
		int t=minp[u]; 
		while(u%t==0) cn1[t]+=d,u/=t;
	}
}void add2(int u,int d){
	while(u>1){
		int t=minp[u];
		while(u%t==0) cn2[t]+=d,u/=t;
	}
}int C(int x,int y){if(x<y) return 0; return fac[x]*Fast(fac[y],m-2)%m*Fast(fac[x-y],m-2)%m;}
int Lucas(int x,int y){
	if(y==0) return 1;
	return Lucas(x/m,y/m)*C(x%m,y%m)%m;
}signed main(){
	freopen("random.in","r",stdin);
	freopen("random.out","w",stdout);
	scanf("%lld%lld",&n,&m),init();
	if(m==1){
		printf("%lld\n",n); 
		for(int i=1;i<=n;i++) printf("%lld ",i); 
		return 0;
	}if(n<=1000){
		int mxp=0,mno=m;
		for(int i=2;i*i<=mno;i++){
			if(m%i) continue;
			while(m%i==0) m/=i; 
			mxp=max(mxp,m);
		}mxp=max(mxp,m);
		if(mxp>n){puts("0"); return 0;} m=mno;
		for(int i=2;i*i<=mno;i++){
			if(m%i) continue;
			while(m%i==0) m/=i,++cn1[i]; 
		}if(m>1) ++cn1[m];
		for(int i=0;i<n;i++){
			int fl=1;
			for(int j=1;j<=i;j++) add1(j,1);
			for(int j=n-i;j<=n-1;j++) add2(j,1);
			for(int j=1;j<=prcnt;j++)
				if(cn1[pr[j]]>cn2[pr[j]]) fl=0;
			if(fl) ans.pb(i+1);
			for(int j=1;j<=i;j++) add1(j,-1);
			for(int j=n-i;j<=n-1;j++) add2(j,-1);
		}printf("%lld\n",(int)ans.size());
		for(int &u:ans) printf("%lld ",u);
	}else{
		if(m>n){puts("0"); return 0;}
		fac[0]=1;
		for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%m;
		for(int i=0;i<n;i++) if(!Lucas(n-1,i)) ans.pb(i+1);
		printf("%lld\n",(int)ans.size());
		for(int &u:ans) printf("%lld ",u); 
	}return 0;
}
