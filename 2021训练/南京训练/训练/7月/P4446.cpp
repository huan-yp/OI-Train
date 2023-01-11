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
const int N=2e5+10;
int pd[N],zs[N];
map<int,int> mp;
void init()
{
	for(i=2;i<=2e5;i++)
	{
		if(!pd[i]) zs[++t]=i;
		for(j=1;j<=t&&zs[j]*i<=2e5;j++)
		pd[i*zs[j]]=1;
	}
}
void solve()
{
	read(n);
	int now=1;
	for(i=1;zs[i]<=32000;i++)
	{
		while(n%(zs[i]*zs[i]*zs[i])==0)
		now*=zs[i],n/=zs[i]*zs[i]*zs[i];
		while(n%zs[i]==0)
		n/=zs[i];
		if(n<=zs[i]*zs[i]*zs[i])break;
	}
	if(mp.find(n)!=mp.end())
	cout<<now*mp[n]<<endl;
	else
	cout<<now<<endl;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	init();
	for(i=32000;i<=1e6;i++)
	mp[i*i*i]=i;
	read(t);
	while(t--)
	solve();
	return 0;
}


