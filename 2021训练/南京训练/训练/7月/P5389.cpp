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
const int mod=998244353;
int i,j,k,n,s,t,m;
int inv(int aa,int ss=mod-2)
{
	aa%=mod;
	int ret=1;
	while(ss)
	{
		if(ss&1)
		ret=ret*aa%mod;
		ss>>=1;
		aa=aa*aa%mod;
	}
	return ret;
}
//3*n*(n+1)+3*n*n*(n+1)-2*(n+1)*n*(2*n+1)
//3*n^2+3*n+3*n^3+3^2
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	//正确的方式应该是打个表找规律 
	read(n);
	if(n==0)
	printf("%lld",inv(2));
	else
	printf("%lld",(1-(3*inv(n)%mod*inv(n+2)%mod)+mod)%mod*inv(2)%mod);
	return 0;
}


