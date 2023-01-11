#include<bits/stdc++.h>
#define LL long long
#define y1 y3647
#define pii pair<int,int>
using namespace std;
void read(int &x){
	char ch=getchar();x=0;int f=1;
	while((ch<'0'||ch>'9')&&ch!=45)ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	x*=f;
}
template<typename _type>
void cmax(_type &x,const _type &y){x=max(x,y);}
template<typename _type>
void cmin(_type &x,const _type &y){x=min(x,y);}
const int N=2005,mod=1e9+7;
int i,j,k,m,n,s,t;
int dp[N][N];
char ch[N],str[N];
void Inc(int &x,const int &y){
	x+=y;if(x>=mod)x-=mod;
}
int main(){
//	freopen("expression.in","r",stdin);
//	freopen("expression.out","w",stdout);
	scanf("%s",ch+1);n=strlen(ch+1);
	for(i=1;i<=n;i++){
		if(ch[i]=='-'||ch[i]=='+')str[++s]='+';
		if(ch[i]=='/'||ch[i]=='*')str[++s]='*';
		if(ch[i]<='9'&&ch[i]>='0'&&(ch[i-1]>'9'||ch[i-1]<'0'))str[++s]='1';
	}
	n=s;dp[0][0]=1;
	for(i=1;i<=n;i++){
		if(str[i]=='+'||str[i]=='*'){
			for(j=1;j<=n;j++)
			Inc(dp[i][j],dp[i-1][j-1]);
		}
		if(str[i]=='*'&&str[i-1]!='1'){
			dp[n][0]=0;break;
		}
		if(str[i]=='1'){
			int sum=0;
			for(j=n;j>=0;j--)
			Inc(sum,dp[i-1][j]),Inc(dp[i][j],sum);
		}
	}
	cout<<dp[n][0]<<endl;
	return 0;
}

