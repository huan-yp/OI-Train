#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;i++)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;i--)
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long
using namespace std;
const int N=1e7+5;
int n,x,y;
ll dp[N]; 
inline int read(){
	int f=1,x=0;
	char ch=getchar();
	while(ch>'9'||ch<'0') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {x=x*10+ch-'0';ch=getchar();}
	return f*x;
}
int main(){
	n=read(),x=read(),y=read();
	rep(i,1,n){
		if(i&1) dp[i]=min(dp[i-1]+x,min(dp[i>>1]+x+y,dp[(i+1)>>1]+x+y));
		else dp[i]=min(dp[i-1]+x,dp[i>>1]+y);	
	}
	printf("%lld",dp[n]);
	return 0;
}

