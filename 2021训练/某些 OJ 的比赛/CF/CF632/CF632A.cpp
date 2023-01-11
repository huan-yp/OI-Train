#include<bits/stdc++.h>
#define y1 y3647
#define next nxt
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
int i,j,k,n,s,t,m;
string a[50];
double ans;
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	int p;
	read(n),read(p);
	for(i=1;i<=n;i++)
	cin>>a[i];
	for(i=n;i>=1;i--)
	{
		if(a[i].length()>5)
		ans=(ans+0.5)*2,s++;
		else
		ans=ans*2;
	}
	cout<<(int)((ans-1.0*s/2)*p+0.5);
	return 0;
}


