#include<bits/stdc++.h>
#define y1 y3647
#define next nxt
#define LL long long
using namespace std;
inline int read(int &x)
{
	x=0;int f=1;
	char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}
	x*=f;
}
int i,j,k,n,s,t,m;
const int N=2001,M=31;
int lo[N];
int scnt[M][M],sval[M][M];
struct ST
{
	int st[N][11];
	ST()
	{
		for(i=0;i<N;i++)
		st[i][0]=-1e9;
	}
	void insert(int x,int val)
	{
		st[x][0]=max(st[x][0],val);		
	}	
	void build()
	{
		for(int i=1;i<=10;i++)
		for(int j=0;j+(1<<i)-1<N;j++)
		st[j][i]=max(st[j][i-1],st[j+(1<<i-1)][i-1]);
	}
	int quert(int l,int r)
	{
		int tmp=lo[r-l+1];
		return max(st[l][tmp],st[r-(1<<tmp)+1][tmp]);
	}
}h[M],l[M];
void init()
{
	for(int i=1;i<N;i++)
	lo[i]=log2(i);
}
class FoxAndFlowerShopDivOne{
	public:
	int theMaxFlowers(vector<string> mp, int d)
	{
		int ans=-1;
		init();
		n=mp.size();
		m=mp[0].size();
		for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			sval[i][j]=sval[i-1][j]+sval[i][j-1]-sval[i-1][j-1]+(mp[i-1][j-1]!='.');
			scnt[i][j]=scnt[i-1][j]+scnt[i][j-1]-scnt[i-1][j-1]+(mp[i-1][j-1]!='.')*(mp[i-1][j-1]=='P'?1:-1);
		}
		
		for(int i1=1;i1<=n;i1++)
		for(int j1=1;j1<=m;j1++)
		for(int i2=i1;i2<=n;i2++)
		for(int j2=j1;j2<=m;j2++)
		{
			int val=sval[i2][j2]-sval[i1-1][j2]-sval[i2][j1-1]+sval[i1-1][j1-1];
			int cnt=scnt[i2][j2]-scnt[i1-1][j2]-scnt[i2][j1-1]+scnt[i1-1][j1-1]+900;
			h[i1].insert(cnt,val);
			l[j1].insert(cnt,val);
		}
		for(i=1;i<=n;i++)
		h[i].build();
		for(i=1;i<=m;i++)
		l[i].build();
		
		for(int i1=1;i1<=n;i1++)
		for(int j1=1;j1<=m;j1++)
		for(int i2=i1;i2<=n;i2++)
		for(int j2=j1;j2<=m;j2++)
		{
			int val=sval[i2][j2]-sval[i1-1][j2]-sval[i2][j1-1]+sval[i1-1][j1-1];
			int cnt=scnt[i2][j2]-scnt[i1-1][j2]-scnt[i2][j1-1]+scnt[i1-1][j1-1];
			for(i=i2+1;i<=n;i++)
			ans=max(ans,val+h[i].quert(max(900-d-cnt,0),min(900+d-cnt,1800)));//小心这里会超出	
			for(j=j2+1;j<=m;j++)
			ans=max(ans,val+l[j].quert(max(900-d-cnt,0),min(900+d-cnt,1800)));//
		}
		return ans;
	}
};
