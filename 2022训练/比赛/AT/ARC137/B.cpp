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
const int N=3e5+10;
int i,j,k,n,s,t,m;
int pd[N<<1],a[N<<1];
signed main()
{
 	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	read(n);
	//ans=(i+1)+2*sum[j-1]-j-2*sum[i]+sum[n]
	//连续，区间覆盖 
	int maxn=0,minu=0,sum=0;
	for(i=1;i<=n;i++){
		read(a[i]);sum+=a[i]==1?1:-1;
		cmax(maxn,sum),cmin(minu,sum);
		pd[sum-maxn+N]++,pd[sum-minu+1+N]--;
	}
	int ans=0;
	for(i=1;i<2*N;i++){
		pd[i]+=pd[i-1];
		if(pd[i])ans++;
	}
	cout<<ans<<endl;
	return 0;
}


