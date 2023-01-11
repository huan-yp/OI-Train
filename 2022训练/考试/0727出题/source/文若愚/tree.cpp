#include<bits/stdc++.h>
const int N=200005;
using namespace std;
int bfs[N],dfs[N],num[N],s[N],a[N],b[N],n;
double ans;
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);
		dfs[x]=i;
	}
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);
		bfs[dfs[x]]=i;
		num[i]=dfs[x];
	}
	a[1]=1;
	b[1]++;b[2]--;
	for(int i=2;i<=n;i++){
		if(num[i]>num[i+1]){
			a[i]=1;
			b[i]++;b[i+1]--;
		}
	}
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		if(bfs[i]<bfs[i+1]&&s[bfs[i+1]-1]-s[bfs[i]-1]){
			b[bfs[i]]++;
			b[bfs[i+1]]--;
		}
	}
	for(int i=1;i<=n;i++){
		b[i]+=b[i-1];
		ans+=b[i]?a[i]:0.5;
	}
	printf("%.3lf",ans);
}