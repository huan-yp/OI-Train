#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
using namespace std;
template<typename T>
inline int read(T &x){
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch<'0'||ch>'9'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*=f;
}
template<typename T1,typename T2>void cmin(T1 &a,const T2 &b){if(a>b)a=b;}
template<typename T1,typename T2>void cmax(T1 &a,const T2 &b){if(a<b)a=b;}
const int N=55,M=25;
int n,m;
int len[N],vis[N][M][M];
char ch[N][N],sig[N];
string dp[N][M][M];
bool cmp(const string &a,const string &b){
	if(a==b)return 0;
	if(b=="-")return 1;
	if(a=="-")return 0;
	return a<b;
}
void cmin(string &a,const string &b){
	if(cmp(b,a))a=b;
}
void DP(){
	int i,j,k;
	for(i=0;i<=m;i++){
		for(j=1;j<=n;j++){
			for(k=1;k<=len[j];k++){
				if(ch[j][k]>='a'&&i){
					if(dp[j][k-1][i-1]!="-")
					dp[j][k][i]=dp[j][k-1][i-1]+ch[j][k];
					continue;
				} 
				for(int s=1;s<=n;s++)
				if(sig[s]==ch[j][k]){
					for(int w=0;w<=i;w++)if(dp[j][k-1][w]!="-"&&dp[s][len[s]][i-w]!="-")	
					cmin(dp[j][k][i],dp[j][k-1][w]+dp[s][len[s]][i-w]);
				}	
			}
		}
	}
}
void ___solve(){
	int i,j,k;
	read(n),read(m);
	for(i=0;i<N;i++)for(j=0;j<M;j++)for(k=0;k<M;k++)dp[i][j][k]="-";
	for(i=1;i<=n;i++){
		dp[i][0][0]="";
		char chr=getchar();while(chr<'A')chr=getchar();
		sig[i]=chr;
		scanf("%s",ch[i]);
		len[i]=strlen(ch[i]+1);
	}
	for(i=1;i<=15;i++)DP();
	string ans="-";
	for(i=1;i<=n;i++)if(sig[i]=='S'){
		cmin(ans,dp[i][len[i]][m]);
	}
	cout<<ans<<endl;
}
signed main()
{
	int tot=1;
	while(tot--){
		___solve();
	}
	return 0;
}
