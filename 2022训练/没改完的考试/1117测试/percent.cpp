#include<bits/stdc++.h>
#define INF 1000000000
#define LL long long
//#define DEBUG
using namespace std;
template<typename T>
void read(T &x){
	x=0;char ch=getchar();int f=1;
	while((ch<'0'||ch>'9')&&ch!=45)ch=getchar();
	if(ch==45)ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
template<typename T1,typename T2>void cmin(T1 &x,const T2 &y){if(y<x)x=y;}
template<typename T1,typename T2>void cmax(T1 &x,const T2 &y){if(y>x)x=y;}
#ifdef DEBUG
const int N=405+10;
#else
const int N=4e5+10;
#endif
int i,j,k,m,n,s,t,cnt;
int fa[N][20],st[N],rk[N],dep[N],p[N][2];
char ch[N];
vector<int> e[N];
struct DP{
	int val[2][2];
	DP(){val[0][1]=val[1][0]=1;val[0][0]=val[1][1]=0;}
	void check(){
		for(int i=0;i<=1;i++)
		cmin(val[i][1],val[i][0]+1),cmin(val[i][0],val[i][1]+1);
	}
	friend DP operator +(const DP &a,const DP &b){
		DP res;
		for(int i=0;i<=1;i++)
		for(int j=0;j<=1;j++)
		res.val[i][j]=min(a.val[i][1]+b.val[1][j],a.val[i][0]+b.val[0][j]);	
		res.check();
		return res;
	}
	DP reverse()const{
		auto res=*this;
		swap(res.val[0][1],res.val[1][0]);
		return res;
	}
}dp[N][20];
void dfs(int u){
	for(i=1;i<=19;i++){
		fa[u][i]=fa[fa[u][i-1]][i-1];
		dp[u][i]=dp[u][i-1]+dp[fa[u][i-1]][i-1];
	}
	for(int i=0;i<e[u].size();i++){
		int v=e[u][i];
		fa[v][0]=u;dep[v]=dep[u]+1;
		dp[v][0].val[0][0]=1+i*2;
		dp[v][0].val[0][1]=(e[u].size()-i)*2;
		dp[v][0].val[1][0]=2+i*2;
		dp[v][0].val[1][1]=(e[u].size()-i)*2-1;
		dp[v][0].check();
		dfs(v);
	}
}
int lca(int x,int y){
	if(dep[y]>dep[x])swap(x,y);
	int p=dep[x]-dep[y];
	for(int i=0;i<19;i++)if(1<<i&p)
	x=fa[x][i];
	if(x==y)return x;
	for(int i=18;i>=0;i--)if(fa[x][i]!=fa[y][i])
	x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
pair<int,DP> jump(int x,int step){
	DP res;
	for(int i=0;i<19;i++)if(1<<i&step)
	res=res+dp[x][i],x=fa[x][i];
	return make_pair(x,res);
}
int get_pos(const vector<int> &v,int x){
	return lower_bound(v.begin(),v.end(),x)-v.begin();
}
DP distance(int x,int y,int u){
	int p1=get_pos(e[u],x),p2=get_pos(e[u],y);
	DP r;
	r.val[1][0]=abs((p1*2+1)-(p2*2));
	r.val[1][1]=abs((p1*2+1)-(p2*2+1));
	r.val[0][0]=abs((p1*2)-(p2*2));
	r.val[0][1]=abs((p1*2)-(p2*2+1));
	return r;
}
int main(){
	freopen("percent.in","r",stdin);
	freopen("percent.out","w",stdout);
//	auto start=clock();
	scanf("%s",ch+1);
	
	n=strlen(ch+1);
	rk[0]=++cnt;dep[1]=1;
	for(int i=1,top=0;i<=n;i++){
		if(ch[i]=='(')
		rk[i]=++cnt,st[++top]=i,p[rk[i]][0]=i;
		else
		rk[i]=rk[st[top--]],p[rk[i]][1]=i,e[rk[st[top]]].push_back(rk[i]);
	}
	dfs(1);
	read(m);
	
	for(i=1;i<=m;i++){
		int x,y,lc,ox,oy;
		read(x),read(y);
		if(x==y){
			puts("0");
			continue;
		}
		ox=p[rk[x]][1]==x,oy=p[rk[y]][1]==y;
		x=rk[x],y=rk[y];
		if(x==y){
			puts("1");
			continue;
		}
		if(dep[x]<dep[y])swap(x,y),swap(ox,oy);
		lc=lca(x,y);
		if(lc==y){
			DP res=jump(x,dep[x]-dep[y]).second;
			printf("%d\n",res.val[ox][oy]);
			continue;
		}
		auto w1=jump(x,dep[x]-dep[lc]-1),w2=jump(y,dep[y]-dep[lc]-1);
		auto d1=w1.second,d2=w2.second;
		int u1=w1.first,u2=w2.first;
		int ans=lc!=1?((d1+dp[u1][0])+(d2+dp[u2][0]).reverse()).val[ox][oy]:INF;
		d2=d2.reverse();
		auto d=distance(u1,u2,lc);
		cmin(ans,(d1+d+d2).val[ox][oy]);
		printf("%d\n",ans);
	}
//	cout<<clock()-start<<endl;
	return 0;
}

