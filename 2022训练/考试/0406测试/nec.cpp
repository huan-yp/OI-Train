#include<bits/stdc++.h>
#define LL long long
#define INF 1000000000
#define y1 y3647
#define pii pair<int,int>
using namespace std;
void read(int &x){
	char ch=getchar();x=0;int f=1;
	while((ch>'9'||ch<'0')&&ch!=45)ch=getchar();
	if(ch==45)f=-1,ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	x*=f;
}
template<typename _type>void cmax(_type &x,const _type &y){x=max(x,y);}
template<typename _type>void cmin(_type &x,const _type &y){x=min(x,y);}
const int N=2e5+10,mod=1e9+7;
int i,j,k,m,n,s,t,flag;
int p[N],fa[N],f[N],inv[N],ans[N];
struct edge{
	int u,v,val;
	friend bool operator <(edge a,edge b){
		if(a.val!=b.val)return a.val>b.val;
		if(a.u!=b.u)return a.u>b.u;
		return a.v<b.v;
	}
};
struct block{
	int x,y;
}b[N];
vector<int> e[N];
vector<edge> line;
set<int> st;
int quick(int a,int s,int ret=1){
	while(s){
		if(s&1)ret=1ll*ret*a%mod;
		a=1ll*a*a%mod;s>>=1;
	}
	return ret;
}
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void dfs(int u,edge x,int fa=0){
	if(e[u].size()!=2&&fa!=0)line.push_back(x);
	for(int v:e[u]){
		if(v==fa)continue;
		if(e[u].size()==2)dfs(v,edge{x.u,v,x.val+1},u);
		else dfs(v,edge{u,v,2},u);
	}
}
void merge(int u,int v,int val){
	u=find(u),v=find(v);
	b[u].x+=b[v].x+val-2;fa[v]=u;
	b[u].y+=b[v].y-2;st.erase(v);
}
int main(){
//	freopen("nec.in","r",stdin);
//	freopen("nec.out","w",stdout);
	read(n);
	inv[0]=f[0]=1;
	for(i=1;i<=n;i++)
	f[i]=1ll*f[i-1]*i%mod,inv[i]=quick(f[i],mod-2);
	for(i=1;i<=n;i++)ans[i]=f[i],fa[i]=i;
	for(i=1;i<n;i++){
		int x,y;read(x),read(y);
		e[x].push_back(y),e[y].push_back(x);
	}
	for(i=1;i<=n;i++){
		if(e[i].size()==1){
			dfs(i,edge{i,i,1});
			break;
		}
	}
	for(auto x:line){
//		printf("%d %d %d\n",x.u,x.v,x.val);
	}
	for(i=1;i<=n;i++){
		if(e[i].size()==2)continue;
		b[i].x=1;
		st.insert(i);
	}
	for(auto x:line){
		b[x.u].y++;
		b[x.v].y++;	
	}
	sort(line.begin(),line.end());
	for(i=n-1;i>=1;i--){
		while(!line.empty()&&line.back().val<n-i)
		merge(line.back().u,line.back().v,line.back().val),line.pop_back();
		int prod=1;
		if(st.size()==1){
			ans[i]=1;
			continue;
		}
		for(int x:st)
		{
			if(i-((n-b[x].x)+b[x].y*(i-n+1))<0)printf("Boom");
			prod=1ll*prod*inv[i-(n-b[x].x)-b[x].y*(i-n+1)]%mod;
		}	
		ans[i]=1ll*ans[i]*prod%mod;
	}
	for(i=1;i<=n;i++)cout<<ans[i]<<'\n';
	return 0;
}
