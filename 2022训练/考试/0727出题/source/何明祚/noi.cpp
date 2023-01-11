#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define pb(x) push_back(x)
#define lowbit(x) x&-x
using namespace std;
ll ans;
int n,m,T,a[50][50];
inline int read(){
	int s=0,f=0;
	char ch=getchar();
	while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
	while(ch<='9'&&ch>='0') s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return f?-s:s;
}
int main(){
	freopen("noi.in","r",stdin);
	freopen("noi.out","w",stdout);
	n=read();
	printf("%d",n*m-5*n+4+2*n+2+n+4);
	return 0;
}
