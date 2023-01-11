#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
#define int long long
#define pii pair<int,int>
using namespace std;
template<typename T>
inline int read(T &x){
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch<'0'||ch>'9'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*=f;
}
template<typename T1,typename T2>void cmin(T1 &a,const T2 &b){if(a>b)a=b;}
template<typename T1,typename T2>void cmax(T1 &a,const T2 &b){if(a<b)a=b;}
const int N=1e6+10;
int i,j,n,s,t,m;
int dp[N][4],p[N][2];
int mex(vector<int> v){
	int pd[N];memset(pd,0,sizeof(pd));
	for(int i=0;i<v.size();i++)pd[v[i]]=1;
	for(int i=0;i<=v.size();i++)if(!pd[i])return i;
	return -1;
}
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	n=10;
	for(i=1;i<=n;i++){
		vector<int> v;
		for(j=1;j<=i;j++)
		v.push_back(dp[j-1][2]^dp[i-j][2]);
		dp[i][3]=mex(v),v.clear();
		for(j=1;j<i;j++){
			//one way
			v.push_back(dp[j-1][2]^dp[i-j][0]);
			v.push_back(dp[j-1][2]^dp[i-j][1]);
		}
		v.push_back(dp[i-1][2]);
		dp[i][2]=mex(v),v.clear();
		for(j=1;j<i;j++){
			//dif
			v.push_back(dp[j-1][1]^dp[i-j][0]);
		}
		dp[i][1]=mex(v),v.clear();
		for(j=1;j<=i;j++){
			//same
			v.push_back(dp[j-1][1]^dp[i-j][1]);
		}
		for(j=2;j<i;j++){
			//same
			v.push_back(dp[j-1][0]^dp[i-j][0]);
		}
		dp[i][0]=mex(v),v.clear();
	//	printf("%d %d %d %d\n",dp[i][0],dp[i][1],dp[i][2],dp[i][3]);
	}
	read(n),read(m);
	int ans=0;
	if(m==0){
		ans=n&1;	
	}
	else{
		for(i=1;i<=m;i++)read(p[i][0]),read(p[i][1]);
		ans^=p[1][0]-1,ans^=n-p[m][0];
		for(i=2;i<=m;i++){
			int same=p[i][1]==p[i-1][1];
			ans^=same;
		}
	}
	if(ans)puts("Takahashi");
	else puts("Aoki");
	return 0;
}


