#include<bits/stdc++.h>
#define int long long
#define INF 1000000000
using namespace std;
template<typename T>
void read(T &x){
	x=0;char ch=getchar();int f=1;
	while((ch<'0'||ch>'9')&&ch!=45)ch=getchar();
	if(ch==45)ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	x*=f;
}
const int N=1e5+10;
int i,j,k,m,n,s,t,top,ans;
int st[N],b[N],f[2][N],g[2][N],a[N];
struct ques{
	int l1,r1,l2,r2,res;
	void init(){
		read(l1),read(r1),read(l2),read(r2);
	}
}q[N];
struct RMQ{
	int st[N][17],b[N],lo[N];
	int merge(int x,int y){return b[x]>b[y]?x:y;}
	void init(int a[]){
		memcpy(b,a,sizeof(b));st[1][0]=1,lo[1]=0;
		for(i=2;i<N;i++)st[i][0]=i,lo[i]=lo[i>>1]+1;
		for(i=1;i<=16;i++)
		for(j=1;j+(1<<i)-1<N;j++)
		st[j][i]=merge(st[j][i-1],st[j+(1<<i-1)][i-1]);
	}
	int ask(int l,int r){
		int len=log2(r-l+1);
		return merge(st[l][len],st[r-(1<<len)+1][len]);
	}
}R;
int solve(int l,int r){
	if(l>r)return 0;
	int mid=R.ask(l,r);
	return g[0][r]-g[0][mid]-f[0][mid]*(r-mid)+g[1][l]-g[1][mid]-f[1][mid]*(mid-l)+(r-mid+1)*(mid-l+1)*a[mid];
}
void solve(ques &q){
	q.res+=solve(q.l1,q.r2)-solve(q.r1+1,q.r2)-solve(q.l1,q.l2-1)+solve(q.r1+1,q.l2-1);
}
void get_pre(int f[],int g[]){
	top=0;int now=0;
	for(i=1;i<N;i++){
		now+=a[i];
		while(top&&a[i]>=a[st[top]]){
			now+=(st[top]-st[top-1])*(a[i]-a[st[top]]);
			top--;
		}
		st[++top]=i;
		g[i]=g[i-1]+(f[i]=now);
	}
}
void solve(){
	R.init(a);
	get_pre(f[0],g[0]);reverse(a+1,a+N);
	get_pre(f[1],g[1]);reverse(a+1,a+N);
	reverse(g[1]+1,g[1]+N),reverse(f[1]+1,f[1]+N);
	for(i=1;i<=t;i++)
	solve(q[i]);
}
signed main(){
	int p1=1,p2=1;
	for(i=1;i<N;i++)a[i]=((p1*=1023)%=INF)^((p2*=1025)%=INF);
	for(i=1;i<N;i++)b[i]=-a[i];
	read(t);
	for(i=1;i<=t;i++)q[i].init();
	solve();swap(a,b);solve();
	for(i=1;i<=t;i++)printf("%lld\n",q[i].res);
	return 0;
}

