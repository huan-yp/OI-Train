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
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	{
		int a,b,x,y,ans=0,opt=0;
		read(x),read(y),read(a),read(b);
		if(y>x)swap(x,y);if(b>a)swap(a,b);
		//x>y,a>b
		int all=a+b;
		ans=y/all,y-=ans*all,x-=ans*all;
		opt=ans*2;
		int l=0,r=ans,last=opt;
		while(r>=l)
		{
			int mid=(l+r)/2;
			if((x+mid*b)/a>=(y+mid*a)/b)
			last=max(ans*2-mid+(y+mid*a)/b,last),l=mid+1;
			else
			last=max(ans*2-mid+(x+mid*b)/a,last),r=mid-1;
		}
		printf("%lld\n",last);
	}
	return 0;
}


