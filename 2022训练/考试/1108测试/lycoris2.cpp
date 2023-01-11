/*
First contest after losing you.
In memory of you.
The smile lighting me up.
*/
#include<bits/stdc++.h>
using namespace std;
template<typename T>
void read(T &x){
	x=0;char ch=getchar();int f=1;
	while((ch<'0'||ch>'9')&&ch!=45)ch=getchar();
	if(ch==45)ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
template<typename T1,typename T2>void cmin(T1 &x,const T2 &y){if(y<x)x=y;}
template<typename T1,typename T2>void cmax(T1 &x,const T2 &y){if(y>x)x=y;}
const int N=12005,M=700,mod=993244353;
int i,j,k,n,t,ans;
long long dp[N][M*2];
char ch[N];
bool match(const char* text,const char* temp){
	for(int i=0;i<strlen(temp);i++)
	if(*(text+i)!=*(temp+i)&&*(text+i)!='?')return false;
	return true;
}
int main(){
//	freopen("lycoris.in","r",stdin);
//	freopen("lycoris.out","w",stdout);
	const char* s1="sakana";
	const char* s2="chinanago";
	read(n);scanf("%s",ch+1);
	dp[0][M]=1;
	for(i=0;i<n;i++){
		int start=M-min(i/6,(n-i)/9)-2,end=min(M+min(i/9,(n-i)/6)+2,2*M);
		for(j=max(start,0);j<end;j++){
			if(!dp[i][j])continue;
			dp[i+9][j+1]=((match(ch+i+1,s2)?dp[i][j]:0)+dp[i+9][j+1])%mod;
			dp[i+6][j-1]=((match(ch+i+1,s1)?dp[i][j]:0)+dp[i+6][j-1])%mod;
			dp[i+9][j]=((match(ch+i+1,s2)?-dp[i][j]:0)+dp[i+9][j])%mod;
			dp[i+6][j]=((match(ch+i+1,s1)?-dp[i][j]:0)+dp[i+6][j])%mod;
			dp[i+1][j]=(dp[i+1][j]+dp[i][j]*(ch[i+1]!='?'?1:26ll))%mod;
		}
	}
	cout<<(dp[n][M]+mod)%mod<<endl;
	return 0;
}

