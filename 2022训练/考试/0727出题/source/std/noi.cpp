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
const int N=155,M=515; 
int i,j,k,n,s,t,m,ans=-INF;
int a[M][M],sum[M][M],dp[2][3][N][N],ans1[M],ans2[M],dp_max[M];
#define get(t,b,l,r) (sum[b][r]+sum[t-1][l-1]-sum[t-1][r]-sum[b][l-1])
#define get_v(x,b) (sum[b][x]-sum[b][x-1])
#define get_h(x,r) (sum[x][r]-sum[x-1][r])
//inline int get(int t,int b,int l,int r){
//	return sum[b][r]+sum[t-1][l-1]-sum[t-1][r]-sum[b][l-1];
//}
//inline int get_h(int x,int r){return get(x,x,1,r);}
//inline int get_v(int x,int b){return get(1,b,x,x);}
void solve1(){
		for(i=1;i<=m;i++){
		memset(dp[i&1],191,sizeof(dp[i&1]));
		ans1[i]=ans1[i-1];
		for(j=1;j<=n;j++)
		for(k=j;k<=n;k++){
			int v=get(j,k,i,i);
			dp[i&1][0][j][k]=max(dp[i-1&1][0][j][k],0)+v;
			dp[i&1][2][j][k]=dp[i-1&1][2][j][k]+v;
			cmax(ans1[i],dp[i-1&1][2][j][k]);
		}
		memset(dp_max,191,sizeof(dp_max));
		for(int l=1;l<=n;l++){//1-1
			for(int r=l,max_val=dp_max[l-1];r<=n;r++){
				cmax(dp_max[r],dp[i-1&1][1][l][r]);
				cmax(max_val,dp_max[r]);
				dp[i&1][1][l][r]=max_val+get(l,r,i,i);
			}
		}
		for(int l=1;l<n;l++){//0-1	
			for(int r=n-1,max_val=dp[i-1&1][0][l][n];r>=l;r--){
				cmax(dp[i&1][1][l][r],max_val+get(l,r,i,i));
				cmax(max_val,dp[i-1&1][0][l][r]);
			}
		}
		for(int r=n;r>1;r--){//1-2
			for(int l=r-1,max_val=dp[i-1&1][1][r][r];l>=1;l--){
				cmax(dp[i&1][2][l][r],max_val+get(l,r,i,i));
				cmax(max_val,dp[i-1&1][1][l][r]);
			}
		}
	}
}
void solve2(){
	for(int l=1;l<n;l++){
		for(int r=l+2;r<=n;r++){
			int max_h=get_h(l,m)+get_h(r,m);
			int max_suf=sum[r-1][m-1]-sum[l][m-1]+max_h;
			int max_val=max_suf-(sum[r-1][m-2]-sum[l][m-2]);
			for(i=m-2;i>=1;i--){
				cmax(ans2[i-1],max(ans2[i],max_val-get_h(l,i-1)-get_h(r,i-1)));
				cmax(max_h,get_h(l,i+1)+get_h(r,i+1));
				cmax(max_suf,sum[r-1][i]-sum[l][i]+max_h);
				cmax(max_val,-(sum[r-1][i-1]-sum[l][i-1])+max_suf);				
			}
		}
	}
}
void solve3(){
	int max_val[M][M];
	memset(max_val,191,sizeof(max_val));
	for(int l=5;l<=m;l++)
	for(int r=l+2;r<=m-4;r++)
	max_val[l][r]=get(n,n,l,r)+get_v(l,n-1)+get_v(r,n-1);
	
	for(i=n-2;i>=1;i--){
		for(int l=5;l<=m;l++){
			for(int r=l+2;r<=m-4;r++){
				int o_val=-get_v(l,i-1)-get_v(r,i-1)+get(i,i,l+1,r-1)+max_val[l][r];
				cmax(ans,ans1[l-1]+ans2[r+1]+o_val);
				cmax(max_val[l][r],get(i+1,i+1,l,r)+get_v(l,i)+get_v(r,i));
			
			}
		}
	}
}
signed main()
{
 	freopen("noi.in","r",stdin);
	freopen("noi.out","w",stdout);
	read(n),read(m);
	memset(ans1,191,sizeof(ans1));
	memset(ans2,191,sizeof(ans2));
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++){
		read(a[i][j]);
		sum[i][j]=a[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
	}
	memset(dp,191,sizeof(dp));
	solve1();
	solve2();
	solve3();


	cout<<ans<<endl;
	return 0;
}
