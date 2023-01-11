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
const int N=3e5+10;
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
		int ans=1ll*-INF*INF;
		read(n),read(k);
		for(i=1;i<=n;i++)read(a[i]);
		
		for(i=1;i<=n;i++)
		for(j=max(1ll,i-5*k);j<i;j++)
		cmax(ans,i*j-k*(a[i]|a[j]));
		
		cout<<ans<<endl;
	}
	return 0;
}

