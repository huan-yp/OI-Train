#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,fz=1;
	char ch;
	while((ch=getchar())<'0'||ch>'9')if(ch=='-')fz=-1;
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*fz;
}
const int N=1e5;
int req[20],num[20],tp;
int f[N+2],g[N+2][20];
int prim[N+2],cnt,id[N+2];
void prep(int n){
	for(int i=2;i<=n;i++){
		if(!f[i]) f[i]=i,prim[++cnt]=i;
		for(int j=1;j<=cnt&&prim[j]*i<=n;j++){
			f[i*prim[j]]=prim[j];
			if(i%prim[j]==0) break;
		}
	}
}
vector<int> ans;
bool check(int x,int n){
	for(int i=1;i<=tp;i++)
		if(num[i]>g[n][i]-g[x][i]-g[n-x][i]) return false;
	return true;
}
int main(){
	freopen("random.in","r",stdin);
	freopen("random.out","w",stdout);
	int n=read()-1,m=read();
	prep(n);
	for(int i=1;i<=cnt;i++){
		if(m%prim[i]==0) req[++tp]=prim[i],id[prim[i]]=tp;
		while(m%prim[i]==0) num[tp]++,m/=prim[i];
		if(m==1) break;
	}
	if(m!=1) {
		putchar('0'); return 0;
	}
	for(int i=1;i<=n;i++){
		int x=i;
		for(int j=0;j<=tp;j++) g[i][j]=g[i-1][j];
		while(x!=1){
			g[i][id[f[x]]]++;
			x/=f[x];
		}
	}
	for(int i=0;i<=n;i++) if(check(i,n)) ans.push_back(i);
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++) printf("%d ",ans[i]+1);
	return 0;
} 
