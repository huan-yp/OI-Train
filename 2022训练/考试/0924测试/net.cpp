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
template<typename T1,typename T2>void cmax(T1 &a,const T2 &b){if(b>a)a=b;}
template<typename T1,typename T2>void cmin(T1 &a,const T2 &b){if(b<a)a=b;}
const int N=2560;
int i,j,k,m,n,s,t,ans=1e9,cnt;
int dis[N][N],ae[N][2],vis[N],a[N];
char ch[N][N];
bitset<N> mp[N],ok1[N],ok2[N];
vector<int> e[N];
namespace DIS{
	int rt,maxn,dis[N];
	void dfs(int u,int fa=0){
		cmax(maxn,dis[u]);
		for(auto v:e[u]){
			if(v==fa)continue;
			dis[v]=dis[u]+1,dfs(v,u);
		}
		if(dis[u]>dis[rt])rt=u;
	}
	void solve(){
		maxn=0;rt=0;
		dfs(dis[1]=1);dis[rt]=1;
		dfs(rt);
		if(ans>dis[rt]){
			ans=dis[rt];cnt=0;
			for(i=1;i<=n;i++)
			for(auto v:e[i])if(v<i)
			ae[++cnt][0]=v,ae[cnt][1]=i;
		}
	}
}
void solve(int x){
	for(int i=1;i<=n;i++)e[i].clear(),dis[x][i]=1e9;
	dis[x][x]=1;int cnt=0;
	bitset<N>now;now.reset();
	for(int i=1;i<=n;i++)now[i]=1;
	queue<int>q;q.push(x);now[x]=0;
	while(!q.empty()){
		cnt++;
		int u=q.front();q.pop();
		auto ok=mp[u]&now;
		A:
		int p=ok._Find_next(0);
		if(p==N)continue;
		dis[x][p]=dis[x][u]+1,now[p]=0;q.push(p);
		e[u].push_back(p),e[p].push_back(u);
		ok[p]=0;
		goto A;
	}
	DIS::solve();
}
int check(int x){
	for(i=1;i<=n;i++)for(j=1;j<=n;j++)
	ok1[i][j]=dis[i][j]<=x>>1;
	for(i=1;i<=n&&x%2==0;i++)for(j=i+1;j<=n;j++)if(mp[i][j]&&(ok1[i]|ok1[j]).count()==n){
		cnt=0;using DIS::dis;memset(dis,1,sizeof(dis));dis[i]=dis[j]=0;
		queue<int> q;ae[++cnt][0]=i,ae[cnt][1]=j;q.push(i),q.push(j);
		while(!q.empty()){
			int u=q.front();q.pop();
			for(i=1;i<=n;i++)if(mp[u][i]&&dis[i]>dis[u]+1){
				q.push(i),dis[i]=dis[u]+1;
				ae[++cnt][0]=u,ae[cnt][1]=i;
			}
		}
		return 1;
	}
	return 0;
}
int main(){
//	freopen("net.in","r",stdin);
//	freopen("net.out","w",stdout);
	//freopen(".in","w",stdout);
	read(n);
	if(n==1){puts("");return 0;}
	for(i=1;i<=n;i++){
		scanf("%s",ch[i]+1);
		for(j=1;j<=n;j++)if(ch[i][j]=='1')
		mp[i][j]=1;
	}
	for(int i=1;i<=n;i++)solve(i);
	check(ans-1);
	for(i=1;i<=cnt;i++)cout<<ae[i][0]<<' '<<ae[i][1]<<endl;
	return 0;
}


