#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
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
void cmin(int &a,int b){a=min(a,b);}
void cmax(int &a,int b){a=max(a,b);}
const int N=55,mod=1e9+7;
int i,j,k,n,s,t,m,ans,flag;
char ch[N][N];
int rk[N][N],x[N],y[N],fa[N*N],size[N*N],ok[N*N],se[N*N],pd[N][N];
int find(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void merge(int u,int v)
{
	if(u==v)se[find(u)]=0;
	u=find(u),v=find(v);
	if(u==v)
	{
		if(ok[u])ok[u]=0;
		else flag=1;
		return ;
	}
	if(ok[u]==0&&ok[v]==0)flag=1;
	size[u]+=size[v];
	fa[v]=u,ok[u]&=ok[v],se[u]&=se[v];
}
void calc()
{
	flag=0;int sum=1;
	for(i=1;i<=n*m;i++)
	fa[i]=i,ok[i]=1,size[i]=1,se[i]=1;
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	{
		if(pd[i][j]==0)continue;
		if(i==1||pd[i-1][j])merge(rk[i][j],rk[i][j]);
		if(j==1||pd[i][j-1])merge(rk[i][j],rk[i][j]);
		if(j==m||pd[i][j+1])merge(rk[i][j],rk[i][j]);
		if(i==n||pd[i+1][j])merge(rk[i][j],rk[i][j]);
		if(pd[i+2][j]==1)
		merge(rk[i][j],rk[i+2][j]);
		if(pd[i][j+2]==1)
		merge(rk[i][j],rk[i][j+2]);
		if(pd[i+1][j+1]==1)
		merge(rk[i][j],rk[i+1][j+1]),merge(rk[i][j],rk[i+1][j+1]);
		if(pd[i+1][j-1]==1)
		merge(rk[i][j],rk[i+1][j-1]),merge(rk[i][j],rk[i+1][j-1]);
	}
	if(flag)return;
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	{
		if(pd[i][j]==0||find(rk[i][j])!=rk[i][j])continue;
		if(ok[rk[i][j]]==0)sum=(1ll+(se[rk[i][j]]==1))*sum%mod;
		else sum=1ll*(size[rk[i][j]]*3+1)*sum%mod; 
	}
	ans+=sum,ans%=mod;
}
signed main()
{
	read(n),read(m);
	for(i=1;i<=n;i++)
	scanf("%s",ch[i]+1);
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	{
		rk[i][j]=(i-1)*m+j;
		if(ch[i][j]=='*')x[s]=i,y[s++]=j;
		if(ch[i][j]=='o')pd[i][j]=1;
	}
	for(int mask=0;mask<1<<s;mask++)
	{
		for(i=0;i<s;i++)
		if(1<<i&mask)
		pd[x[i]][y[i]]=1;
		else
		pd[x[i]][y[i]]=0;
		calc();
	}
	cout<<ans<<endl;
	return 0;
}

