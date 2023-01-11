#include<bits/stdc++.h>
#define y1 y36
#define INF 1000000000
#define LL long long 
using namespace std;
namespace FAST_READ{
	const int MAX_BUF=1<<20;
	char buf[MAX_BUF+10],*p1=buf,*p2=buf;
	#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,MAX_BUF,stdin),p1==p2)?EOF:*p1++)
	int read(){
		int x=0;char ch=gc();
		while(ch<'0'||ch>'9')ch=gc();
		while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=gc();
		return x;
	}
}
using namespace FAST_READ;
template<typename T1,typename T2>void cmin(T1 &x,const T2 &y){if(y<x)x=y;}
template<typename T1,typename T2>void cmax(T1 &x,const T2 &y){if(y>x)x=y;}
const int T=10,M=1<<T,Q=1e6+10,N=5e4+10;
int i,j,k,m,n,t;
int x[Q],a[N],b[N],cnt[M],nxt[N][M];
LL ans[Q],res;
void process(){
	n=read();
	for(i=1;i<=n;i++)a[i]=read();
	memset(nxt[n+1],1,sizeof(nxt[n+1]));
	for(i=n;i>=1;i--){
		memcpy(nxt[i],nxt[i+1],sizeof(nxt[i]));
		nxt[i][a[i]]=i;
		for(int w=M-1^a[i];w;w=(w-1)&(M-1^a[i]))
		nxt[i][w|a[i]]=i;
	}
	for(i=1;i<=n;i++)b[i]=read();
	m=read();
	for(i=1;i<=m;i++){
		int l=read(),r=read();x[i]=read();
		l=nxt[l][x[i]];
		while(l<=r){
			ans[i]+=b[l];
			x[i]^=a[l];
			l=nxt[l][x[i]];
		}
	}
}
int main(){
//	freopen("expedition.in","r",stdin);
//	freopen("expedition.out","w",stdout);
	process();
	for(i=1;i<=m;i++)res^=ans[i];
	cout<<res<<endl;
	return 0;
}

