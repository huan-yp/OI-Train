#include<bits/stdc++.h>
using namespace std;
int p[100100],fl[100100],c,id[101000];
const int N=1e5;
void sieve(){
	for(int i=2;i<=N;i++)if(!fl[i]){
		p[++c]=i;
		for(int j=2;i*j<=N;j++)fl[j]=1;
		id[i]=c;
	}
}
int zc[101000];bool fuk;
int num=0;
void ins(int x,int z){
	for(int i=1;p[i]*p[i]<=x&&i<=c;i++)if(!(x%p[i])){
		while(!(x%p[i])){
			num-=(zc[i]<0);
			x/=p[i],zc[i]+=z;
			num+=(zc[i]<0);
		}
	}
	if(x>N){fuk=1;return;}
	if(x>1){
		num-=(zc[id[x]]<0);
		zc[id[x]]+=z;
		num+=(zc[id[x]]<0);
	}
}
int main(){
	freopen("random.in","r",stdin);
	freopen("random.out","w",stdout);
	sieve();
	int n,mod;
	scanf("%d%d",&n,&mod);
	if(mod==1){
		printf("%d\n",n);
		for(int i=1;i<=n;i++)printf("%d\n",i);
		return 0;
	}
	ins(mod,-1);n--;
	vector<int>ans;
	for(int i=0;i<=n;i++){
		if(i>0)ins(n-i+1,1),ins(i,-1);
		if(!fuk&&num==0)ans.push_back(i);
	}
	printf("%d\n",(int)ans.size());
	for(int i=0;i<(int)ans.size();i++)printf("%d\n",ans[i]+1);
	return 0;
}
