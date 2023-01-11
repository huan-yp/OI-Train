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
const int N=2e3+10;
int i,j,k,n,s,t,m;
int a[N],b[N];
int gcd(int x,int y)
{
	if(y==0)return x;
	return gcd(y,x%y);
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	cin>>t;
	while(t--)
	{
		int ans=0,cnt=0;
		cin>>n;
		for(i=1;i<=n;i++)	
		cin>>a[i];
		for(i=1;i<=n;i++)
		if(a[i]%2==0)
		b[++cnt]=a[i];
		for(i=1;i<=n;i++)
		if(a[i]%2==1)
		b[++cnt]=a[i];
		
		for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
		if(gcd(b[i],2*b[j])!=1)
		ans++;
		printf("%d\n",ans);
	}
	return 0;
}


