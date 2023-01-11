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
const int N=2e5+10;
int i,j,k,n,s,t,m,size,cnt,flag;
int col[N],vis[N][2];
vector<pair<int,int> > e[N];
void dfs(int u,int op)
{
	size++;vis[u][op]=1;
	if(col[u]==1)cnt++;
	for(auto tmp:e[u])
	{
		int v=tmp.first,val=tmp.second;
		if(vis[v][op])
		{
			if((col[v]^val)!=col[u])
			flag=1;
		}
		else
		{
			col[v]=col[u]^val;
			dfs(v,op);
		}
	}
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	{
		read(n),read(m);
		for(i=1;i<=n;i++)
		vis[i][0]=vis[i][1]=0,e[i].clear();

		for(i=1;i<=m;i++)
		{
			int x,y;char ch[100];
			read(x),read(y),scanf("%s",ch+1);
			if(ch[1]=='c')
			{
				e[x].push_back(make_pair(y,0));
				e[y].push_back(make_pair(x,0));
			}
			else
			{
				e[x].push_back(make_pair(y,1));
				e[y].push_back(make_pair(x,1));
			}
		}
		int cant=0,ans=0;
		for(i=1;i<=n;i++)
		{
			if(vis[i][0])continue;
			
			int ct=0,maxn=0;
			flag=0,size=0,cnt=0,col[i]=0;
			dfs(i,0);
			if(flag==0)
			{
				cmax(maxn,max(cnt,size-cnt));
			}
			ct+=flag;
			
			flag=0,size=0,cnt=0,col[i]=1;
			dfs(i,1);
			if(flag==0)
			{
				cmax(maxn,max(cnt,size-cnt));
			}
			ct+=flag;
			if(ct==2)
			cant=1;
			ans+=maxn;
		}
		if(cant)
		{
			printf("-1\n");
			continue;
		}
		printf("%d\n",ans);
	}

	return 0;
}

