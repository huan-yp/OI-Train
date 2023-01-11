#include<bits/stdc++.h>
#define in(x,mask) (bool(1<<(x)-1&(mask)))
#define size(mask) (__builtin_popcount((mask)))
using namespace std;
template<typename _type>
inline int read(_type &x){
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch<'0'||ch>'9'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*=f;
}
const int N=11,M=N*N/2;
int i,j,k,n,s,t,m;
double dp[1<<N][M],f[M],C[M][M];
int e[M][2];
signed main()
{
	read(n),read(m);f[0]=1;
	for(i=0;i<M;i++)for(C[i][0]=1,j=1;j<=i;j++)
	C[i][j]=C[i-1][j-1]+C[i-1][j];
	for(i=1;i<=m;i++)read(e[i][0]),read(e[i][1]),f[i]=f[i-1]*i;
	
	for(int mask=1;mask<1<<n;mask++){
		if(__builtin_popcount(mask)==1)dp[mask][0]=1;
		for(int mask2=(mask-1)&mask;mask2;mask2=(mask2-1)&mask){
			int mask1=mask^mask2,c1=0,c2=0,c0=0;
			if(mask1>mask2)continue;
			for(i=1;i<=m;i++){
				int u=e[i][0],v=e[i][1];
				c1+=in(u,mask1)&&in(v,mask1);
				c2+=in(u,mask2)&&in(v,mask2);
				c0+=(in(u,mask1)&&in(v,mask2))||(in(u,mask2)&&in(v,mask1));
			}
			for(int k1=size(mask1)-1;k1<=c1;k1++)
			for(int k2=size(mask2)-1;k2<=c2;k2++)
			for(int _k1=k1;_k1<=c1;_k1++)
			for(int _k2=k2;_k2<=c2;_k2++){
				int all=c1+c2-_k1-_k2;
				double base0=C[_k1+_k2][_k1]*C[all+c0-1][c0-1];
				double base1=C[all][c1-_k1]*f[c0];
				dp[mask][_k1+_k2+1]+=dp[mask1][k1]*dp[mask2][k2]*base0*base1;
			}
		}
	}
	double ans=0,lst=0;
	for(i=n-1;i<=m;i++){
		double now=dp[(1<<n)-1][i];
		ans+=(now)/(m+1)*i;
	}
	cout<<ans/f[m]<<endl;
	return 0;
}
