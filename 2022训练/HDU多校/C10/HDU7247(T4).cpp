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
const int N=1e5+10;
int i,j,k,n,s,t,m,tp1,tp2;
int e[N][2],fa[N],sz[N],d[N];
long double ans[N],a[N];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void merge(int u,int v){
	u=find(u),v=find(v);
	if(u==v)return ;
	fa[v]=u;sz[u]+=sz[v];
}
signed main()
{
// 	freopen("in","r",stdin);
//	freopen("out","w",stdout);
//	freopen(".in","w",stdout);
	scanf("%d",&t);
	while(t--){
		read(n),read(m);k=0;
		for(i=1;i<=n;i++)
		read(tp1),a[i]=tp1,sz[i]=0,d[i]=0,ans[i]=0;
		
		for(i=1;i<=m;i++){
			read(e[i][0]),read(e[i][1]);
			sz[e[i][0]]++,sz[e[i][1]]++;
		}
		for(i=1;i<=n;i++)fa[i]=i,sz[i]++,d[i]=sz[i];
		for(i=1;i<=m;i++)
		merge(e[i][0],e[i][1]);
		
		for(i=1;i<=n;i++){
			ans[find(i)]+=a[i]*d[i]/sz[find(i)];
		}
		for(i=1;i<=n;i++)
		printf("%0.6lf\n",double(ans[find(i)]));
	}
	return 0;
}
