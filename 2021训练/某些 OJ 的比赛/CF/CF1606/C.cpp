#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
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
const int N=1e5+10;
int i,j,k,n,s,t,m;
int a[N],p[N],maxn[N],ls[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	p[0]=1;
	for(i=1;i<=18;i++)p[i]=p[i-1]*10;
	int tot=1;read(tot);
	while(tot--)
	{
		read(n),read(k);
		for(i=1;i<=n;i++)read(a[i]);
		int lst=-1,now=1,lim=0;
		for(i=0;i<=18;i++)
		{
			if(a[now]==i&&now<=n)lst=a[now],now++;
			lim+=p[i-lst]*9,maxn[i]=lim,ls[i]=lst;
			if(lim>k)break;
		}
		for(;i>=1;i--)
		{
			for(j=0;j<=9;j++)
			{
				if(maxn[i-1]+p[i-ls[i]]*j>k)
				{
					printf("%d",j);
					k-=p[i-ls[i]]*j;
					break;
				}
			}
		}
		for(j=0;j<=9;j++)
		{
			if(p[i-ls[i]]*j>k)
			{
				printf("%d",j);
				break;
			}
		}
		cout<<endl;
	}
	return 0;
}

