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
const int N=1e5+10;
int i,j,k,n,s,t,m,tp1,tp2;
int c[N],dp[N];
vector<int> e[N];
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	read(t);
	while(t--){
		read(n);
		for(i=1;i<=n;i++)e[i].clear();
		for(i=1;i<=n;i++)read(c[i]),e[c[i]].push_back(i);
		for(i=1;i<=n;i++){
			int ans=0,dp1=0,dp0=0;
			for(auto v:e[i]){
				if(v&1)cmax(dp1,dp0+1);
				else cmax(dp0,dp1+1);
			}
						
			cout<<max(dp1,dp0)<<' ';
		}
		cout<<endl;
	}



	return 0;
}


