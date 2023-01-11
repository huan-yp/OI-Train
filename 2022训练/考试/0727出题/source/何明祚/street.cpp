#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define pb(x) push_back(x)
#define lowbit(x) x&-x
using namespace std;
const int N=1e5+10;
struct node{
	int to,nxt;
}a[N];
ll ans;
vi son[N];
char typ[N];
int n,m,T,siz[N],head[N],cnt;
double dp[2][N];//0:在子树内，1:不在子树内 
inline int read(){
	int s=0,f=0;
	char ch=getchar();
	while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
	while(ch<='9'&&ch>='0') s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return f?-s:s;
}
inline bool cmp(int a1,int a2){
	return (dp[1][a1]+2)/siz[a1]<(dp[1][a2]+2)/siz[a2];
}
void dfs(int x,int fa){
	siz[x]=1;
	if(!head[x]) return ;
	siz[x]=0;
	for(register int i=head[x];i;i=a[i].nxt){
		int to=a[i].to;
		if(to==fa) continue;
		dfs(to,x);
		siz[x]+=siz[to];
	}
	sort(son[x].begin(),son[x].end(),cmp);
	for(register int i=0;i<son[x].size();++i){
		int to=son[x][i];
		if(to==fa) continue;
		dp[0][x]=dp[0][x]+(dp[0][to]+dp[1][x]+1.0)*siz[to]/siz[x];
		dp[1][x]=dp[1][x]+dp[1][to]+2.0;
	}
	if(typ[x]=='Y') dp[1][x]=0.0;
	return ;
}
inline void add(int from,int to){
	a[++cnt]=(node){to,head[from]};
	head[from]=cnt;
}
int main(){
	freopen("street.in","r",stdin);
	freopen("street.out","w",stdout);
	n=read();
	for(register int i=2;i<=n;++i){
		int fa=read();
		cin>>typ[i];
		add(fa,i);
		son[fa].pb(i);
	}
	dfs(1,0);
	cout<<fixed<<setprecision(10)<<dp[0][1];
	return 0;
}
