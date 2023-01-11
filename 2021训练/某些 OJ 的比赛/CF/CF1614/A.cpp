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
const int N=1e6+10;
int i,j,k,n,s,t,m;
int a[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	int tot=1;read(tot);
	while(tot--)
	{
		int l,r,k,ans=0;
		read(n),read(l),read(r),read(k);
		for(i=1;i<=n;i++)read(a[i]);
		sort(a+1,a+n+1);
		for(i=1;i<=n;i++)
		{
			for(j=i;j<=n;j++)
			{
				int sum=0;
				if(a[i]<l||a[j]>r)continue;
				for(s=i;s<=j;s++)
				sum+=a[s];
				if(sum<=k)
				cmax(ans,j-i+1);
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}

