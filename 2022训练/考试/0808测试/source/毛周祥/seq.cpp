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
const int N=1e6+10,mod=1e9+7;
int i,j,k,n,s,t,m;
int a[N];
struct itv{
	int l,r,val,mid;
	itv(int a,int b,int m,int v):l(a),r(b),mid(m),val(v){}
	itv():l(0){}
	int ask(int a,int b){
		cmax(a,l),cmin(b,r);
		return 1ll*(mid-a+1)*(b-mid+1)%mod*val%mod;
	}
}b[N];
int quick(int a,int s,int ret=1){
	while(s){
		if(s&1)ret=1ll*ret*a%mod;
		a=1ll*a*a%mod;s>>=1;
	}
	return ret;
}
namespace Solve{
	void solve(){
		for(i=1;i<=m;i++){
			int l,r,len,ans=0;
			read(l),read(r);len=1ll*(r-l+2)*(r-l+1)%mod;
			for(j=2*l-1;j<=2*r;j++)
			ans+=b[j].ask(l,r),ans%=mod;
			
			printf("%d\n",1ll*ans*quick(len,mod-2)%mod);
		}
	}
}
namespace Pre{
	int st[2][N],top[2],l[2][N],r[2][N];
	void init(){
		read(n),read(m);
		for(i=1;i<=n;i++){
			read(a[i]);
			while(top[0]&&a[st[0][top[0]]]>=a[i])top[0]--;
			while(top[1]&&a[st[1][top[1]]]<=a[i])top[1]--;
			l[0][i]=st[0][top[0]]+1,l[1][i]=st[1][top[1]]+1;
			st[0][++top[0]]=i;
			st[1][++top[1]]=i;
					}
		top[0]=top[1]=0;st[0][0]=st[1][0]=n+1;
		for(i=n;i>=1;i--){
			while(top[0]&&a[st[0][top[0]]]>a[i])top[0]--;
			while(top[1]&&a[st[1][top[1]]]<a[i])top[1]--;
			r[0][i]=st[0][top[0]]-1,r[1][i]=st[1][top[1]]-1;
			st[0][++top[0]]=i;
			st[1][++top[1]]=i;
			b[i*2]=itv(l[0][i],r[0][i],i,a[i]);
			b[i*2-1]=itv(l[1][i],r[1][i],i,a[i]);
		}
	}
}
signed main()
{
 	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
//	freopen(".in","w",stdout);
	Pre::init();
	Solve::solve();
	return 0;
}


