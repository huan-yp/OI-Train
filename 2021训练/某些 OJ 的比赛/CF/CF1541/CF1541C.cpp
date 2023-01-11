#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
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
/*



*/
int i,j,k,n,s,t,m;
const int N=1e5+10;
int d[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	{
		read(n);
		for(i=1;i<=n;i++)
		read(d[i]);
		sort(d+1,d+n+1);
		
		int ans=-d[n],sum=0;
		for(i=1;i<=n;i++)
		{
			sum+=d[i];
			ans+=d[i]*i-sum;
		}
		cout<<-ans<<endl;
	}
	return 0;
}

