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
const int N=105;
int j,k,n,s,t,m,tp1,tp2,xr;
int dp[N][N][2],pd[N],a[N];
char ch[N];
int solve(int l,int r,int op){
	if(l>r)return 0;
	if(~dp[l][r][op])return dp[l][r][op];
	vector<int> v(0);int i;
	for(i=max(1,l-1);i<=min(r,n-1);i++){
		if(!(a[max(i,l)]^op)&&!(a[min(i+1,r)]^op))continue;
		v.push_back(solve(l,i-1,op^1)^solve(i+2,r,op^1));
	}
	for(auto val:v)pd[val]=1;
	for(i=0;i<=r-l+2;i++)
	if(pd[i]==0)break;
	for(auto val:v)pd[val]=0;
	cmax(xr,i);
	return dp[l][r][op]=i;
}
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen("1.out","w",stdout);
//	freopen(".in","w",stdout);
	read(t);
	while(t--){
		int i,cnt=0;
		
//		read(n);
		assert(n<100);
		scanf("%s",ch+1);
		n=strlen(ch+1);
		for(i=1;i<=n;i++)memset(dp[i],-1,sizeof(dp[i]));
		int ca=0,cb=0;
		for(i=1;i<=n;i++)a[i]=ch[i]=='R';
		for(i=2;i<=n-1;i++)
		if(a[1])ca+=a[1]==a[2]; else cb+=a[1]==a[2]; 
		if(a[n])ca+=a[n]==a[n-1]; else cb+=a[n]==a[n-1];
		if(solve(1,n,0))puts("Alice");
		else puts("Bob");
		for(int l=1;l<=n;l++)
		for(int r=l;r<=n;r++){
			if(~dp[l][r][0]||~dp[l][r][1])cnt++;
		}
//		cout<<cnt<<' '<<xr<<endl;
//		cout<<dp[1][n][0]<<endl;
	}
	return 0;
}


