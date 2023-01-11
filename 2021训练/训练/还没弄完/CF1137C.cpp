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
const int N=1e5+10,M=55;
int i,j,k,n,s,t,m,d;
int pd[N][M];
char ch[N][M];
queue<pair<int,int>> q;
vector<int> e[N];
void bfs()
{
	pd[1][1]=1;
	q.push(make_pair(1,1));
	while(!q.empty())
	{
		auto tmp=q.front();q.pop();
		int u=tmp.first,re=tmp.second;
		for(int v:e[u])
		{
			int tod=re%d+1;
			if(pd[v][tod])continue;	
			pd[v][tod]=1;
			q.push(make_pair(v,tod));
		}
	}
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(m),read(d);
	for(i=1;i<=m;i++)
	{
		int x,y;
		read(x),read(y);
		e[x].push_back(y);
	//	e[y].push_back(x);
	}
	for(i=1;i<=n;i++)
	scanf("%s",ch[i]+1);
	bfs();
	for(i=1;i<=n;i++)
	{
		int flag=0;
		for(j=1;j<=d;j++)
		flag|=(ch[i][j]=='1')&&pd[i][j];
		s+=flag;
	}
	cout<<s<<endl;
	return 0;
}

