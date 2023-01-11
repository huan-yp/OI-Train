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
int fa[N],dep[N],val[N];
char ch[N];
vector<int>e[N];
void dfs(int u){
	for(int v:e[u]){
		if(fa[u]==v)continue;fa[v]=u;
		dfs(v);cmax(dep[u],dep[v]+1);
	}
	if(ch[u]=='W')val[dep[u]]^=1;
}
signed main()
{
 	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	read(t);
	while(t--){
		read(n);
		scanf("%s",ch+1);
		for(i=0;i<=n;i++)dep[i]=0,val[i]=0,e[i].clear();
		for(i=1;i<n;i++){
			int x,y;read(x),read(y);
			e[x].push_back(y),e[y].push_back(x);
		}
		dfs(1);
		int flag=0;
		for(i=0;i<=n;i++)if(val[i])flag=1;
		if(flag)puts("Xiao");
		else puts("AI");
		
	}

	return 0;
}

