#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
#define int long long
#define pii pair<int,int>
#define low(x)  ((x)&(-x))
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
const int N=1e6+10;
int i,j,k,n,s,t,m;
int a[N],S[N],cnt[N],ans[N];
struct BIT{
	int c[N];
	void updata(int x,int cc){
		if(x==0){c[0]+=cc;return ;}
		for(;x<=n+3;x+=low(x))c[x]+=cc;
	}
	int quert(int x,int ret=0){
		if(x<0)return 0;
		for(;x;x-=low(x))ret+=c[x];
		return ret+c[0];
	}
	void clear(){
		memset(c,0,sizeof(c));
	}
}B,T;
struct oper{
	int rk,r,d;
}op[N];
vector<int> e[N];
signed main()
{
 	//freopen("seq.in","r",stdin);
	//freopen("seq.out","w",stdout);
	//freopen(".in","w",stdout)
	read(n);
	for(i=1;i<=n;i++){
		read(a[i]),S[i]=S[i-1]+a[i];
		read(op[i].r),read(op[i].d);
		e[op[i].r].push_back(i);	
	}
	for(i=n;i>=1;i--){
		for(auto v:e[i]){
			ans[v]+=T.quert(op[v].d-1);
			cnt[v]-=B.quert(op[v].d-1);
		}
		B.updata(op[i].r-i,1);
		T.updata(op[i].r-i,S[i-1]);
		ans[i]-=T.quert(op[i].d-1);		
		cnt[i]+=B.quert(op[i].d-1);
	}
	T.clear(),B.clear();
	for(i=n;i>=1;i--){
		B.updata(op[i].r-i,1);
		T.updata(op[i].r-i,S[op[i].r]);
		if(op[i].r-i<op[i].d)continue;
		ans[i]+=T.quert(op[i].d-1);
		cnt[i]-=B.quert(op[i].d-1);
	}
	B.clear(),T.clear();
	for(i=n;i>=1;i--){
		for(auto v:e[i]){
			B.updata(op[v].r-v,1);
			T.updata(op[v].r-v,S[op[v].r]);
		}
		for(auto v:e[i]){
			if(op[v].r-v<op[v].d)continue;
			ans[v]-=T.quert(op[v].d-1);
			cnt[v]+=B.quert(op[v].d-1);
		}
	}
	T.clear(),B.clear();
	for(i=n;i>=1;i--){
		T.updata(op[i].r,S[op[i].r]),B.updata(op[i].r,1);
		if(op[i].r-i>=op[i].d)continue;
		ans[i]+=T.quert(op[i].r),cnt[i]-=B.quert(op[i].r);
	}
	for(i=1;i<=n;i++)ans[i]+=cnt[i]*S[op[i].r];
	for(i=1;i<=n;i++)printf("%lld\n",ans[i]);
	return 0;
}

