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
const int N=2e5+10;
int i,j,k,n,s,t,m;
int a[N],sum;
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	//n*(n-lst)
	read(t);
	while(t--)
	{
		sum=0;
		read(n);
		for(i=1;i<=n;i++)
		read(a[i]),sum+=a[i];	
		
		int ave=sum/n;
		int ans=0;
		
		int lst=sum%n;
		cout<<lst*(n-lst)<<endl;
	}
	return 0;
}

