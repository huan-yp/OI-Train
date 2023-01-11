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
const int N=1e3+10,dx[]={1,-1,0,0},dy[]={0,0,1,-1};
int i,j,k,n,s,t,m,ans;
int pd[N][N],a[N][N];
int ok(int x,int y)
{
	return x>0&&y>0&&x<=n&&y<=n;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	{
		read(n);ans=0;
		for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		read(a[i][j]),pd[i][j]=0;
		for(i=2;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			if(pd[i-1][j])continue;
			ans^=a[i][j];
			for(k=0;k<4;k++)
			{
				int tox=i+dx[k],toy=j+dy[k];
				if(ok(tox,toy)==0)continue;
				pd[tox][toy]^=1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

