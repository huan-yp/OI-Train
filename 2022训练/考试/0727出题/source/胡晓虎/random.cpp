#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,f[100005][55],p[55],a[55],cnt;
vector<int>ans;
void doing(int x){
	for(int i=1;i*p[x]<=n;i++) f[i*p[x]][x]=f[i][x]+1;
	for(int i=1;i<=n;i++) f[i][x]+=f[i-1][x];
}
bool check(int n,int m){
	for(int i=1;i<=cnt;i++) if(f[n][i]-f[m][i]-f[n-m][i]<a[i]) return false;
	return true;
}
signed main(){
	freopen("random.in","r",stdin);
	freoepn("random.out","w",stdout);
	cin>>n>>m;
	int t=m;
	for(int i=2;i*i<=t;i++){
		if(t%i==0){
			p[++cnt]=i;
			while(t%i==0){
				t/=i;
				a[cnt]++;
			}
		}
	}
	if(t-1){
		p[++cnt]=t;
		a[cnt]=1;
	}
	for(int i=1;i<=cnt;i++) doing(i);
	for(int i=1;i<=n;i++) if(check(n-1,i-1)) ans.push_back(i);
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++) printf("%lld ",ans[i]);
}
