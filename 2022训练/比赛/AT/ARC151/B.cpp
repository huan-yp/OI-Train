#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
#define int long long
#define pii pair<int,int>
using namespace std;
template<typename T>
inline int read(T &x){
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch<'0'||ch>'9'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*=f;
}
template<typename T1,typename T2>void cmin(T1 &a,const T2 &b){if(a>b)a=b;}
template<typename T1,typename T2>void cmax(T1 &a,const T2 &b){if(a<b)a=b;}
const int N=2e5+10,mod=998244353;
int i,j,n,s,t,m,ans,cnt;
int p[N],pd[N],fa[N];
int quick(int a,int s,int ret=1){
	while(s){
		if(s&1)ret=1ll*ret*a%mod;
		a=1ll*a*a%mod,s>>=1;
	}
	return ret;
}
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
void merge(int u,int v){
	u=find(u),v=find(v);
	cnt--;fa[u]=v;
}
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	read(n),read(m);cnt=n;
	for(i=1;i<=n;i++)read(p[i]),fa[i]=i;
	for(i=1;i<n;i++){
		if(find(i)==find(p[i]))continue;
		ans+=1ll*quick(m,cnt-2)*(1ll*m*(m-1)/2%mod)%mod,ans%=mod;
		merge(i,p[i]);
	}
	cout<<ans<<endl;
	return 0;
}


