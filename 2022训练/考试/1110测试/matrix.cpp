#include<bits/stdc++.h>
#define INF 1000000000
#define LL long long
#define gc() getchar()
int read(){
	int x=0;char ch=gc();
	while(ch<'0'||ch>'9')ch=gc();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=gc();
	return x;
}
using namespace std;
template<typename T1,typename T2>void cmin(T1 &x,const T2 &y){if(y<x)x=y;}
template<typename T1,typename T2>void cmax(T1 &x,const T2 &y){if(y>x)x=y;}
const int N=3005;
int i,j,k,m,n,s,t;
int a[N][N],rk[2][N],height[2][N],st[N];
signed main(){
	read();
	n=read(),m=read();
	for(i=1;i<=n;i++)for(j=1;j<=m;j++)
	a[i][j]=read(),a[i][j]=(a[i][j]+a[i][j-1])&1;
	long long ans=1ll*(n+1)*n*(m+1)*m/4;
	for(i=0;i<=m;i++)rk[n+1&1][i]=i;
	for(i=n;i>=1;i--){
		auto f=rk[i+1&1],g=rk[i&1],h=height[i&1],w=height[i+1&1];
		int cnt=0,maxn=INF,flag=0,top=0;
		long long sum=0,all=0;
		for(j=0;j<=m;j++){
			cmin(maxn,w[j]);
			if(a[i][f[j]]==0){
				g[cnt]=f[j];
				h[cnt++]=maxn+1;
				maxn=INF;
			}
		}
		maxn=0;
		for(j=0;j<=m;j++){
			cmin(maxn,w[j]);
			if(a[i][f[j]]==1){
				g[cnt]=f[j];
				h[cnt]=maxn+flag;
				cnt++,flag=1;
				maxn=INF;
			}
		}
		for(j=1;j<=m;j++){
			int minu=INF;
			while(top&&h[st[top]]>h[j]){
				sum-=(h[st[top]]-h[j])*(st[top]-st[top-1]);
				top--;
			}
			st[++top]=j;
			all+=sum+=h[j];
		}
		ans-=all;
	}
	cout<<ans<<endl;
	return 0;
}

