#include<bits/stdc++.h>
using namespace std;

#define int long long
int n,m;

inline int read(){
	int res=0,f=1;char ch;
	do{ch=getchar();if(ch=='-')f=-1;}while(!isdigit(ch));
	do{res=res*10+ch-'0';ch=getchar();}while(isdigit(ch));
	return res*f;
}

void solve(){
	int n=read(),m=read();
	printf("%lld\n",n+m);
}

signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int T=read();while(T--)solve();
	return 0;
}
