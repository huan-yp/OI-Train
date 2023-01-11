#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
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
int i,j,k,n,s,t,m,tp1,tp2,mod;
struct Element{
	int p=1,isp=0,len=0,sp=1;
	Element operator *(const Element &a){
		Element res;
		res.len=len+a.len;
		res.p=1ll*p*a.p%mod;
		res.isp=(isp+1ll*a.isp*p+1ll*a.sp*p%mod*len)%mod;
		res.sp=(sp+1ll*a.sp*p)%mod;
		return res;
	}
};
void Inc(int &x,const int &y){
	x+=y;x-=(x>=mod)*mod;
}
auto quick(auto a,int s){
	Element ret;
	while(s){
		if(s&1)ret=ret*a;
		a=a*a,s>>=1;
	}
	return ret;
}
signed main()
{
	freopen("hamburger.in","r",stdin);
	freopen("hamburger.out","w",stdout);
//	freopen(".in","w",stdout);
	read(t);
	while(t--){
		int p,q;
		read(p),read(q),read(n),read(mod);
		Element rp,rq;
		rp.p=p,rp.len=1,rp.sp=p,rp.isp=p;
		rq.p=q,rq.len=1,rq.sp=q,rq.isp=q;
		rp=quick(rp,n),rq=quick(rq,n);
		int sp,sq,isq,isp;
		sp=rp.sp,isp=rp.isp;
		sq=rq.sp,isq=rq.isp;
		int ans=0;
		Inc(ans,1ll*sp*sq%mod),Inc(ans,1ll*isp*sq%mod);
		Inc(ans,1ll*sp*isq%mod),Inc(ans,1ll*isp*isq%mod);
		cout<<(ans-1+mod)%mod<<endl;
	}
	return 0;
}


