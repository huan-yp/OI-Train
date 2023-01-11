#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
using namespace std;
inline void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
void cmin(int &a,int b){a=min(a,b);}
void cmax(int &a,int b){a=max(a,b);}
const int N=1e6+10;
const int dx[]={0,0,-1,1},dy[]={1,-1,0,0};
int i,j,k,n,s,t,m;
queue<pair<int,int> > q;
char ch[N];
int vis[N];
string str[N],ans[N];
int ok(int x,int y)
{
	return x&&y&&x<=n&&y<=m&&str[x][y-1]!='#';
}
int count(int x,int y)
{
	int ret=0;
	for(int k=0;k<=3;k++)
	{
		int tox=x+dx[k],toy=y+dy[k];
		if(ok(tox,toy)&&ans[tox][toy-1]=='.')ret+=1;
	}
	return ret;
}
void bfs()
{
	while(!q.empty())
	{
		int x=q.front().first,y=q.front().second;q.pop();
		vis[(x-1)*m+y]=1;
		for(k=0;k<=3;k++)
		{
			int tox=x+dx[k],toy=y+dy[k];
			if(ok(tox,toy)==0)continue;
			if(vis[(tox-1)*m+toy]||count(tox,toy)>1)continue;
			vis[(tox-1)*m+toy]=1;
			q.push(make_pair(tox,toy));ans[tox][toy-1]='+';
		}
	}
}
signed main()
{
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	//freopen(".ans","w",sdtout);
	clock_t start = clock();
	int tot=1;cin>>tot;
	while(tot--)
	{
		cin>>n>>m;
		for(i=1;i<=n*m;i++)vis[i]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%s",ch+1);str[i]="";
			for(j=1;j<=m;j++)str[i]+=ch[j];
			
			ans[i]=str[i];
		}
		
		for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		if(str[i][j-1]=='L')
		q.push(make_pair(i,j));	
		
		bfs();
		for(i=1;i<=n;i++)
		cout<<ans[i]<<endl;
	}
	return 0;
}

