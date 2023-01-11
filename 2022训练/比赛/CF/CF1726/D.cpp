#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
using namespace std;
template<typename _type>
inline int read(_type &x){
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch<'0'||ch>'9'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*=f;
}
template<typename _type1,typename _type2>void cmin(_type1 &a,const _type2 &b){if(a>b)a=b;}
template<typename _type1,typename _type2>void cmax(_type1 &a,const _type2 &b){if(a<b)a=b;}
const int N=2e5+10;
int i,j,k,n,s,t,m,tp1,tp2;
int a[N][2],dep[N],col[N],vis[N];
vector<pii> e[N];
int ex[5],fa[N];
void dfs(int u){
	for(auto [v,rk]:e[u]){
		if(rk==fa[u]||vis[rk])continue;
		if(fa[v]){
			vis[rk]=1;
			ex[++s]=rk;
			continue;
		}
		dep[v]=dep[u]+1,fa[v]=rk;dfs(v);
	}
}
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	read(t);
	while(t--){
		read(n),read(m);s=0;
		for(i=1;i<=n;i++)e[i].clear();
		for(i=1;i<=m;i++){
			int x,y;read(x),read(y);
			a[i][0]=x,a[i][1]=y;
			e[x].emplace_back(y,i),e[y].emplace_back(x,i);
		}
		fa[1]=-1;
		dfs(1);
		if(s<=2){
			for(i=1;i<=s;i++)
			col[ex[i]]=1;
		}
		else{
		//	sort(ex+1,ex+4,cmp);
			vector<int> v(0);
			for(i=1;i<=3;i++){
				v.push_back(a[ex[i]][0]);
				v.push_back(a[ex[i]][1]);
			}
			sort(v.begin(),v.end());
			if(v[0]==v[1]&&v[2]==v[3]&&v[4]==v[5]){
				int u1=a[ex[3]][0],u2=a[ex[3]][1];
				if(dep[u1]<dep[u2])swap(u1,u2);
				ex[3]=fa[u1];
			}
			col[ex[1]]=col[ex[2]]=col[ex[3]]=1;
		}
		for(i=1;i<=m;i++)
		printf("%d",col[i]);
		puts("");
		memset(fa,0,sizeof(int)*(n+5));
		memset(col,0,sizeof(int)*(m+5));
		memset(vis,0,sizeof(int)*(m+5));
	}
	return 0;
}


