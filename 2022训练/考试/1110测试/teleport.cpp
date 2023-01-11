#include<bits/stdc++.h>
#define y1 y36
#define INF 1000000000
//#define VEC
#define LINK
#define PC
//#define CO
#define QUE
using namespace std;
namespace FAST_READ{
	const int MAX_BUF=1<<20;
	char buf[MAX_BUF+10],*p1=buf,*p2=buf;
	#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,MAX_BUF,stdin),p1==p2)?EOF:*p1++)
	int read(){
		int x=0;char ch=gc();
		while(ch<'0'||ch>'9')ch=gc();
		while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=gc();
		return x;
	}
}
template<typename T1,typename T2>void cmin(T1 &x,const T2 &y){if(y<x)x=y;}
template<typename T1,typename T2>void cmax(T1 &x,const T2 &y){if(y>x)x=y;}
const int N=1e6+10;
int i,j,k,m,n,s,t;
#ifdef VEC
vector<int> e[N];
#else
struct {
	int next,v;
}a[N*2];
int head[N];
#endif
int dis[N][2],fa[N],q[N<<1];
void bfs(int x){
	int tail=1,h=1;
	q[tail++]=x;dis[x][0]=1;
	while(tail!=h){
		int u=q[h++];
		#ifdef VEC
		for(auto v:e[u])for(int d:{0,1}){
		#else
		for(int i=head[u];~i;i=a[i].next)for(int d:{0,1}){
			int v=a[i].v;
		#endif
			if(dis[v][d^1]||!dis[u][d])continue;
			dis[v][d^1]=1;q[tail++]=v;
		}
	}
}
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
string ans;
void puts(string str){
	#ifdef CO
	ans+=str;
	#else
	for(char c:str)putchar(c);
	#endif
}
int main(){
//	freopen("teleport.in","r",stdin);
//	freopen("teleport.out","w",stdout);
	using FAST_READ::read;
	#ifdef LINK
	memset(head,-1,sizeof(head));
	#endif
	read();n=read(),m=read();
	for(i=1;i<=n;i++)fa[i]=i;
	for(i=1;i<=m;i++){
		int x=read(),y=read();
		#ifdef VEC
		e[x].push_back(y),e[y].push_back(x);
		#else
		a[k].next=head[x];a[k].v=y;head[x]=k++;
		a[k].next=head[y];a[k].v=x;head[y]=k++;
		#endif
		fa[find(x)]=find(y);
	}
	for(i=1;i<=n;i++){
		if(fa[i]!=i)continue;
		bfs(i);
	}
	m=read();
	for(i=1;i<=m;i++){
		int x=read(),y=read();
		int rt=find(x);
		if(x==y){puts("0");continue;}
		if(find(y)!=rt){puts("-1");continue;}
		if(dis[x][0]&&dis[y][1]||dis[x][1]&&dis[y][0])puts("1");
		else puts("2");
	}
	#ifdef CO
	cout<<ans<<endl;
	#endif
	return 0;
}

