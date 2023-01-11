#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define y1 y3647
#define next nxt
#define LL long long
using namespace std;
inline void read(int &x)
{
	x=0;int f=1;
	char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}
	x*=f;
}
int i,j,k,n,s,t,m,cnt0,cnt1,cnt2,val,maxn,root;
const int N=2500+10;
int fa[N*2],size1[N*2],size2[N*2],f[N*2];
char ch[N][N];
vector <int> e[N*2]; 
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}  
void put(int u,int v)
{
	u=find(u),v=find(v);
	if(u==v)return;
	e[i].push_back(j+n),e[j+n].push_back(i);
	fa[u]=v,size1[v]+=size1[u],size2[v]+=size2[u];
}
int calc(int x,int y)
{
	if(x<0||y<0) return -1;
	return x*m+y*n-x*y;
}
void dfs(int u,int fa,int op)
{
	if(op==1&&u<=n)root=u;
	if(op==2&&u>n)root=u;
	for(int v:e[u])
	{
		if(v==fa)continue;
		dfs(v,u,op);
	}
}
void dfs(int u)
{
	for(int v:e[u])
	{
		if(v==f[u])continue;
		f[v]=u;
		dfs(v);		 
	}
	if(u==root)return;
	if(u<=n)
	printf("X %d %d\n",u,f[u]-n);
	else
	printf("Y %d %d\n",f[u],u-n);
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	scanf("%s",ch[i]+1);
	for(i=1;i<=n+m;i++)fa[i]=i,size1[i]=(i<=n),size2[i]=(i>n);
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	{
		if(ch[i][j]=='B')continue;
		put(i,j+n); 
	}
	for(i=1;i<=n+m;i++)
	{
		if(fa[i]^i||size1[i]+size2[i]==1)continue;
		cnt1+=size1[i],cnt2+=size2[i],cnt0++; 
	}
	for(i=0;i<=cnt0;i++)
	{
		if(calc(cnt1-i,cnt2-cnt0+i)>val)
		maxn=i,val=calc(cnt1-i,cnt2-cnt0+i);
	}
	printf("%d\n",cnt1+cnt2-cnt0);
	for(i=1;i<=n+m;i++)
	{
		if(fa[i]^i||size1[i]+size2[i]==1)continue;
		t++;
		dfs(i,0,(maxn>=t)?1:2);
		dfs(root);
	}
	memset(fa,0,sizeof(fa));
	return 0;
}


