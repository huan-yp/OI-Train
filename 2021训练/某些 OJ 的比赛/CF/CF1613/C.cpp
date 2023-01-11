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
const int N=105;
int i,j,k,n,s,t,m,h;
int a[N];
int check(int x)
{
	int sum=0;
	for(i=2;i<=n;i++)
	{
		sum+=min(x,a[i]-a[i-1]);
		if(sum>=h)return 1;
	}
	sum+=x;
	if(sum>=h)return 1;
	return 0;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	int tot=1;read(tot);
	while(tot--)
	{
		read(n),read(h);
		for(i=1;i<=n;i++)read(a[i]);
		int l=1,r=h,ans=0;
		while(r>=l)
		{
			int mid=(l+r)/2;
			if(check(mid))
			ans=mid,r=mid-1;
			else
			l=mid+1;
		}
		cout<<ans<<endl;
	}
	return 0;
}

