#include<bits/stdc++.h>
using namespace std;
template<typename T>
int read(T &x){
	x=0;char ch=getchar();int f=1;
	while((ch<'0'||ch>'9')&&ch!=45)ch=getchar();
	if(ch==45)ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	return x*=f;
}
template<typename T1,typename T2>void cmax(T1 &x,const T2 &y){if(y>x)x=y;}
template<typename T1,typename T2>void cmin(T1 &x,const T2 &y){if(y<x)x=y;}
const int N=1005;
const double eps=1e-9;
int i,j,k,m,n,s,t,p,q;
double dp[N][N][2];
int from[N][N][2];
struct task{
	int t,a,b,c,d;
	void init(){
		read(t),read(a),read(b),read(c),read(d);
		a+=c;
	}
}a[N];
int check(double x){
	for(i=0;i<=n;i++)
	for(j=0;j<=m;j++)
	dp[i][j][0]=dp[i][j][1]=-1e18;
	
	dp[0][0][0]=0;
	for(i=0;i<n;i++)for(j=0;j<=m;j++)for(k=0;k<=1;k++){
		if(dp[i][j][k]<-1e17)continue;
		if(j+a[i+1].t<=m&&dp[i][j][k]+a[i+1].a-a[i+1].b*x>dp[i+1][j+a[i+1].t][k|(a[i+1].b>0)]){
			dp[i+1][j+a[i+1].t][k|(a[i+1].b>0)]=dp[i][j][k]+a[i+1].a-a[i+1].b*x;
			from[i+1][j+a[i+1].t][k|(a[i+1].b>0)]=2|k;
		}
		if(dp[i][j][k]-a[i+1].d*x>dp[i+1][j][k|(a[i+1].d>0)]){
			dp[i+1][j][k|(a[i+1].d>0)]=dp[i][j][k]-a[i+1].d*x;
			from[i+1][j][k|(a[i+1].d>0)]=k;
		}
	}	
	double max_val=-1e9,mv2=-1e9;int max_pos=0,p=0,q=0,f=1;
	for(i=0;i<=m;i++){
		cmax(max_val,dp[n][i][0]),cmax(mv2,dp[n][i][1]);
		if(dp[n][i][1]>dp[n][max_pos][1])max_pos=i;
	}
	
	for(i=n;i>=1;i--){
		int val=from[i][max_pos][f];
		if(val&2)p+=a[i].a,q+=a[i].b,max_pos-=a[i].t;
		else q+=a[i].d;
		if(val&1)f=1;
		else f=0;
	}
	if(1.0*p/q>=x){
		::p=p,::q=q;
		return 1;
	}
	if(max_val>=x){
		::p=max_val,::q=1;
		return 1;
	}
	return 0;
}
int main(){
//	freopen("kda.in","r",stdin);
//	freopen("kda.out","w",stdout);
	//freopen(".in","w",stdout);
	read(n),read(m);
	for(i=1;i<=n;i++)a[i].init();
	double l=-1,r=1000,ans=-1;
	while(r-l>=eps){
		double mid=(l+r)/2;
		if(check(mid))
		ans=l=mid;
		else 
		r=mid;
	}
	int gc=__gcd(p,q);
	cout<<p/gc<<' '<<q/gc<<endl;
	return 0;
}
