#include<cstdio>
#include<vector>
#include<algorithm>
#include<iostream>
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
const int N=1e5+10;
int i,j,k,n,t,m,tp1,tp2;
char s[3];
int pd[N],sz[N];
double dp[N][2];
vector<int> e[N];
bool cmp(int u,int v){
	return (dp[u][0]+2)/sz[u]<(dp[v][0]+2)/sz[v];
}
void dfs(int u){
	sz[u]=0;
	if(e[u].size()==0){
		dp[u][0]=dp[u][1]=0;sz[u]=1;
		return ;
	}
	for(int i=0;i<e[u].size();i++){
		int v=e[u][i];
		dfs(v);
		sz[u]+=sz[v];
	}
	for(int i=0;i<e[u].size();i++){
		int v=e[u][i];
		dp[u][1]+=(dp[v][1]+1)*sz[v]/sz[u];
		dp[u][0]+=(dp[v][0]+2);
	}
	sort(e[u].begin(),e[u].end(),cmp);
	if(pd[u])dp[u][0]=0;
	int siz=0;
	for(int i=0;i<e[u].size();i++){
		int v=e[u][i];
		siz+=sz[v];
		dp[u][1]+=(dp[v][0]+2)*(sz[u]-siz)/sz[u];
	}
}
signed main()
{
	freopen("street.in","r",stdin);
	freopen("street.out","w",stdout); 
	read(n);
	//if(n==0)break;
	for(i=1;i<=n;i++)e[i].clear(),dp[i][0]=dp[i][1]=0;
	//read(tp1),scanf("%s",s);
	for(i=2;i<=n;i++){
		read(tp1),scanf("%s",s);
		e[tp1].push_back(i);
		pd[i]=s[0]=='Y';
	}
	dfs(1);
	printf("%0.10lf\n",dp[1][1]);
	
	return 0;
}
