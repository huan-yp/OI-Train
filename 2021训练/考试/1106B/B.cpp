#include<bits/stdc++.h>
#define LL long long 
using namespace std;
void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	x*=f;
}
template<typename _type>
void cmin(_type &a,const _type b){a=min(a,b);}
template<typename _type>
void cmax(_type &a,const _type b){a=max(a,b);}
const int N=3e3+10;
int i,j,k,m,n,s,t,l,r;
LL a[N],w;
long long b[N];
int main()
{
	read(n),read(m);
	for(i=1;i<=n;i++)
	scanf("%lld",&a[i]);
	for(i=1;i<=n;i++)
	for(j=1;j<=7;j++)
	b[i]+=a[i+j-1];

	for(i=1;i<=m;i++)
	{
		read(l),read(r);
		scanf("%lld",&w);
		int nowl=l,nowr=l;
		LL ans=0,valnow=a[nowl-1];
		while(valnow+b[nowr]<=w&&nowr+6<=r)
		valnow+=b[nowr],nowr+=7;
		LL *p1=a+l-1,*p2=a+nowr;
		for(;nowl<=r;nowl++)
		{
			valnow-=*p1;p1++;
			while(valnow+*p2<=w&&nowr<=r)valnow+=*p2++,nowr++;
			cmax(ans,valnow);
			if(nowr==r+1)continue;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

