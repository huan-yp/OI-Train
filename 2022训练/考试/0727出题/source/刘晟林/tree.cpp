#include<bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &x)
{
	x=0;T f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-')f=-1;
	for(;isdigit(c);c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	x*=f;
}
template <typename T,typename ...Args>void read(T &x,Args&...args){read(x),read(args...);}
template <typename T> void print(T x)
{
	if(x<0) x=-x,putchar('-');
	if(x>9) print(x/10);
	putchar(x%10+48);
}
template <typename T> void print(T x,char c){print(x); putchar(c);}
const int N=2000007;
int n,dfn[N],idx[N],c[N];
long double ans;
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	read(n); ans=2;
	c[1]++; c[2]--;
	for(int i=1,x;i<=n;i++) read(x),dfn[x]=i;
	for(int i=1,x;i<=n;i++) read(x),idx[dfn[x]]=i;
	for(int i=1;i<=n;i++) dfn[idx[i]]=i;
	if(n==1) return puts("1"),0;
	if(n==0) return puts("0"),0;
	for(int i=1;i<n;i++)
	{
		if(dfn[i]>dfn[i+1]) ans++,c[i]++,c[i+1]--;//必须分
		if(idx[i]<idx[i+1]-1) c[idx[i]]++,c[idx[i+1]]--;//必须不分
	}
	for(int i=1;i<n;i++) c[i]+=c[i-1];
	for(int i=1;i<n;i++) ans+=(c[i]?0:0.5);
	printf("%.3Lf",ans);
	return 0;
}