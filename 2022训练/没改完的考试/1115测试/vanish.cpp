#include<bits/stdc++.h>
using namespace std;
template<typename T>
void read(T &x){
	x=0;char ch=getchar();int f=1;
	while((ch<'0'||ch>'9')&&ch!=45)ch=getchar();
	if(ch==45)ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
template<typename T1,typename T2>void cmin(T1 &x,const T2 &y){if(y<x)x=y;}
template<typename T1,typename T2>void cmax(T1 &x,const T2 &y){if(y>x)x=y;}
const int N=5005,mod=998244353;
int i,j,k,m,n,t,ca,cb;
int pa,pb,s;
int f[N][N],g[N][N];
char ch[N];
int quick(int a,int s,int ret=1){
	while(s){
		if(s&1)ret=1ll*ret*a%mod;
		a=1ll*a*a%mod;s>>=1;
	}
	return ret;
}
signed main(){
	read(n);
	scanf("%s",ch+1);
	cin>>pa>>pb;read(ca),read(cb);swap(pa,pb);
	s=quick(pa+pb,mod-2);
	pa=1ll*pa*s%mod,pb=1ll*pb*s%mod;
	int ipa=quick(pa,mod-2),ipb=quick(pb,mod-2);
	f[0][cb]=1,g[n+1][ca]=1;
	//考虑 i 之前的系数 
	for(i=0;i<n;i++){
		if(ch[i+1]=='A'){
			for(j=1;j<=n;j++)
			f[i+1][j]=(1ll*f[i][j]*pb+1ll*f[i+1][j-1]*pa*(j!=1))%mod;
		}
		else{
			for(j=0;j<=n;j++)
			f[i+1][j]=f[i][j+1];			 
		}
	}
	for(i=n+1;i>=1;i--){
		if(ch[i-1]=='B'){
			for(j=1;j<=n;j++)
			g[i-1][j]=(1ll*g[i][j]*pa+1ll*g[i-1][j-1]*pb*(j!=1))%mod;
		}
		else{
			for(j=0;j<=n;j++)
			g[i-1][j]=g[i][j+1];			 
		}
	}
	int ans=0;
	for(i=0;i<=n;i++){
		ans=(ans+1ll*f[i][0]*g[i+1][0])%mod;
	}
	cout<<ans<<endl;
	return 0;
}

