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
const int N=2e6+10;
struct edge{
	int v,s1,s2;
};
int i,j,k,m,n,s,t,len,ok,flag,top;
int fa[N],col[N],dep[N],st[N];
char ch[N],str[N][2];
vector<int> e[1][N];
vector<tuple<int,int,int>> a[N];
void predfs(int u){
	for(int v:e[0][u]){
		if(fa[u]==v)continue;
		dep[v]=dep[u]+1,fa[v]=u,predfs(v);
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	while(dep[x]!=dep[y])x=fa[x];
	while(x!=y)x=fa[x],y=fa[y];
	return x;
}
void insert(int u,char c1,char c2){
	if(str[u][0]==0)str[u][0]=c1,str[u][1]=c2;
	if(c1!=str[u][0])a[i+n].emplace_back(u,0,1),a[u].emplace_back(i+n,0,1);
	if(c1!=str[u][1])a[i+n].emplace_back(u,0,0),a[u].emplace_back(i+n,1,1);
	if(c2!=str[u][0])a[i+n].emplace_back(u,1,1),a[u].emplace_back(i+n,0,0);
	if(c2!=str[u][1])a[i+n].emplace_back(u,1,0),a[u].emplace_back(i+n,1,0);
}
void jump1(int start,int end,int inc){
	insert(start,ch[inc],ch[len-inc+1]);
	if(start==end)return ;
	jump1(fa[start],end,inc+1);
}
void jump2(int start,int end,int inc){
	if(start==end)return ;
	insert(start,ch[len-inc+1],ch[inc]);
	jump2(fa[start],end,inc+1);
}
void dfs(int u){
	st[++top]=u;
	for(auto [v,x1,x2]:a[u]){
		if(col[u]!=x1)continue;
		if(col[v]==-1){
			col[v]=x2;
			dfs(v);
			continue;
		}
		if(col[v]!=x2)ok=0;
	}
}
signed main()
{
 	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	memset(col,-1,sizeof(col));
	read(n),read(m);
	for(i=1;i<n;i++){
		int x,y;read(x),read(y);
		e[0][x].push_back(y),e[0][y].push_back(x);
	}
	predfs(1);
	for(i=1;i<=m;i++){
		int x,y;read(x),read(y);
		scanf("%s",ch+1);len=strlen(ch+1);
		int lc=lca(x,y);jump1(x,lc,1);jump2(y,lc,1);
	}
	for(i=1;i<=m;i++){
		if(col[i+n]!=-1)continue;
		ok=1,top=col[i+n]=0,dfs(i+n);
		if(ok==0){
			while(top)col[st[top--]]=-1;
			ok=1,col[i+n]=1;dfs(i+n);
			if(ok==0)flag=1;
		}
	}
	if(flag){
		puts("NO");
		return 0;
	}
	puts("YES");
	for(i=1;i<=n;i++)if(col[i]==-1)col[i]=0;
	for(i=1;i<=n;i++)
	putchar(str[i][col[i]]!=0?str[i][col[i]]:'a');
	puts("");
	return 0;
}
