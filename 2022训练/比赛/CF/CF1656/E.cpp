#include<bits/stdc++.h>
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
template<typename _type>void cmin(_type &a,_type b){a=min(a,b);}
template<typename _type>void cmax(_type &a,_type b){a=max(a,b);}
const int N=1e6+10;
int i,j,k,n,s,t,m;
vector<int> e[N];
int val[N],fa[N],dep[N],deg[N],tar[N];
void dfs(int u){
	if(u==s)tar[u]=val[u]=0;
	else tar[u]=val[u]=dep[u]%2?1:-1;
	for(int v:e[u]){
		if(fa[u]==v)continue;
		dep[v]=dep[u]+1,fa[v]=u;dfs(v);val[u]-=tar[v];
	}
}
signed main()
{
	read(t);
	while(t--){
		read(n);dep[1]=1;s=1;
		for(i=1;i<=n;i++)e[i].clear(),val[i]=0,tar[i]=deg[i]=0,fa[i]=0;
		for(i=1;i<n;i++){
			int x,y;read(x),read(y);
			e[x].push_back(y),e[y].push_back(x);
			deg[x]++,deg[y]++;
		}
		for(i=1;i<=n;i++)if(deg[i]>deg[s])s=i;
		dfs(s);
		for(i=1;i<=n;i++)printf("%d ",val[i]);
		puts("");
		
	} 
	return 0;
}


