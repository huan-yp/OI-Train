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
const int N=2e5+10;
int i,j,k,n,s,t,m;
int a[N],sum[N],st[N][20],lo[N];
int ask(int l,int r)
{
	int len=lo[r-l+1];
	return min(st[l][len],st[r-(1<<len)+1][len]);
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	for(i=1;i<N;i++)lo[i]=log2(i);
	while(t--)
	{
		int al=-1,ar=-2;
		read(n),read(s);
		for(i=1;i<=n;i++)read(a[i]),sum[i]=sum[i-1]+a[i],st[i][0]=sum[i];
		for(i=1;i<=18;i++)
		for(j=1;j+(1<<i)-1<=n;j++)
		st[j][i]=min(st[j][i-1],st[j+(1<<i-1)][i-1]);
		
		for(i=1;i<=n;i++)
		{
			int l=i,r=n,ans=0;
			while(r>=l)
			{
				int mid=(r+l)/2;
				if(sum[i-1]-ask(i,mid)<=s)
				l=mid+1,ans=mid;
				else
				r=mid-1;
			}			
			if(ans-i+1>ar-al+1)
			al=i,ar=ans;
		}
		if(al==-1)
		puts("-1");
		else
		printf("%lld %lld\n",al,ar);
		
	}

	return 0;
}

