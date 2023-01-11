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
const int N=2e6+10; 
int i,j,k,n,s,t,m;
double f[N],d[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n);
	f[n]=d[n]=0;
	for(i=n-1;i>=0;i--)
	f[i]=f[i+1]+1.0*n/(n-i),d[i]=1.0*n/(n-i)+d[i+1]+2*f[i+1]+f[i]*i*2/(n-i);
	printf("%0.2lf",(d[0]+f[0])/2);
	return 0;
}


