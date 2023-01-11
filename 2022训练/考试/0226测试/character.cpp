#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
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
const int N=1e5+10,mod=1e9+7;
int i,j,k,n,s,t,m,ans;
int dp[N],nxt[N],sum[N],nxtb[N],nxtv[N][3];
char ch[N];
int get(int l,int r){
	return (sum[r]-sum[l-1]+3)%3;
}
int get(int pos){
	return get(pos,pos);
}
signed main()
{
 	freopen("character.in","r",stdin);
	freopen("character.out","w",stdout);
	scanf("%s",ch+1);
	int flag=1;
	n=strlen(ch+1);
	for(i=1;i<n;i++)if(ch[i]==ch[i+1])flag=0;
	if(flag){
		puts("1");
		return 0;
	}
	for(i=1;i<=n;i++)sum[i]=(sum[i-1]+(ch[i]=='a'?1:2))%3;
	nxtb[n]=n+1,nxtv[n][0]=nxtv[n][1]=nxtv[n][2]=n+1;
	nxtv[n][get(n,n)]=n;
	for(i=n-1;i>=1;i--){
		nxtb[i]=nxtb[i+1];
		if(ch[i]==ch[i+1])nxtb[i]=i+1;
		nxtv[i][0]=nxtv[i+1][(0-get(i)+3)%3];
		nxtv[i][1]=nxtv[i+1][(1-get(i)+3)%3];
		nxtv[i][2]=nxtv[i+1][(2-get(i)+3)%3];
		nxtv[i][get(i,i)]=i;
	}
	dp[0]=1;
	for(i=0;i<n;i++){
		int val=3-get(i+1),pos=nxtb[i+1];
		pos=nxtv[pos][(val-get(i+1,pos-1)+3)%3];
		nxt[i]=pos;
	}
	for(i=0;i<n;i++){
		dp[i+1]+=dp[i],dp[i+1]%=mod;
		dp[nxt[i]]+=dp[i],dp[nxt[i]]%=mod;
		if(get(i+1,n)==0&&i)ans+=dp[i],ans%=mod;
	}
	cout<<(ans+dp[n])%mod<<endl;
	return 0;
}

