#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int n,m;
int cnt[100001];
int pre[100001],suf[100001];
vector<int> ans;
int main(){
	freopen("random.in","r",stdin);
	freopen("random.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(m==1){
		printf("%d\n",n);
		for(int i=1;i<=n;i++){
			printf("%d ",i);
		}
	}
	for(int i=1;i<n;i++){
		int tmp=i;
		while(tmp%m==0){
			cnt[i]++;
			tmp/=m;
		}
	}
	for(int i=1;i<n;i++){
		pre[i]=pre[i-1]+cnt[i];
	}
	for(int i=n-1;i;i--){
		suf[i]=suf[i+1]+cnt[i];
	}
	
	for(int i=0;i<n;i++){
		if(suf[n-i]-pre[i]){
			ans.push_back(i+1);
		}
	}
	printf("%d\n",ans.size());
	for(int i:ans){
		printf("%d ",i);
	}
}
/*
In this problem, we know that r=(\sum_{i=1}^{n} \dbinom{n-1}{i-1}a[i])\bmod m.
So, a_i has no effect on the final result <=> m| \dbinom{n-1}{i-1} 
*/
