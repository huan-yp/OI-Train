#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LNF 100000000000000000ll
#define LL long long
#define low(x) (x)&(-x)
#define pii pair<int,int>
using namespace std;
inline void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
template<typename _type>
void cmin(_type &a,const _type &b){a=min(a,b);}
template<typename _type>
void cmax(_type &a,const _type &b){a=max(a,b);}
const int N=2e6+10;
int i,j,k,n,s,t,m,a,b,q;
LL add;
LL val[N];
int x[N];
struct BIT{
	LL c[2][2][N],ans;
	void clear(){
		ans=LNF;
		memset(c,16,sizeof(c));
	}
	void updata(int x,const LL &cc){
		for(int i=x;i<=n;i+=low(i))
		cmin(c[0][1][i],(LL)cc-x);
		for(int i=x;i>=1;i-=low(i))
		cmin(c[1][0][i],(LL)cc+x);
		cmin(ans,(LL)cc);
	}
	void QuertPre(LL &res,int x,int op){
		for(;x;x-=low(x))cmin(res,c[0][op][x]);
	}
	void QuertSuf(LL &res,int x,int op){
		for(;x<=n;x+=low(x))cmin(res,c[1][op][x]);
	}
}T;
signed main()
{
 	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	read(n),read(q),read(a),read(b);
	read(x[1]);T.clear();
	for(i=1;i<=n;i++){
		val[i]=min(abs(b-i)+abs(x[1]-a),abs(a-i)+abs(x[1]-b));
		T.updata(i,val[i]);
	}
	
	for(i=2;i<=q;i++){
		read(x[i]);int gap=abs(x[i]-x[i-1]);
		LL dp=LNF;LL res;
		if(x[i]<x[i-1]){
			res=LNF;T.QuertSuf(res,x[i],0);cmin(dp,res-x[i]);
			res=LNF;T.QuertPre(res,x[i],1);cmin(dp,res+x[i]);
		}
		else{
			res=LNF;T.QuertSuf(res,x[i],0);cmin(dp,res-x[i]);
			res=LNF;T.QuertPre(res,x[i],1);cmin(dp,res+x[i]);
		}
		add+=gap;
		T.updata(x[i-1],dp-gap);
	}
	printf("%lld\n",T.ans+add);
	return 0;
}
