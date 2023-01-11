#include<bits/stdc++.h>
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
using namespace std;
template<typename _type>
inline void read(_type &x){
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
template<typename _type>void cmin(_type &a,_type b){a=min(a,b);}
template<typename _type>void cmax(_type &a,_type b){a=max(a,b);}
const int N=55;
int i,j,k,n,s,t,m;
int dp[N][N];
signed main()
{
 	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	read(t);
	memset(dp,1,sizeof(dp));dp[0][0]=0;
	for(i=0;i<=50;i++)
	for(j=0;j<=50;j++)
	for(k=0;k<=i;k++)
	for(s=0;s<=j;s++)
	{
		int x=(i-k)*(i-k)+(j-s)*(j-s);
		int val=(int)sqrt(1.0*x)*sqrt(1.0*x);
		if(val==x)
		cmin(dp[i][j],dp[k][s]+1);
	}
	while(t--){
		int x,y;read(x),read(y);
		cout<<dp[x][y]<<endl;
	}
	return 0;
}


