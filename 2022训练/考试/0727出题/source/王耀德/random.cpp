#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
int n,m;
vector<int>prm,val;
vector<int>prms,vals;
int isp[100005];
void go(int x,int add){
	for(int i=2;i*i<=x;++i){
		while(x%i==0){
			vals[isp[i]]+=add;
			x/=i;
		}
	}
	if(x!=1)vals[isp[x]]+=add;
}
bool check(){
	for(int i=0;i<prm.size();++i){
		if(vals[prm[i]]<val[i])return false;
	}
	return true;
}
int main(){
//*
	freopen("random.in","r",stdin);
	freopen("random.out","w",stdout);//*/
	memset(isp,-1,sizeof(isp));
	scanf("%d%d",&n,&m);
	--n;
	if(m==1){
		printf("%d\n",n+1);
		for(int i=1;i<=n+1;++i)printf("%d ",i);
		printf("\n");
		return 0;
	}
	for(int i=2;i*i<=100000;++i){
		if(isp[i]==-1){
			for(int j=i*i;j<=100000;j+=i)isp[j]=-2;
		}
	}
	for(int i=2;i<=100000;++i){
		if(isp[i]==-1){
			isp[i]=prms.size();
			prms.push_back(i);
		}
	}
	vals.resize(prms.size(),0);
	for(int i=0;i<prms.size();++i){
		int k=0;
		while(m%prms[i]==0){
			m/=prms[i];
			++k;
		}
		if(k!=0)val.push_back(k);
	}
	if(m!=1){
		printf("0\n");
		return 0;
	}
	vector<int>ans;
	for(int i=1;i<n;++i){
		go(n-i+1,1);
		go(i,-1);
		if(check())ans.push_back(i+1);
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();++i){
		printf("%d ",ans[i]);
	}
	return 0;
}

