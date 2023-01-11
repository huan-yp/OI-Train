#include<bits/stdc++.h>
#define debug(...) std::cerr<<#__VA_ARGS__<<" : "<<__VA_ARGS__<<std::endl
typedef long long ll;
const int maxn=200005;
int n; double ans;
int a[maxn],b[maxn],pbfs[maxn],pdfs[maxn],temp[maxn]; ll cha[maxn];
void add(int x,int y) {cha[x]++; cha[y]--;}
int main() {
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n); add(1,2); ans=2; //bfs[1] and bfs[2] depth + 1
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	for(int i=1;i<=n;i++) temp[a[i]]=i;
	for(int i=1;i<=n;i++) pbfs[i]=temp[b[i]];
	for(int i=1;i<=n;i++) temp[b[i]]=i;
	for(int i=1;i<=n;i++) pdfs[i]=temp[a[i]];
	for(int i=1;i<n;i++) if(pbfs[i]>pbfs[i+1]) add(i,i+1),ans++;
	for(int i=1;i<n;i++) if(pdfs[i]+1<pdfs[i+1]) add(pdfs[i],pdfs[i+1]);
	for(int i=1;i<=n;i++) cha[i]+=cha[i-1];
	for(int i=1;i<n;i++) if(cha[i]==0ll) ans+=0.5;
	printf("%.14lf\n",ans);
	return 0;
}
