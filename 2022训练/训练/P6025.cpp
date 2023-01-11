#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
#define int long long
#define pii pair<int,int>
#define low(x) ((x)&-(x))
using namespace std;
template<typename _type>
inline void read(_type &x){
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
template<typename _type1,typename _type2>void cmin(_type1 &a,const _type2 b){if(a>b)a=b;}
template<typename _type1,typename _type2>void cmax(_type1 &a,const _type2 b){if(a<b)a=b;} 
int i,j,k,n,s,t,m,tp1,tp2;
int solve(int x){
	if(x==0)return 0;
	if(x==1)return 1;
	int res=1,h=log2(x);
	for(i=1;i<h;i++){
		res^=(1ll<<i+1)-1;
		res^=(1ll<<i+1)+1;
	}
	res^=(1ll<<h+1)-1;
	if(low(x)==x)return res;
	res^=(1ll<<h+1)+1;
	if(x-1==1ll<<h||x&1)return res;
	int now=1;
	while(__builtin_popcountll(x)>2||(x&1)==0){
		now=now<<1|1;
		x>>=1;
	}
	while(x){
		x>>=1;
		now<<=1;
	}
	now|=1;
	return res^now;
}
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	int l,r;
	read(l),read(r);
	printf("%lld\n",solve(r)^solve(l-1));
	return 0;
}


