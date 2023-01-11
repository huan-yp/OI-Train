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
const int N=505;
int i,j,k,n,s,t,m;
int sum[N][N],val[N][N],a[N][N],minu[N][N];
char ch[N][N];
int calc(int x1,int y1,int x2,int y2,int op)
{
	if(op==0)
	return (x2-x1+1)*(y2-y1+1)-calc(x1,y1,x2,y2,1);
	return a[x2][y2]-a[x2][y1-1]-a[x1-1][y2]+a[x1-1][y1-1]; 
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	{
		int ans=1e9;
		read(n),read(m);
		for(i=1;i<=n;i++)
		scanf("%s",ch[i]+1);
		for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		a[i][j]=a[i][j-1]+a[i-1][j]-a[i-1][j-1]+ch[i][j]-'0';
		
		for(k=5;k<=n;k++)
		{
			//(sum[i][j]-sum[i][x])+val[i][j]+val[i][x]
			for(i=k;i<=n;i++)
			{
				minu[i][0]=1e9;
				for(j=1;j<=m;j++)
				{
					sum[i][j]=calc(i-k+2,1,i-1,j,1);
					val[i][j]=calc(i-k+2,j,i-1,j,0);
					sum[i][j]+=calc(i-k+1,1,i-k+1,j,0);
					sum[i][j]+=calc(i,1,i,j,0);
					if(j>=4)
					cmin(ans,minu[i][j-3]+val[i][j]+sum[i][j-1]);
					minu[i][j]=min(minu[i][j-1],val[i][j]-sum[i][j]);
				}
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}

