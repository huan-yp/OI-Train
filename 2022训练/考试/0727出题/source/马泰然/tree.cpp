#include<bits/stdc++.h>
#define N 200010
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<48){if(c=='-')f=0;c=getchar();}
	while(c>=48) x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return f?x:-x;
}
int n;
int d[N],dfn[N],bfn[N],f[N];
double ans;
signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	n=read();
	if(n==1){cout<<1<<endl;return 0;}
	for(int i=1;i<=n;i++) d[i]=read();
	for(int i=1;i<=n;i++) bfn[read()]=i;
	for(int i=1;i<=n;i++) d[i]=bfn[d[i]],dfn[d[i]]=i;
	f[1]++,f[2]--;ans=2;
	for(int i=1;i<n;i++)
		if(dfn[i]>dfn[i+1]){
			ans+=1;
			f[i]++;f[i+1]--;
		}
	for(int i=1;i<n;i++)
		if(d[i]+1<d[i+1]) f[d[i]]++,f[d[i+1]]--;
	for(int i=1;i<n;i++){
		f[i]+=f[i-1];
		if(!f[i]) ans+=0.5;
	}
	cout<<ans<<endl;
	return 0;
}
