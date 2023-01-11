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
int i,j,k,n,s,t,m;
int arr[N],maxn[N],minu[N];
int smaxn[N],pmaxn[N],sminu[N],pminu[N];
struct point{
	int val,rk;
	friend bool operator <(point a,point b)
	{
		return a.val<b.val;
	}
}p[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	int tot=1;read(tot);
	while(tot--)
	{
		read(n),read(m);int flag=0;
		int a[n+10][m+10];
		memset(a,0,sizeof(a));
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			read(a[i][j]);
		}
		for(i=1;i<=n;i++)	
		p[i].val=a[i][1],p[i].rk=i;
		sort(p+1,p+n+1);
		if(n>m)
		{
			for(int ii=1;ii<m;ii++)
			{
				maxn[n+1]=0;//×ómaxn 
				minu[n+1]=2e9;//ÓÒminu 
				for(i=n;i>=1;i--)
				{
					maxn[i]=maxn[i+1],minu[i]=minu[i+1];
					for(j=1;j<=ii;j++)
					cmin(minu[i],a[p[i].rk][j]);
					for(j=ii+1;j<=m;j++)
					cmax(maxn[i],a[p[i].rk][j]);
				}
				int mi=2e9,mx=0;
				for(i=1;i<n;i++)
				{
					for(j=1;j<=ii;j++)
					cmax(mx,a[p[i].rk][j]);
					for(j=ii+1;j<=m;j++)
					cmin(mi,a[p[i].rk][j]);
					if(mi>maxn[i+1]&&minu[i+1]>mx)flag=i;
					if(flag)break;
				}
				for(i=1;i<=flag;i++)arr[p[i].rk]=0;
				for(i=flag+1;i<=n;i++)arr[p[i].rk]=1;
				if(flag)
				{
					flag=ii;
					break;
				}
			}
		}
		else
		{
			int lim=0;
			for(int ii=1;ii<n;ii++)
			{
				for(i=1;i<=ii;i++)arr[p[i].rk]=0;
				for(i=ii+1;i<=n;i++)arr[p[i].rk]=1;
				maxn[m+1]=0,minu[m+1]=2e9;
				for(j=m;j>=1;j--)
				{
					maxn[j]=maxn[j+1];
					minu[j]=minu[j+1];
					for(i=1;i<=n;i++)
					{
						if(arr[i]==1)cmax(maxn[j],a[i][j]);
						else cmin(minu[j],a[i][j]);
					}
					if(maxn[j]>=minu[j]){lim=j+1;break;}
				}
				int mx=0,mi=2e9;
				for(j=1;j<m;j++)
				{
					for(i=1;i<=n;i++)
					{
						if(arr[i]==0)cmax(mx,a[i][j]);
						else cmin(mi,a[i][j]);
					}
					if(mx>=mi)break;
					if(j+1>=lim)flag=j;
				}
				if(flag)break;
			}
		}
		if(flag)
		{
			puts("YES");
			for(i=1;i<=n;i++)
			if(arr[i]==0)printf("B");
			else printf("R");
			
			printf(" %d\n",flag);
		}
		else
		puts("NO");
	}

	return 0;
}

