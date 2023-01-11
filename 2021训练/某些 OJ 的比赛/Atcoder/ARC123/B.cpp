#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
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
int i,j,k,n,s,t,m,ans;
multiset<int> st[3];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n);
	for(s=0;s<=2;s++)
	{
		int x;
		for(i=1;i<=n;i++)
		{
			read(x);
			st[s].insert(x);
		}
	}
	for(i=1;i<=n;i++)
	{
		int val0=*st[0].begin();
		auto it1=st[1].upper_bound(val0);
		if(it1==st[1].end())break;
		int val1=*it1;
		auto it2=st[2].upper_bound(val1);
		if(it2==st[2].end())break;
		ans++;
		st[0].earse(st[0].begin());
		st[1].earse(it1);
		st[2].earse(it2);
	}
	cout<<ans;
	return 0;
}

