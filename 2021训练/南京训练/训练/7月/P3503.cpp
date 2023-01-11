#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LNF 1000000000000000000ll
#define int long long
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
void cmin(int &a,int b)
{
	a=min(a,b);
}
void cmax(int &a,int b)
{
	a=max(a,b);
}
/*



*/
const int N=1e6+10;
int i,j,k,n,s,t,m;
int a[N],sum[N];
int st1[N],st2[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(m);
	for(i=1;i<=n;i++) 
	read(a[i]);
	
	for(s=1;s<=m;s++)
	{
		read(k);
		for(i=1;i<=n;i++)
		sum[i]=a[i]-k+sum[i-1];
		
		int minu=2ll*LNF,maxn=-2ll*LNF,cnt1=0,cnt2=0,ans=0;
		for(i=0;i<=n;i++)
		{
			if(minu<=sum[i])continue;
			minu=sum[i];
			st1[++cnt1]=i;
		}
		for(i=n;i>=0;i--)
		{
			if(maxn>=sum[i])continue;
			maxn=sum[i];
			st2[++cnt2]=i;
		}
		for(i=1;i<=cnt2/2;i++)
		swap(st2[i],st2[cnt2-i+1]);
		
		int now=0;
		for(i=1;i<=cnt1;i++)
		{
			while(sum[st2[now+1]]>=sum[st1[i]]&&now<cnt2)
			now++;
			
			ans=max(ans,st2[now]-st1[i]);
		}
		cout<<ans<<' ';
	}
	return 0;
}

