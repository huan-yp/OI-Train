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
		int c1,c2,c3,a1,a2,a3,a4,a5;
		read(c1),read(c2),read(c3),read(a1),read(a2),read(a3),read(a4),read(a5);
		c1-=a1,c2-=a2,c3-=a3;
		if(c1<0||c2<0|c3<0)
		{
			puts("NO");
			continue;
		}
		int tmp=min(c1,a4);
		c1-=tmp,a4-=tmp,c3-=a4;
		tmp=min(c2,a5);
		c2-=tmp,a5-=tmp,c3-=a5;
		if(c1<0||c2<0||c3<0)
		puts("NO");
		else
		puts("YES");
	}
	return 0;
}


