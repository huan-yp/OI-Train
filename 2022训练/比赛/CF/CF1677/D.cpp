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
const int N=1e6+10,mod=998244353;
int i,j,k,n,s,t,m;
int v[N];
signed main()
{
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".in","w",stdout);
	read(t);
	while(t--){
		read(n),read(k);int ans=1;
		for(i=1;i<=n;i++)read(v[i]);
		for(i=1;i<=k;i++)ans=1ll*i*ans%mod;
		for(i=n;i>=n-k+1;i--)if(v[i]>0)ans=0;
		for(i=n;i>k;i--)
		ans=1ll*ans*(v[i-k]==-1?i:(v[i-k]==0?k+1:1))%mod;
		cout<<ans<<endl;
	}
	return 0;
}


