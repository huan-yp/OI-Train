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
const int N=3e5+10;
int i,j,k,n,s,t,m,tp1,tp2,b,ans;
int dep[N],fa[N],dp[N],a[N],minu[N];
vector<int> e[N];
void predfs(int u){
	for(auto v:e[u]){
		if(fa[u]==v)continue;
		fa[v]=u;dep[v]=dep[u]+1;
		predfs(v);
	}
	if(dep[u]>dep[t])t=u;
}
void redfs(int u){
	for(auto v:e[u]){
		if(fa[u]==v)continue;
		fa[v]=u;dep[v]=dep[u]+1;
		redfs(v);cmax(dp[u],dp[v]+1);
	}
	if(dep[u]>dep[b])b=u;
}
int calc(int idx,int op){
	if(op)idx=m-idx+1;
	int res=0,u=a[idx];
	for(auto v:e[u]){
		if(v==a[idx+1]||v==a[idx-1])continue;
		cmax(res,dp[v]+1);
	}
	return res;
}
void check(int op=0){
	int min_a=INF,add=0,lst=m;set<int>st;
	st.clear();st.insert(0);minu[m]=0;
	for(i=m-1;i>=1;i--){
		int len=calc(i,op);
		st.insert((len+lst-i)-add);
		while(m-lst<*st.rbegin()+add){
			lst--,add--;
		}
		minu[i]=m-lst+(*st.rbegin()+add);
	}
	st.clear();st.insert(add=0);lst=1;
	for(i=1;i<m;i++){
		int len=calc(i,op);
		st.insert((len+i-lst)-add);
		while(lst-1<*st.rbegin()+add){
			lst++,add--;
		}
		len=lst-1+*st.rbegin()+add;
		cmin(ans,max(max(minu[i+1],len),(len+1)/2+(minu[i+1]+1)/2+1));
	}
}
void lit(int u){
	do a[dep[b]+1-(++m)]=u,u=fa[u]; while(u);
}
signed main()
{
	freopen("rebuild.in","r",stdin);
	freopen("rebuild.out","w",stdout);
//	freopen(".in","w",stdout);
	read(n);
	if(n==1){
		printf("0\n");
		return 0;
	}
	for(i=1;i<n;i++){
		int x,y;read(x),read(y);
		e[x].push_back(y),e[y].push_back(x);
	}
	predfs(dep[1]=1);
	fa[t]=0,dep[t]=1,redfs(t);
	ans=dep[b]-1;lit(b);
	check();
	cout<<ans<<endl;
	return 0;
}
