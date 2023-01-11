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
int fa[N],size[N],cnt[N],b[N];
int find(int x)
{
	if(fa[x]==x)return fa[x];
	return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	x=find(x),y=find(y);
	if(x==y)
	{
		cnt[x]++;
		return ;
	}
	size[x]+=size[y],fa[y]=x,cnt[x]+=cnt[y];
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(m);
	for(i=1;i<=n;i++)fa[i]=i,size[i]=1;
	for(i=1;i<=m;i++)
	{
		int x,y,ans=0,sum=1;s=0;
		read(x),read(y);merge(x,y);
		for(j=1;j<=n;j++)
		{
			if(find(j)!=j)continue;
			sum+=cnt[j];
			b[++s]=size[j];
		}
		sort(b+1,b+s+1);
		for(j=s;j>=s-sum+1&&j>=1;j--)ans+=b[j];
		
		cout<<ans-1<<endl;
	}
	return 0;
}

