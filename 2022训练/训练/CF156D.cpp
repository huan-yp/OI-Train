#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
using namespace std;
template<typename _type>
inline void read(_type &x)
{
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
template<typename _type>
void cmin(_type &a,_type b){a=min(a,b);}
template<typename _type>
void cmax(_type &a,_type b){a=max(a,b);}
int i,j,k,n,s,t,m,p,ans=1;
int fa[1000005],sz[1000005];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void merge(int u,int v){
	u=find(u),v=find(v);
	if(u==v)return ;
	
	fa[u]=v,sz[v]+=sz[u];
}
signed main()
{
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	read(n),read(m),read(p);
	for(i=1;i<=n;i++)fa[i]=i,sz[i]=1;
	for(i=1;i<=m;i++){
		int x,y;read(x),read(y);
		merge(x,y);
	}
	int cnt=-2;
	for(i=1;i<=n;i++){
		if(fa[i]==i)ans=1ll*ans*sz[i]%p,cnt++;
	}
	if(cnt==-1){
		printf("%d\n",1%p);
		return 0;
	}
	for(i=1;i<=cnt;i++)ans=1ll*ans*n%p;

	cout<<ans<<endl;
	return 0;
}

