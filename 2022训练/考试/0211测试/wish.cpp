#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
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
int i,j,k,n,s,t,m;
int maxn[15],minu[15],ans[15],es[15],vis[15][2],acc[15],dp[15];
char ch[15][55]; 
int findpos(int pos,int op)
{
	int rk=-10;
	for(int i=1;i<=n;i++)
	if(vis[i][op]&&abs(rk-pos)>abs(pos-i))rk=i;
	return rk;
}
int setval(int l,int r,int op)
{
	if(l>r)swap(l,r);
	for(int i=l;i<=r;i++)vis[i][op]=1;
}
signed main()
{
 	freopen("wish.in","r",stdin);
	freopen("wish.out","w",stdout);
	read(n),read(m);s=1e8;
	for(i=1;i<=n;i++)
	{
		scanf("%s",ch[n-i+1]+1);
		int lst=0,x=n-i+1;ans[x]=1e8;
		maxn[x]=0,minu[x]=0;
		for(j=1;j<=m;j++)
		{
			if(ch[x][j]!='#')continue;
			if(lst)cmin(ans[x],2*m-2*(j-lst+1));
			es[x]++;lst=j;++t;
			cmax(maxn[x],2*(j-1)),cmax(minu[x],2*(m-j));
		}
	}
	while(es[n]==0)n--;
	for(int mask1=0;mask1<1<<n;mask1++)
	for(int mask2=0;mask2<1<<n;mask2++)
	{
		if(mask1&mask2)continue;
		for(i=1;i<=n;i++)acc[i]=vis[i][0]=vis[i][1]=0;
		int now=0,sum=-2;
		for(i=1;i<=n;i++)
		{
			if(1<<i-1&mask1)acc[i]=1,now^=1,sum+=m-1;
			vis[i][now]=1,sum++;
		}
		for(i=n;i>=1;i--)
		{
			if(1<<i-1&mask2)acc[i]=1,now^=1,sum+=m-1;
			vis[i][now]=1,sum++;
		}
		if(now==1)acc[1]=1,sum+=m-1;
		int tmp=INF,all=0;
		for(i=1;i<=n;i++)
		{
			if(es[i]==0||acc[i])continue;
			int val=1e8;
			if(vis[i][1])cmin(val,minu[i]);
			if(vis[i][0])cmin(val,maxn[i]);
			if(vis[i][1]&&vis[i][0])cmin(val,ans[i]);
			all+=val;
		}
		cmin(tmp,all);all=0;
		for(i=1;i<=n;i++)
		{
			if(es[i]==0||acc[i])continue;
			int val=1e8;
			if(vis[i][1])cmin(val,minu[i]);
			if(vis[i][0])cmin(val,maxn[i]);
			if(vis[i][1]&&vis[i][0])cmin(val,ans[i]);
			if((vis[i][1]==0||vis[i][0]==0)&&ans[i]+2<=val&&es[i]>=2)
			{
				int pos=vis[i][1]==1;
				int p=findpos(i,pos^1);
				setval(p,i,pos^1);
				val=ans[i]+abs(p-i)*2;
			}
			all+=val;
		}
		cmin(tmp,all);
		cmin(s,sum+tmp);
	}
	cout<<s+t<<endl;
	return 0;
}

