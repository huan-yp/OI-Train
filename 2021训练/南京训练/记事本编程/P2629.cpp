#include<bits/stdc++.h>
#define y1 y3647
#define next nxt
#define LL long long
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
const int N=1e6+10;
int i,j,k,n,s,t,m;
int a[N],low[N],suf[N],pd[N],sum;
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n);
	for(i=1;i<=n;i++)
	read(a[i]);
	for(i=n;i>=1;i--)
	{
		suf[i]=suf[i+1]+a[i];
		pd[i]=min(0,pd[i+1]+a[i]);
	}
	for(i=1;i<=n;i++)
	{
		sum+=a[i];
		low[i]=min(low[i-1],sum);//low的定义错了 
	}
	for(i=1;i<=n;i++)
	if(pd[i]==0&&suf[i]+low[i-1]>=0)
 	s++;
	cout<<s;
	return 0;
}


