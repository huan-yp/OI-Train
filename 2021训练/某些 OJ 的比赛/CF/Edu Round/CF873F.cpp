#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
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
const int N=2e5+10;
int i,j,k,n,s,t=1,m,lst=1;
LL ans;
char ch[N],p[N];
vector<int> e[N<<2];
struct node{
	int ch[26],fa,len,cnt;
}a[N<<2];
void add(int x)
{
	int np=++t;
	a[np].len=a[lst].len+1;
	for(;lst&&a[lst].ch[x]==0;lst=a[lst].fa)
	a[lst].ch[x]=np;
	if(lst==0)
	a[np].fa=1;
	else
	{
		int q=a[lst].ch[x];
		if(a[q].len==a[lst].len+1)
		a[np].fa=q;
		else
		{
			int nq=++t;
			a[nq]=a[q],a[nq].cnt=0,a[nq].len=a[lst].len+1;//¼ÇµÃ°Ñ cnt ÖÃÁã 
			a[q].fa=a[np].fa=nq;
			for(;a[lst].ch[x]==q&&lst;lst=a[lst].fa)
			a[lst].ch[x]=nq;
		}
	}
	lst=np;
}
void dfs(int u)
{
	for(int v:e[u])
	{
		dfs(v);
		a[u].cnt+=a[v].cnt;
	}	
	ans=max(ans,1ll*a[u].cnt*a[u].len);
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n);
	scanf("%s",ch+1);
	scanf("%s",p+1);
	for(i=1;i<=n;i++)
	{
		add(ch[i]-'a');
		a[lst].cnt+=(p[i]-'0')^1;
	}
	for(i=1;i<=t;i++)
	e[a[i].fa].push_back(i);
	
	dfs(1);
	cout<<ans<<endl;
	return 0;
}


