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
template<typename _type>void cmin(_type &a,_type b){a=min(a,b);}
template<typename _type>void cmax(_type &a,_type b){a=max(a,b);}
const int N=23,L=10000,LIM=1.2e8;
int i,j,k,n,s,t,m,now=1,x;
unsigned ans,pre;
unsigned dp[LIM],start[1<<N],c[L];
signed main()
{
 	//freopen("bit.in","r",stdin);
	//freopen("bit.out","w",stdout);
	read(n);
	for(i=0;i<L;i++)read(c[i]);
	read(x);dp[start[0]=0]=pre=ans=c[0];
	for(i=2;i<=1<<n;i++){
		read(x);start[x]=now++;
		dp[start[x]]=c[(i-1)%L]^pre;
		for(k=0,j=n;j>=1;j--){
			if(!(1<<j-1&x))continue;
			int pos=start[x^(1<<j-1)]+k;
			dp[now]=dp[now-1]+dp[pos];
			now++,k++;
		}	
		ans^=pre=dp[now-1];
	}
	cout<<ans<<endl;
	return 0;
}


