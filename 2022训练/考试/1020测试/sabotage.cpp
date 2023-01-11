#include<bits/stdc++.h>
#define LL long long
#define y1 y3647
#define INF 1000000000
using namespace std;
template<typename T1,typename T2>void cmax(T1 &x,const T2 &y){if(y>x)x=y;}
template<typename T1,typename T2>void cmin(T1 &x,const T2 &y){if(y<x)x=y;}
const int N=1e4+10,M=1<<10,mod=998244353;
int i,j,k,m,n,s,t;
int stat[2][20];
LL dp[2][M],ans;
template<typename T>
void read(T &x){
	x=0;char ch=getchar();int f=1;
	while((ch<'0'||ch>'9')&&ch!=45)ch=getchar();
	if(ch==45)ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	x*=f;
}
int main(){
	//when use memset,memcpy,DO NOT WRITE BYTES OUT OF THE RANGE
	//or you will get confusing runtime error
//	freopen("sabotage.in","r",stdin);
//	freopen("sabotage.out","w",stdout);
	scanf("%d%d",&m,&k);
	int statu=0,e;
	for(i=0;i<k;i++)scanf("%d",&e),statu|=e<<i;
	dp[0][statu]=1;
	for(i=2;i<m-1;i++){
		memset(dp[(i+1)&1],0,sizeof(dp[(i+1)&1]));
		memset(stat,0,sizeof(stat));
		for(j=0;j<k;j++)
		for(s=0;s<k;s++){
			read(e);
			stat[0][j]|=e<<s,stat[1][s]|=e<<j;
		}
		for(int mask=0;mask<1<<(k+1);mask++){
			int final=0;
			for(j=0;j<k;j++){
				int val=stat[mask>>k][j];
				if(!((1<<j)&mask)) val=0;
				final^=val;
			}
			dp[(i+1)&1][final]+=dp[i&1][mask&((1<<k)-1)];
		}
		for(int mask=0;mask<1<<k;mask++)
		dp[(i+1)&1][mask]%=mod;
	}
	for(statu=0,i=0;i<k;i++)scanf("%d",&e),statu|=e<<i;
	for(int mask=0;mask<1<<k;mask++){
		if(__builtin_popcount(mask&statu)%2==0)
		ans+=dp[(m-1)&1][mask]%mod;
	}
	cout<<ans%mod<<endl;
	return 0;
}

