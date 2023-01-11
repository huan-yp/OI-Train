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
const int N=2e5+10;
int i,j,k,n,s,t,m,tp1,tp2,ans;
int fa[N];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
struct edge{
	int u,v,val,pd;
	friend bool operator <(const edge &a,const edge &b){
		return a.val>b.val;
	}
	void init(){
		val=i;
		read(u),read(v);
	}
	int merge(){
		u=find(u),v=find(v);
		if(u==v)return false;
		fa[u]=v;pd=1;
		return true;
	}
}a[N];
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	read(t);
	while(t--){
		memset(a,0,sizeof(a));
		read(n),read(m);ans=m+1;
		for(i=1;i<=m;i++)
		a[i].init();
		for(i=1;i<=n;i++)fa[i]=i;
		sort(a+1,a+m+1);
		for(i=1;i<=m;i++){
			ans-=a[i].merge();
		}
		printf("%d\n",ans-1);
		for(i=m;i>=1;i--){
			if(a[i].pd)continue;
			printf("%d ",a[i].val);
			ans--;
			if(ans==0)break;	
		}
		cout<<endl;
	}
	return 0;
}


