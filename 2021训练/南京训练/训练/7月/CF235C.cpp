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



*/
const int N=2e6+10;
struct SAM{
	int ch[26],fa,len;
}a[N];
int i,j,k,n,s,t,m,lst=1;
int val[N];
LL ans;
char ch[N];
vector<int> e[N]; 
map <int,int> mp;
void dfs(int u)
{
	for(int v:e[u])
	{
		dfs(v);
		val[u]+=val[v];
	}
}
void add(int c)
{
	int np=++t;a[np].len=a[lst].len+1;
	while(lst&&a[lst].ch[c]==0)
	{
		a[lst].ch[c]=np;
		lst=a[lst].fa;
	}
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
			a[np].fa=a[q].fa=nq;
			while(lst&&a[lst].ch[c]==q)
			a[lst].ch[c]=nq,lst=a[lst].fa;
		}
	}
	lst=np;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	t=1;
	scanf("%s",ch+1);
	n=strlen(ch+1);
	read(m);
	for(i=1;i<=n;i++)
	add(ch[i]-'a'),val[lst]++;
	for(i=1;i<=t;i++)
	e[a[i].fa].push_back(i);
	
	dfs(1);a[0].len=-1;
	for(j=1;j<=m;j++)
	{
		mp.clear();
		ans=0;
		scanf("%s",ch+1);
		n=strlen(ch+1);
		int now=1,len=0;
		for(i=1;i<=n;i++)
		{
			while(a[now].ch[ch[i]-'a']==0&&now)
			now=a[now].fa,len=a[now].len;
			len++;	
			now=a[now].ch[ch[i]-'a'];
			if(len==n)
			ans+=val[now],mp[now]=1;			
		}
		for(i=1;i<n;i++)
		{
			while((a[now].ch[ch[i]-'a']==0&&now))
			now=a[now].fa,len=a[now].len;
			len++;	
			now=a[now].ch[ch[i]-'a'];
			while(a[a[now].fa].len>=n)
			now=a[now].fa,len=a[now].len;
			if(len>=n&&mp[now]==0)
			ans+=val[now],mp[now]=1;	
			
		}
		printf("%lld\n",ans);
	}
	return 0;
}
