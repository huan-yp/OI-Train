#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	char ch=getchar();int x=0,r=1;
	while(ch<'0'||ch>'9'){if(ch=='-')r=0;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return r?x:-x;
}
int n;
signed main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	n=read();
	printf("%.8lf",n==1?1:0.5*(n+2));
	return 0;
}
