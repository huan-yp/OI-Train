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
int i,j,k,n,s,t,m;
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	cin>>t;
	while(t--) 
	{
		int maxn=0,mexn=0,a1,a2,a3,a4;
		cin>>a1>>a2>>a3>>a4;
		int m1=max(a1,a2),m2=max(a3,a4);
		maxn=max(m1,m2);
		if(a1<maxn)
		mexn=max(mexn,a1);
		if(a2<maxn)
		mexn=max(mexn,a2);
		if(a3<maxn)
		mexn=max(mexn,a3);
		if(a4<maxn)
		mexn=max(mexn,a4);
		
		if(m1==mexn||m2==mexn)
		puts("YES");
		else
		puts("NO");
	}
	return 0;
}


