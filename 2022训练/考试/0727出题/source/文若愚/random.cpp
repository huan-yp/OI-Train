#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,pri[N],c[N],ct1,suf[N][100];
void init(){
    for(int i=2;i*i<=m;i++){
        if(m%i==0){
            pri[++ct1]=i;
            while(m%i==0)m/=i,c[ct1]++;
        }
    }
	if(m!=1)pri[++ct1]=m,c[ct1]=1;
	for(int i=1;i<n;i++){
		int now=i;
		for(int o=1;o<=ct1;o++){
			suf[i][o]=suf[i-1][o];
			int kk=pri[o];
			while(now%kk==0)now/=kk,suf[i][o]++;
		}
	}
}
int main(){
	freopen("random.in","r",stdin);
	freopen("random.out","w",stdout);
	scanf("%d%d",&n,&m);
    init();
    int ans[N],ct2=0;
	for(int i=1;i<=n-1;i++){
		int pd=1;
		for(int o=1;o<=ct1;o++)if(suf[n-1][o]-suf[i][o]-suf[n-i-1][o]<c[o])pd=0;
		if(pd)ans[++ct2]=i+1;
	}
	printf("%d\n",ct2);
	for(int i=1;i<=ct2;i++)printf("%d ",ans[ct2]);
	return 0;
}
