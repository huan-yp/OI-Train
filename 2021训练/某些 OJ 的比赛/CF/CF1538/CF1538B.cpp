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
const int N=2e5+10;
int i,j,k,n,s,t,m;
int a[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	{
		int sum=0,ans=0;
		read(n);
		for(i=1;i<=n;i++)
		read(a[i]),sum+=a[i];
		int ave=sum/n;
		if(sum%n)
		{
			printf("-1\n");
			continue;
		}
		for(i=1;i<=n;i++)
		if(a[i]>ave)
		ans++;
		cout<<ans<<endl;
	}
	return 0;
}


