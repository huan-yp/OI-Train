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
const int N=1e5+10,M=1e3+10;
int i,j,k,n,s,t,m;
char ch[N],str[N];
int dp[M][M],nxt[N],trans[N][26];
void print(int n,int x){
	if(n==0)return ;
	for(int j=0;j<=m;j++)
	for(int k=0;k<26;k++){
		if(dp[n][x]!=dp[n-1][j]+(j==m)||trans[j][k]!=x||(ch[n]!='?'&&k+'a'!=ch[n]))continue;
		print(n-1,j);
		putchar('a'+k);
		return ;
	}
}
signed main()
{
 	//freopen("match.in","r",stdin);
	//freopen("match.out","w",stdout);
	//freopen(".in","w",stdout);
	scanf("%s%s",ch+1,str+1);
	n=strlen(ch+1),m=strlen(str+1);
	int ans=0;
	j=nxt[0]=-1;
	for(i=1;i<=m;i++){
		while(j!=-1&&str[i]!=str[j+1])j=nxt[j];
		nxt[i]=++j;
	}
	if(n>1000&&m>1000){
		for(i=1;i<=n;i++){
			while(j!=-1&&str[j+1]!=ch[i])j=nxt[j];
			j++;
			if(j==m){
				j=nxt[j];
				ans++;
			}
		}
		cout<<ans<<endl;
		cout<<ch+1;
		return 0;
	}
	trans[0][str[1]-'a']=1;
	for(i=1;i<=m;i++)
	for(j=0;j<26;j++){
		if(str[i+1]=='a'+j)trans[i][j]=i+1;
		else trans[i][j]=trans[nxt[i]][j];
	}
	memset(dp,191,sizeof(dp));
	dp[0][0]=0;
	for(i=0;i<n;i++){
	
		for(j=0;j<=m;j++){
			if(ch[i+1]!='?'){
				cmax(dp[i+1][trans[j][ch[i+1]-'a']],dp[i][j]+(j==m));
				continue;
			}
			for(k=0;k<26;k++){
				cmax(dp[i+1][trans[j][k]],dp[i][j]+(j==m));
			}
		}
	}
	for(i=0;i<=m;i++)cmax(ans,dp[n][i]+(i==m));
	cout<<ans<<endl;
	for(i=0;i<=m;i++){
		if((dp[n][i]+(i==m))!=ans)continue;
		print(n,i);
		return 0;
	}
	return 0;
}


