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
void cmin(int &a,int b)
{
	a=min(a,b);
}
void cmax(int &a,int b)
{
	a=max(a,b);
}
/*
2 2
24/4=6;
6-
abab
baba
*/
const int N=1000005,mod=1e9+7;
int i,j,k,n,s,t=1,m,lst=1,minu=N;
int val[N][3];
LL ans[N],c[N];
char ch[N];
struct SAM{
	int len,fa,ch[28];
}a[N];
vector<int> e[N];
void add(int c)
{
	int np=++t;a[np].len=a[lst].len+1;
	while(lst&&a[lst].ch[c]==0)
	a[lst].ch[c]=np,lst=a[lst].fa;
	if(lst==0)
	a[np].fa=1;
	else
	{
		int q=a[lst].ch[c];
		if(a[q].len==a[lst].len+1)
		a[np].fa=q;
		else
		{
			int nq=++t;a[nq]=a[q];
			a[nq].len=a[lst].len+1;
			a[q].fa=a[np].fa=nq;
			while(a[lst].ch[c]==q&&lst)
			a[lst].ch[c]=nq,lst=a[lst].fa;
		}
	}
	lst=np;
}
void dfs(int u,int fa)
{
	for(int v:e[u])
	{
		if(v==fa)continue;
		dfs(v,u);
		val[u][1]+=val[v][1];
		val[u][2]+=val[v][2];
		val[u][3]+=val[v][3];
	}
	if(u==1)return ;
	c[a[a[u].fa].len+1]+=1ll*val[u][1]*val[u][2]*val[u][3];
	c[a[u].len+1]-=1ll*val[u][1]*val[u][2]*val[u][3];
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	scanf("%s",ch+1);
	n=strlen(ch+1);minu=min(minu,n);
	for(i=1;i<=n;i++)
	add(ch[i]-'a'),val[lst][1]++;
	
	add(26);
	scanf("%s",ch+1);
	n=strlen(ch+1);minu=min(minu,n);
	for(i=1;i<=n;i++)
	add(ch[i]-'a'),val[lst][2]++;
	
	add(27);
	scanf("%s",ch+1);
	n=strlen(ch+1);minu=min(minu,n);
	for(i=1;i<=n;i++)
	add(ch[i]-'a'),val[lst][3]++;
	
	for(i=1;i<=t;i++)
	e[a[i].fa].push_back(i);
	
	dfs(1,0);
	for(i=1;i<=minu;i++)
	{
		ans[i]=ans[i-1]+c[i];
		printf("%lld ",ans[i]%mod);
	}
	printf("\n");
	return 0;
}

