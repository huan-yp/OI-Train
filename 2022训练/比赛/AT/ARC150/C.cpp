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
int a[N],b[N],dis[N];
vector<int> e[N];
priority_queue<pii,vector<pii>,greater<pii>> q;
void dij(){
	memset(dis,1,sizeof(dis));
	dis[1]=a[1]==b[1];
	q.push(make_pair(dis[1],1));
	while(!q.empty()){
		int u=q.top().second;q.pop();
		for(auto v:e[u]){
			if(dis[u]+(a[v]==b[dis[u]+1])<dis[v]){
				dis[v]=dis[u]+(a[v]==b[dis[u]+1]);
				q.push(make_pair(dis[v],v));
			}
		}
	}
}
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	read(n),read(m),read(k);
	for(i=1;i<=m;i++){
		int x,y;
		read(x),read(y);
		e[x].push_back(y);
		e[y].push_back(x);	
	}
	for(i=1;i<=n;i++)read(a[i]);
	for(i=1;i<=k;i++)read(b[i]);
	dij();
	if(dis[n]<k)puts("No");
	else puts("Yes");
	return 0;
}


