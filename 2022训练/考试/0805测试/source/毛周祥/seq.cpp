#include<bits/stdc++.h>
#define y1 y3647
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
template<typename _type1,typename _type2>void cmin(_type1 &a,const _type2 b){if(a>b)a=b;}
template<typename _type1,typename _type2>void cmax(_type1 &a,const _type2 b){if(a<b)a=b;}
const int N=1005;
int i,j,k,n,s,t,m,tp1,tp2,c;
int dp[2][N],h[N];
signed main()
{
 	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
//	freopen(".in","w",stdout);
	read(n),read(c);
	for(i=1;i<=n;i++)read(h[i]),cmax(s,h[i]);
	memset(dp,31,sizeof(dp));
	for(i=h[1];i<=s;i++)
	dp[1][i]=(i-h[1])*(i-h[1]);
	for(i=2;i<=n;i++){
		memset(dp[i&1],31,sizeof(dp[i&1]));
		for(j=h[i];j<=s;j++){
			int cost=(h[i]-j)*(h[i]-j);
			for(k=h[i-1];k<=s;k++)
			cmin(dp[i&1][j],dp[i-1&1][k]+abs(j-k)*c+cost);
		}
	}
	int ans=INF;
	for(i=h[i];i<=s;i++)cmin(ans,dp[n&1][i]);
	cout<<ans<<endl;
	return 0;
}


