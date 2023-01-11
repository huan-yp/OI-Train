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
const int N=3e5+10;
int i,j,k,n,s,t,m,tp1,tp2;
int a[N],dp[N];
map<int,int> mp;
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	read(t);
	while(t--){
		read(n);
		mp.clear();
		for(i=1;i<=n;i++)read(a[i]);
		int sum=0;mp.insert(make_pair(0,0));
		for(i=1;i<=n;i++){
			dp[i]=dp[i-1]+(a[i]!=0);
			sum^=a[i];
			auto it=mp.find(sum);
			if(it==mp.end()){
				mp[sum]=i;
				continue;
			}
			cmin(dp[i],dp[it->second]+(i-it->second-1));
			mp[sum]=i;
		}
		cout<<dp[n]<<endl;
	}
	return 0;
}


