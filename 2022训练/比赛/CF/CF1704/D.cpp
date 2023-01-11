#include<bits/stdc++.h>
#define y1 y3647
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
template<typename _type1,typename _type2>void cmin(_type1 &a,const _type2 b){if(a>b)a=b;}
template<typename _type1,typename _type2>void cmax(_type1 &a,const _type2 b){if(a<b)a=b;}
const int N=1e6+10;
int i,j,k,n,s,t,m,tp1,tp2;
int sum[N];
vector<int> c[N];
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	read(t);
	while(t--){
		read(n),read(m);
		for(i=1;i<=n;i++){
			c[i].clear();
			c[i].resize(m+3);
			sum[i]=0;
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				read(c[i][j]);
				c[i][j]+=c[i][j-1];
				sum[i]+=c[i][j];
			}
		}
		if(sum[1]!=sum[2]){
			if(sum[2]==sum[3])
			printf("%lld %lld\n",1ll,sum[2]-sum[1]);
			else
			printf("%lld %lld\n",2ll,sum[1]-sum[2]);
			continue;
		}
		for(i=3;i<=n;i++)
		if(sum[i]!=sum[1])s=i;
		
		printf("%lld %lld\n",s,sum[1]-sum[s]);
	}
	return 0;
}


