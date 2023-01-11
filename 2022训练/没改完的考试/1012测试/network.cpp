#include<bits/stdc++.h>
#define LL long long
using namespace std;
template<typename T>
void read(T &x){
	x=0;char ch=getchar();int f=1;
	while((ch<'0'||ch>'9')&&ch!=45)ch=getchar();
	if(ch==45)ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
template<typename T1,typename T2>void cmax(T1 &x,const T2 &y){if(y>x)x=y;}
template<typename T1,typename T2>void cmin(T1 &x,const T2 &y){if(y<x)x=y;}
const int N=1e6+10;
int i,j,k,m,n,s,t;
LL dp[N],h[N],w[N],sm[N];
struct line{
	LL k,b;
	LL operator ()(const LL &x){return k*x+b;}
};
struct LiChaoSGT{
	line a[N<<2];
	void push_down(int l,int r,int rt,line c){
		int mid=(l+r)/2;
		if(c(mid)<a[rt](mid))swap(a[rt],c);
		if(c(l)<a[rt](l))push_down(l,mid,rt<<1,c);
		if(c(r)<a[rt](r))push_down(mid+1,r,rt<<1|1,c);
	}
	LL quert(int l,int r,int rt,LL x){
		if(l==r)return a[rt](x);
		int mid=(l+r)>>1;
		if(x<=mid)return min(a[rt](x),quert(l,mid,rt<<1,x));
		return min(a[rt](x),quert(mid+1,r,rt<<1|1,x));
	}
	void clear(){
		for(i=1;i<N<<2;i++)a[i]=line{0,(long long)1e18};
	}
}T;
line getL(int x){
	return line{-2*h[x],-sm[x]+h[x]*h[x]+dp[x]};
}
int main(){
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	//read(n),cout<<n<<endl;
	T.clear();
	read(n);
	for(i=1;i<=n;i++)read(h[i]);
	for(i=1;i<=n;i++)read(w[i]),sm[i]=sm[i-1]+w[i];
	T.push_down(1,N-1,1,getL(1));	
	for(i=2;i<=n;i++){
		dp[i]=T.quert(1,N-1,1,h[i])+h[i]*h[i]+sm[i-1];
		T.push_down(1,N-1,1,getL(i));
	}
	cout<<dp[n]<<endl;
	return 0;
}

