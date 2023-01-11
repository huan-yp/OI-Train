#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>

using namespace std;
#define rep(i,j,k) for(int i=(j);i<=(k);i++)
#define per(i,j,k) for(int i=(j);i>=(k);i--)
#define pii pair<int,int>
inline void read(int &x)
{
	x=0;int f=1;
	char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}
	x*=f;
}
int n,w,q,x,as,mn,mx,a[1<<20];
int main()
{
	read(n),read(w),read(q);
	rep(i,1,n)read(a[i]);
	
	int j;
	for(j=1;j+3<=q;j+=4)
	{
		int x1,x2,x3,x4;
		int mi1=a[1],mi2=a[1],mi3=a[1],mi4=a[1];
		int as1=0,as2=0,as3=0,as4=0;
		int mx1=a[1],mx2=a[1],mx3=a[1],mx4=a[1];	
		read(x1),read(x2),read(x3),read(x4);
		x1=w-x1,x2=w-x2,x3=w-x3,x4=w-x4;
		for(int i=2;i<=n;i++)
		{
			mi1=a[i]<mi1?a[i]:mi1;
			mx1=a[i]>mx1?a[i]:mx1;
			mi1+x1<mx1?mx1=mi1=a[i],as1++:0;
			mi2=a[i]<mi2?a[i]:mi2;
			mx2=a[i]>mx2?a[i]:mx2;
			mi2+x2<mx2?mx2=mi2=a[i],as2++:0;
			mi3=a[i]<mi3?a[i]:mi3;
			mx3=a[i]>mx3?a[i]:mx3;
			mi3+x3<mx3?mx3=mi3=a[i],as3++:0;
			mi4=a[i]<mi4?a[i]:mi4;
			mx4=a[i]>mx4?a[i]:mx4;
			mi4+x4<mx4?mx4=mi4=a[i],as4++:0;
		}
		printf("%d\n%d\n%d\n%d\n",as1,as2,as3,as4);
	}
	for(;j<=q;j++)
	{
		as=0;mn=mx=a[1];
		read(x);x=w-x;
		rep(i,2,n)
		{
			mn=a[i]<mn?a[i]:mn;
			mx=a[i]>mx?a[i]:mx;
			mn+x<mx?mx=mn=a[i],as++:0;
		}
		printf("%d\n",as);
	}
}
