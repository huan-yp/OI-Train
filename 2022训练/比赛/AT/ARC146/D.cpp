#include<bits/stdc++.h>
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
const int N=8e5+10;
int i,j,k,n,s,t,m,tp1,tp2;
int val[N],vis[N],a[N];
vector<int> e[N],c[N];
void construct(int p,int v){
	val[++s]=v;c[p].push_back(s);
}
bool cmp(int a,int b){
	return val[a]<val[b];
}
void dfs(int u){
	for(auto v:e[u]){
		if(vis[v])continue;
		vis[v]=1;dfs(v);
	}
}
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	read(n),read(m),read(k);
	for(i=1;i<=k;i++){
		int p,x,q,y;read(p),read(x),read(q),read(y);
		construct(p,x);
		construct(q,y);
		e[s].push_back(s-1),e[s-1].push_back(s);
		construct(p,x-1);
		construct(q,y-1);
		e[s].push_back(s-1),e[s-1].push_back(s);
	}
	for(i=1;i<=n;i++){
		sort(c[i].begin(),c[i].end(),cmp);
		if(c[i].begin()==c[i].end())continue;
		for(j=0;j<c[i].size()-1;j++){
			e[c[i][j+1]].push_back(c[i][j]);	
			if(val[c[i][j+1]]==val[c[i][j]])
			e[c[i][j]].push_back(c[i][j+1]);
		}
	}
	for(i=1;i<=s;i++){
		if(vis[i]||val[i]!=0)continue;
		vis[i]=1;dfs(i);
	}
	LL sum=0,flag=0;
	for(i=1;i<=n;i++){
		a[i]=1;
		for(auto rk:c[i]){
			if(vis[rk]==0)continue;
			cmax(a[i],val[rk]+1);
		}
		if(a[i]>m)flag=1;
		sum+=a[i];
	}
	if(flag) puts("-1");
	else cout<<sum<<endl;
	return 0;
}


