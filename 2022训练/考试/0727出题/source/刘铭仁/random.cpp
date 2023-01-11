#include<bits/stdc++.h>
using namespace std;
int n,m,c[100005];
long long t[400005];
void build(int u,int l,int r) {
	t[u]=1;
	if(l==r)return;
	int mid=(l+r)>>1;
	build(u<<1,l,mid);
	build(u<<1|1,mid+1,r);
}
void update(int u,int l,int r,int x,int v) {
	if(l==r) {
		t[u]=v;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)update(u<<1,l,mid,x,v);
	else update(u<<1|1,mid+1,r,x,v);
	t[u]=t[u<<1]*t[u<<1|1]%m;
}
vector<pair<int,int>>g[100005];
long long fpow(long long x,int y) {
	long long res=1;
	while(y) {
		if(y&1)res=res*x%m;
		x=x*x%m;
		y>>=1;
	}
	return res;
}
vector<int>ans;
int main() {
	freopen("random.in","r",stdin);
	freopen("random.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++) {
		int x=i;
		for(int j=2; j*j<=i; j++) {
			int c=0;
			while(x%j==0)x/=j,c++;
			g[i].push_back(make_pair(j,c));
		}
		if(x!=1)g[i].push_back(make_pair(x,1));
	}
	build(1,1,n);
	for(int i=1; i<=n; i++) {
		if(t[1]==0)ans.push_back(i);
		if(i==n)break;
		for(pair<int,int>tmp:g[n-i]) {
			c[tmp.first]+=tmp.second;
			update(1,1,n,tmp.first,fpow(tmp.first,c[tmp.first]));
		}
		for(pair<int,int>tmp:g[i]) {
			c[tmp.first]-=tmp.second;
			update(1,1,n,tmp.first,fpow(tmp.first,c[tmp.first]));
		}
	}
	printf("%d\n",(int)ans.size());
	for(int x:ans)printf("%d ",x);
	return 0;
}
