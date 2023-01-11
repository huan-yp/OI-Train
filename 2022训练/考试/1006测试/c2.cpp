#include<bits/stdc++.h>
#define int long long
#define y1 y3647
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
template<typename T1,typename T2>void cmax(T1 &x,const T2 &y){if(y>x)x=y;}
template<typename T1,typename T2>void cmin(T1 &x,const T2 &y){if(y<x)x=y;}
const int N=1e5+10,M=350;
int i,j,k,m,n,s,t,top,ans;
int a[N+100]={3,5,7,1,4,6,8,2,1,6,2,6,7,1,9,4,6,5,7,1,6,8,3,5,8,6,1,5};
int st[N][2],b[N+100],suf[M][N],pre[M][N],blk[N],l[N],r[N],tmp[N];
struct ques{
	int l1,r1,l2,r2,res;
	void init(){
		read(l1),read(r1),read(l2),read(r2);
	}
}q[N];
int quick(int a,int s,int mod,int ret=1){
	while(s){
		if(s&1)ret=1ll*ret*a%mod;
		a=1ll*a*a%mod;s>>=1;
	}
	return ret;
}
struct RMQ{
	int st[N][18];
	void init(int a[]){
		for(i=1;i<N;i++)st[i][0]=a[i];
		for(i=1;i<=18;i++)
		for(j=1;j+(1<<i)-1<N;j++)
		st[j][i]=max(st[j][i-1],st[j+(1<<i-1)][i-1]);
	}
	int ask(int l,int r){
		int len=log2(r-l+1);
		return max(st[l][len],st[r-(1<<len)+1][len]);
	}
}R;
int solve(int l1,int r1,int l2,int r2,int ans[]){
	cmax(l1,1);int now=0,all=0;top=0;st[0][0]=l1-1;
	for(int i=l1;i<=max(r1,r2);i++){
		int pos=r1,val=a[i];
		if(i>r1&&i<l2){val=R.ask(i,l2);i=l2;}
		if(i<=r1){now+=a[i];pos=i;}
		while(top&&val>=st[top][1]){
			now+=(val-st[top][1])*(st[top][0]-st[top-1][0]);
			top--;
		}
		if(pos!=st[top][0])st[++top][0]=pos,st[top][1]=val;	
		if(i>=l2&&i<=r2)ans[i]=ans[i-1]+now,all+=now;
	}
	return all;
}
void solve(ques &q){
	int l1=q.l1,l2=q.l2,r1=q.r1,r2=q.r2;
	int bl1=blk[l1],br1=blk[r1],bl2=blk[l2],br2=blk[r2];
	for(int i=bl1;i<=br1;i++)
	q.res+=pre[i][r2]-pre[i][l2-1];
	for(int i=bl2;i<=br2;i++)
	q.res-=-suf[i][l1]+suf[i][l[bl1]]-suf[i][r[br1]+1]+suf[i][r1+1];
	q.res+=solve(l[bl1],l1-1,l[bl2],l2-1,tmp)+solve(r1+1,r[br1],l[bl2],l2-1,tmp)+solve(l[bl1],l1-1,r2+1,r[br2],tmp)+solve(r1+1,r[br1],r2+1,r[br2],tmp);
}
void solve(){
	memset(suf,0,sizeof(suf));
	memset(pre,0,sizeof(pre));
	R.init(a);
	for(i=1;i<=blk[N-1];i++)
	solve(l[i],r[i],1,N-1,pre[i]);
	
	reverse(a+1,a+N);
	for(i=1;i<=blk[N-1];i++){
		solve(N-r[i],N-l[i],1,N-1,suf[i]);
		reverse(suf[i]+1,suf[i]+N);
	}
	reverse(a+1,a+N);
	for(i=1;i<=t;i++)
	solve(q[i]);
}
signed main(){
//	freopen("c.in","r",stdin);
//	freopen("c.out","w",stdout);
	for(i=1;i<N;i++)blk[i]=(i-1)/M+1;
	for(i=1;i<M;i++)l[i]=(i-1)*M+1,r[i]=i*M;r[blk[N-1]]=N-1;
//	for(i=1;i<N;i++)a[i]=rand()%100;
	for(i=1;i<N;i++)a[i]=quick(1023,i,1e9)^quick(1025,i,1e9);
	for(i=1;i<N;i++)b[i]=-a[i];
	//freopen(".in","w",stdout); 
	//read(n),cout<<n<<endl;
	read(t);
	for(i=1;i<=t;i++)q[i].init();
	solve();swap(a,b);solve();
	for(i=1;i<=t;i++)
	cout<<q[i].res<<endl;
	return 0;
}

