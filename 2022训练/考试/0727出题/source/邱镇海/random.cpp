#include<cstdio>
const int N=100010,M=25;
int st[M],tp;
int ans[N],tot;
struct node{
	int a[M];
	node operator-(const node &A)const {
		node c;
		for(int i=1;i<=tp;i++)c.a[i]=a[i]-A.a[i];
		return c;
	} 
	bool operator>(const node &A)const {
		for(int i=1;i<=tp;i++)if(a[i]<A.a[i])return 0;
		return 1;
	}
}fac[N],mm;
int main(){
	freopen("random.in","r",stdin);
	freopen("random.out","w",stdout);
	int n,m,i,j,u;
	scanf("%d%d",&n,&m);
	for(i=2;i*i<=m;i++){
		if(m%i==0){
			st[++tp]=i;
			while(m%i==0)m/=i,mm.a[tp]++;
		}
	}
	if(m>1)st[++tp]=m,mm.a[tp]++;
	for(i=2;i<=n;i++){
		fac[i]=fac[i-1],u=i;
		for(j=1;j<=tp;j++)if(u%st[j]==0){
			while(u%st[j]==0)fac[i].a[j]++,u/=st[j];
		}
	}
	for(i=0;i<=n-1;i++){
		if((fac[n-1]-fac[i]-fac[n-1-i])>mm)ans[++tot]=i+1;
	}
	printf("%d\n",tot);
	for(i=1;i<=tot;i++)printf("%d ",ans[i]);
	return 0;
}
