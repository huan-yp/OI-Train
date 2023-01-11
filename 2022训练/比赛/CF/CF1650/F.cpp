#include<bits/stdc++.h>
#define INF 1000000000
#define int long long
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
const int N=2e5+10;
int i,j,k,n,s,t,m;
int dp[N][105],cost[N],a[N];
signed from[N][105];
struct tple{
	signed first,second,third;
};
tple make_tuple(signed a,signed b,signed c){
	return tple{a,b,c};
}
vector<int> ans[N];
vector<tple> pro[N];
signed main()
{
 	//freopen(".in","r",stdin);
	//freopen("1.out","w",stdout);
	read(t);
	while(t--){
		read(n),read(m);int flag=0,s=0;
		for(i=1;i<=n;i++){
			read(a[i]),ans[i].clear(),pro[i].clear();
			pro[i].push_back(make_tuple(0,0,0));cost[i]=0;
		}
		for(i=1;i<=m;i++){
			int e,t,p;
			read(e),read(p),read(t);
			pro[e].push_back(make_tuple((signed)t,(signed)p,(signed)i));
		}
		for(i=1;i<=n;i++){
			int len=pro[i].size()-1;
			for(j=0;j<=len;j++)
			for(k=0;k<=100;k++)
			dp[j][k]=1ll*INF*INF;
			dp[0][0]=0;
			for(j=0;j<len;j++)
			for(k=0;k<=100;k++){
				int to=min(100ll,k+pro[i][j+1].first),val=dp[j][k]+pro[i][j+1].second;
				if(dp[j+1][to]>val)dp[j+1][to]=val,from[j+1][to]=k;
				if(dp[j+1][k]>dp[j][k])dp[j+1][k]=dp[j][k],from[j+1][k]=k;
			}
			int now=100;
			if(dp[len][now]>1e16)cost[i]=2*INF;
			for(j=len;j>=1;j--){
				if(from[j][now]==now)continue;
				now=from[j][now];cost[i]+=pro[i][j].second;
				ans[i].push_back(pro[i][j].third);
			}
		}
		int now=0;
		for(i=1;i<=n;i++){
			now+=cost[i];
			if(now>a[i])flag=1;
		}
		if(flag){
			puts("-1");
			continue;
		}
		for(i=1;i<=n;i++)s+=ans[i].size();
		printf("%lld\n",s);
		for(i=1;i<=n;i++)
		for(int v:ans[i])
		printf("%lld ",v);
		puts("");
	}
	return 0;
}

