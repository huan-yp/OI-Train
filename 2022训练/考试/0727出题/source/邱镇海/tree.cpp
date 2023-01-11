#include<cstdio>
const int N=200020;
int p[N],q[N],b[N],s[N];
double ans=2;
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int n,i,x;s[1]=1,s[2]=-1;
	scanf("%d",&n);
	if(n==1)return !puts("1.0000000");
	for(i=1;i<=n;i++)scanf("%d",&x),p[x]=i;
	for(i=1;i<=n;i++)scanf("%d",&x),q[p[x]]=i;
	for(i=1;i<=n;i++)b[q[i]]=i;
	for(i=2;i<n;i++)if(b[i]>b[i+1])s[i]++,s[i+1]--,ans+=1;
	for(i=1;i<n;i++)if(q[i]+1<q[i+1])s[q[i]]++,s[q[i+1]]--;
	for(x=0,i=1;i<n;i++)x+=s[i],(!x?ans+=0.5:0);
	printf("%.6lf\n",ans);
	return 0;
} 
