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
const int N=1e3+10;
const double eps=1e-7;
int i,j,k,n,s,t,m;
double dp[N][N],p[N],c[N][N];
//dp[s+x][i+1]=dp[s][i+1]*(1-p[x])+dp[s][i]*p[x]
//dp[s-x][i]=(dp[s][i+1]-(1-p[x])*dp[s-x][i+1])/p[x]
bool cmp(int aa,int bb)
{
	return aa>bb;
}
class WaitingForBusAgain{
	public:
	double expectedBus(vector<int> f)
	{
		int minu=2e9;double ans=0;
		n=f.size();
		for(int v:f)
		minu=min(minu,v);
		for(i=0;i<n;i++)
		p[i+1]=(double)1.0*minu/f[i];
		dp[0][0]=1;
		for(i=1;i<=n;i++)
		for(j=0;j<=n;j++)
		{
			//array c has considerred the possibility
			//contribution of i hasn't
			dp[i][j]+=dp[i-1][j]*(1-p[i]),c[i][j]=c[i-1][j]*(1-p[i]);
			if(j) dp[i][j]+=dp[i-1][j-1]*p[i],c[i][j]+=(c[i-1][j-1]*(j-1)+(i-1)*dp[i-1][j-1])/j*p[i];
		}
		//dp[s-x][i]=(dp[s][i]-dp[s-x][i-1]*p[x])/(1-p[x])
		for(i=1;i<=n;i++)
		ans+=c[n][i];
		return ans;
	}
};
//signed main()
//{
//	//freopen(".in","r",stdin);
//	//freopen(".out","w",stdout);
//	//freopen(".ans","w",sdtout);
//	WaitingForBusAgain solve;
//	cout<<solve.expectedBus(	
//{26, 19548, 19299, 19431, 39568, 19476, 19726, 19530, 19613,
//19529, 19679, 19552, 19706, 19505, 19666, 19349, 19755, 19424,
//19486, 19596, 19439, 19500, 19639, 19520, 19472, 19675, 19602,
//19552, 19933, 19424, 19316, 19497, 19582, 19531, 19679, 19742,
//19896, 19365, 20083, 19542, 19827, 19583, 19592, 19593, 19661,
//19340, 19403, 19664, 19690, 19655, 19727, 19661, 19528, 19836,
//19819, 19414, 19770, 19500, 19653, 19613, 19579, 19794, 19668,
//19729, 19428, 19477, 19733, 19641, 19680, 19594, 19667, 19878,
//19571, 19627, 19576, 19422, 19521, 19512, 19481, 19620, 19364,
//19487, 19740, 19627, 19795, 19353, 19251, 19865, 19710, 19597,
//19610, 19710, 19491, 19598, 19650, 19828, 19726, 19810, 19766,
//19692}
//);
//	return 0;
//}


