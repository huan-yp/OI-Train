#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#define y1 y3647
#define INF 1000000000
#define LL long long
#define ULL unsigned long long
#define pii pair<int,int>
using namespace std;
using namespace __gnu_pbds;
template<typename _type>
inline void read(_type &x){
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
template<typename _type1,typename _type2>void cmin(_type1 &a,const _type2 b){if(a>b)a=b;}
template<typename _type1,typename _type2>void cmax(_type1 &a,const _type2 b){if(a<b)a=b;}
const int N=1e6+15;
int T=500,B=1e9/T+1,P=1e4;
int i,j,k,n,s,t,m,p,g,cnt;
int has[N],lo[N+10],pos[N],iv[N];
gp_hash_table<int,int> mp;
struct barrett{
	ULL im;int m;
	barrett(unsigned m) :m(m), im(~0ull/m+1) {}
	int operator ()(int a,int b){
		ULL z=(ULL)a*b;
		int v=z-((__int128)z*im>>64)*m;
		return v<0?v+m:v;
	}
}bt(1);
int quick(int a,int s,int ret=1){
	while(s){
		if(s&1)ret=bt(ret,a);
		a=bt(a,a);s>>=1;
	}
	return ret;
}
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int exgcd(int &x,int &y,int a,int b){
	if(b==0){
		x=1,y=0;
		return a;
	}
	int ret=exgcd(x,y,b,a%b),tp=x;
	x=y,y=(tp-1ll*(a/b)*y%(p-1)+p-1)%(p-1);
	return ret;
}
int dispersed_log(int x){
	for(int i=0;i<T;i++){
		int tar=bt(x,iv[i]);
		auto it=mp.find(tar);
		if(it!=mp.end())return it->second+i;
	}
}
void init(){
	int pw=1,x=pw;
	for(i=0;i<T;i++){
		iv[i]=quick(pw,p-2);
		pw=bt(pw,g);
	}
	x=pw,pw=1;
	for(i=T;i<=p+T;i+=T){
		mp.insert(make_pair(pw,i-T));
		pw=bt(pw,x);
	}
} 
signed main()
{
 	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	//freopen(".in","w",stdout);
	
	read(p),read(t);int x=p-1;
	bt=barrett(p);
	for(i=2;i*i<=x;i++){
		if(x%i==0)has[++cnt]=i;
		while(x%i==0)x/=i;
	}
	if(x!=1)has[++cnt]=i;
	for(g=2;g<=p;g++){
		for(j=1;j<=cnt;j++)
		if(quick(g,(p-1)/has[j])==1)break;
		
		if(j==cnt+1)break;
	}
	init();
	for(i=1;i<=P&&i<p;i++)
	lo[i]=dispersed_log(p-i);
	//T * P * log(P) + B + P * 10^9 / B
	while(t--){
		int x,lx,ord=1e9,_a;LL ans=0;
		read(x);lx=dispersed_log(x);
		int gc=exgcd(_a,k,lx,p-1);
		int now=1,mx=1;ord=(p-1)/gc;int minp=1e9;
		for(i=1;i<=P;i++){
			if(lo[i]%gc)pos[i]=p;
			else pos[i]=1ll*_a*lo[i]/gc%ord;
			cmin(minp,pos[i]);
		}
		int lst=p;
		for(i=1;i<=P;i++){
			if(pos[i]>=lst)continue;
			ans+=1ll*(lst-pos[i])*(p-i),lst=pos[i];
		}
		for(i=0;i<minp;i++){
			ans+=mx,now=bt(now,x),cmax(mx,now);
		}
		cout<<ans<<endl;
	}
	return 0;
}
