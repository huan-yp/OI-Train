#include<bits/stdc++.h>
using namespace std;
template<typename T>
int read(T &x){
	x=0;char ch=getchar();int f=1;
	while((ch<'0'||ch>'9')&&ch!=45)ch=getchar();
	if(ch==45)ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	return x*=f;
}
template<typename T1,typename T2>void cmax(T1 &x,const T2 &y){if(y>x)x=y;}
template<typename T1,typename T2>void cmin(T1 &x,const T2 &y){if(y<x)x=y;}
const int N=2e5+10,mod=998244353;
int i,j,k,m,n,s,t;
int pd[N],p[N],fa[N],sz[N],a[N],ans[N],f[N];
vector<int> e[N];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void dfs(int u,int c,int fa=0){
	if(c==1)a[++s]=u;
	pd[u]=c;
	for(auto v:e[u]){
		if(v==fa)continue ;
		dfs(v,c,u);
	}
}
void solve(int w){
	s=0;dfs(w,1,f[w]);
	sort(a+1,a+s+1);int lst=0,now=0;
	for(i=1;i<=s;i++)fa[a[i]]=a[i],sz[a[i]]=1;
	for(i=s;i>=1;i--){
		now++;
		for(auto v:e[a[i]])if(pd[v]&&v>a[i]){
			int rv=find(v),ru=find(a[i]);
			now=(now-p[sz[rv]]+1)%mod;now=(now-p[sz[ru]]+1)%mod;
			fa[rv]=ru,sz[ru]+=sz[rv];
			now=(now+p[sz[ru]]-1)%mod;
		}
		ans[w]=(1ll*a[i]*(now-lst)+ans[w])%mod;
		lst=now;
	}
	ans[w]=(ans[w]+mod)%mod;
	dfs(w,0,f[w]);
	for(i=1;i<=s;i++)fa[a[i]]=a[i],sz[a[i]]=1;
}
int main(){
//	freopen("t.in","r",stdin);
//	freopen("t.out","w",stdout);
	//freopen(".in","w",stdout);
	read(n);p[0] =1;
	for(i=1;i<=n;i++)p[i]=p[i-1]*2%mod;
	for(i=2;i<=n;i++){
		e[read(f[i])].push_back(i);
		e[i].push_back(f[i]);
	}
	for(int i=1;i<=n;i++){
		solve(i);
		cout<<ans[i]<<' ';
	}
	return 0;
}

