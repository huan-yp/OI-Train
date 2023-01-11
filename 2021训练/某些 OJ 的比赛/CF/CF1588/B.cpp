#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
using namespace std;
inline void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
void cmin(int &a,int b){a=min(a,b);}
void cmax(int &a,int b){a=max(a,b);}
int i,j,k,n,s,t,m,lst;
int ask(int l,int r)
{
	int x;
	printf("? %lld %lld\n",l,r);
	fflush(stdout);
	read(x);return lst=x;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	{
		read(n);
		int l=1,r=n,ans=0,all=ask(1,n);
		while(r>=l)
		{
			int mid=(l+r)/2;
			if(ask(1,mid)==all)
			r=mid-1,ans=mid;
			else
			l=mid+1;
		}
		s=ask(1,ans-1);
		int len2=all-s+1;
		int all1=all-len2*(len2-1)/2;
		int len1=(sqrt(1+8*all1+0.5)+1)/2;
		printf("! %lld %lld %lld\n",ans-len1-len2+1,ans-len2+1,ans);
		fflush(stdout);
	}
	return 0;
}

