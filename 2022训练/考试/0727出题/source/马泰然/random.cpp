#include<bits/stdc++.h>
#define N 100010
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<48){if(c=='-')f=0;c=getchar();}
	while(c>=48) x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return f?x:-x;
}
int n,m,cur;
int a[N],cnt[N];
vector<int> vec;
void add(int x){
	cnt[x]++;
	if(cnt[x]==a[x]) cur++;
}
void del(int x){
	cnt[x]--;
	if(cnt[x]==a[x]-1) cur--;
}
void mul(int x){
	for(int i=2;i*i<=x;i++)
		while(x%i==0) add(i),x/=i;
	if(x>1) add(x);
}
void div(int x){
	for(int i=2;i*i<=x;i++)
		while(x%i==0) del(i),x/=i;
	if(x>1) del(x);
}
signed main(){
	freopen("random.in","r",stdin);
	freopen("random.out","w",stdout);
	n=read();n--;m=read();
	for(int i=2;i*i<=m;i++)
		while(m%i==0) a[i]++,m/=i;
	if(m>1){
		if(m>100000){cout<<0<<endl;return 0;}
		a[m]++;
	}
	for(int i=1;i<=100000;i++)
		if(cnt[i]>=a[i]) cur++;
	for(int i=0;i+i<=n;i++){
		if(cur==100000){
			if(i+i==n) vec.push_back(i);
			else vec.push_back(i),vec.push_back(n-i);
		}
		mul(n-i);div(i+1);
	}
	printf("%d\n",vec.size());
	if(vec.size()){
		sort(vec.begin(),vec.end());
		for(auto i:vec) printf("%d ",i+1);
		printf("\n");
	}
	return 0;
}
