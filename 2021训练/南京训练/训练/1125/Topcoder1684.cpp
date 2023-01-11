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
const int N=105;
int i,j,k,n,s,t,m,ans;
int w[N],h[N],r[N],c[N],colr[N],colc[N],vis[N],lef[N],top[N],pd[N][N];
bitset<128> cov[N],covp[10][N],Z;
void dfs(int dep)
{
	if(dep==s+1)
	{
		int sum=0;
		for(int i=1;i<=n;i++)
		cov[i]&=Z;
		
		for(int i=1;i<=s;i++)
		for(int j=1;j<=w[i];j++)
		cov[j+top[i]-1]|=covp[i][j]<<(lef[i]-1);
		
		for(int i=1;i<=n;i++)
		sum+=cov[i].count();
	
		cmax(ans,sum);
		return ;
	}
	for(int i=1;i<=s;i++)
	{
		if(vis[i])continue;
		vis[i]=1;
		for(int j=1;j<=dep+1;j++)
		for(int k=1;k<=dep+1;k++)
		{		
			if(j==k||r[j]<=0||r[j]>n||c[k]<=0||c[k]>m)continue;
			colr[dep+1]=colr[j],colc[dep+1]=colc[k];
			if(colr[j]==1&&colc[k]==1)
			{
				lef[i]=c[k],top[i]=r[j];
				if(lef[i]+h[i]-1>m||top[i]+w[i]-1>n)continue;
				pd[j][k]=1;
				r[dep+2]=top[i]+w[i],c[dep+2]=lef[i]+h[i];
			}
			if(colr[j]==1&&colc[k]==-1)
			{
				lef[i]=c[k]-h[i]+1,top[i]=r[j];
				if(lef[i]<1||top[i]+w[i]-1>n)continue;
				pd[j][k]=1;
				r[dep+2]=top[i]+w[i],c[dep+2]=lef[i]-1;
			}
			if(colr[j]==-1&&colc[k]==1)
			{
				lef[i]=c[k],top[i]=r[j]-w[i]+1;
				if(lef[i]+h[i]-1>m||top[i]<1)continue;
				pd[j][k]=1;
				r[dep+2]=top[i]-1,c[dep+2]=lef[i]+h[i];
			}
			if(colr[j]==-1&&colc[k]==-1)
			{
				lef[i]=c[k]-h[i]+1,top[i]=r[j]-w[i]+1;
				if(lef[i]<1||top[i]<1)continue;
				pd[j][k]=1;
				r[dep+2]=top[i]-1,c[dep+2]=lef[i]-1;
			}
			dfs(dep+1);
			pd[j][k]=0;
		}
		vis[i]=0;
	}
}
class Posters{
	public:
	int maxCover(int width,int height,vector<int> pWidth,vector<int> pHeight)
	{
		n=width,m=height,s=pWidth.size();
		for(i=1;i<=s;i++)
		w[i]=pWidth[i-1],h[i]=pHeight[i-1];
		//colr[i] = -1:往上走
		//colr[i] = 1:往下走
		//colc[i] = -1:往左走
		//colc[i] = 1:往右走
		
		if(s==1)return w[1]*h[1];
		
		r[1]=1,r[2]=n,colr[1]=1,colr[2]=-1;
		c[1]=1,c[2]=m,colc[1]=1,colc[2]=-1;
		for(i=1;i<=s;i++)
		for(j=1;j<=w[i];j++)
		for(k=1;k<=h[i];k++)
		covp[i][j][k]=1;		
		
		for(i=1;i<=s;i++)
		{
			vis[i]=1,lef[i]=1,top[i]=1;
			colr[3]=1,colc[3]=1,r[3]=w[i]+1,c[3]=h[i]+1;
			for(j=i+1;j<=s;j++)
			{
				vis[j]=1,lef[j]=m-h[j]+1,top[j]=n-w[j]+1;
				colr[4]=-1,colc[4]=-1,r[4]=top[j]-1,c[4]=lef[j]-1;
				dfs(3);
				vis[j]=0;
			}
			vis[i]=0;
		}
		return ans;
	}
};
//signed main()
//{
//	//freopen(".in","r",stdin);
//	//freopen(".out","w",stdout);
//	//freopen(".ans","w",sdtout);
//	Posters solve;
//	cout<<solve.maxCover(100, 100, {49, 49, 48, 48, 50}, {49, 48, 49, 48, 50});
//	return 0;
//}

