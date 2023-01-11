#include<bits/stdc++.h>
#define int long long
using namespace std;
template<typename T>
int read(T &x){
	x=0;char ch=getchar();int f=1;
	while((ch<'0'||ch>'9')&&ch!=45)ch=getchar();
	if(ch==45)ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	return x*=f;
}
template<typename T1,typename T2>void cmax(T1 &a,const T2 &b){if(b>a)a=b;}
template<typename T1,typename T2>void cmin(T1 &a,const T2 &b){if(b<a)a=b;}
const int N=5005;
int i,j,k,m,n,s,t,top;
int lst[N],dp[N][N],ans[N*2],st[N];
char ch[N][N];
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	//freopen(".in","w",stdout);
	read(n),read(m);k=max(n,m)+1;
	for(i=1;i<=n;i++){
		st[top=0]=0;
		scanf("%s",ch[i]+1);
		for(j=1;j<=m;j++){
			if(ch[i][j]=='.'){
				while(top&&lst[st[top]]<=lst[j])top--;
				dp[i][j]=max(dp[i][st[top]]+j-st[top],j-st[top]+i-lst[j]);
				ans[dp[i][j]]++;st[++top]=j;
			}
			else{
				lst[j]=i;st[top=0]=j;
			}
		}
	}
	for(i=1;i<=n+m;i++)printf("%lld ",ans[i]);
	return 0;
}


