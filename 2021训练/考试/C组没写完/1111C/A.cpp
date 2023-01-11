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
const int N=2e6+10;
int i,j,k,n,s,t,m;
int ans[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	int l,r;
	read(l),read(r);
	for(i=2;i<=1e6;i++)
	{
		for(j=((l-1)/i+1)*i;j<=r;j+=i)
		{
			if(ans[j-l+1])continue;
			ans[j-l+1]=i;
		}
	}
	for(i=1;i<=r-l+1;i++)
	if(ans[i]==0)ans[i]=l+i-1;
	
	for(i=1;i<=r-l+1;i++)
	printf("%lld\n",ans[i]);
	return 0;
}

