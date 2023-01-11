#include<bits/stdc++.h>
#define INF 1000000000
#define LL long long
using namespace std;
inline void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
void cmin(int &a,int b){a=min(a,b);}
void cmax(int &a,int b){a=max(a,b);}
const int N=300005;
int i,j,k,n,s,t,m;
int a[N],pd[N],dp[N][2];
struct BIT{
	int c[N];
	int low(int x){
		return x&(-x);
	}
	void updata(int x,int cc){
		for(;x<=n;x+=low(x))cmax(c[x],cc);
	}
	int quert(int x,int ret=-INF){
		for(;x>=1;x-=low(x))cmax(ret,c[x]);
		return ret;
	}
	void clear(){
		for(i=0;i<=n;i++)c[i]=-INF;
	}
}B1,B0;
signed main()
{
 	freopen("subseq.in","r",stdin);
	freopen("subseq.out","w",stdout);
	read(t);
	while(t--){
		//cnt+a=b+b;
		//a+cnt=b;
		read(n);int maxn=0,cnt=0;
		B1.clear(),B0.clear();
		for(i=1;i<=n;i++)read(a[i]),pd[i]=0;
		for(i=1;i<=n;i++)if(a[i]>maxn)cnt++,maxn=a[i],pd[i]=1;
		if(cnt%2==0){
			puts("YES");
			continue;
		}
		maxn=0;
		B0.updata(1,0);
		for(i=1;i<=n;i++){
			dp[i][1]=B1.quert(a[i])+(1+(pd[i]));
			B1.updata(a[i],dp[i][1]);
			if(pd[i]){
				dp[i][0]=B0.quert(a[i])+2;	
				B0.updata(a[i],dp[i][0]);
			}
			else{
				cmax(dp[i][1],B0.quert(a[i])+1);
				B1.updata(a[i],dp[i][1]);
			}
			cmax(maxn,dp[i][1]);
		}
		if(maxn>=cnt)puts("YES");
		else puts("NO");
	}
	return 0;
}

