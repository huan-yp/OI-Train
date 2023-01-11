#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;
template<typename _type>
inline int read(_type &x){
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch<'0'||ch>'9'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*=f;
}
template<typename _type1,typename _type2>void cmin(_type1 &a,const _type2 &b){if(a>b)a=b;}
template<typename _type1,typename _type2>void cmax(_type1 &a,const _type2 &b){if(a<b)a=b;}
const int N=5e5+10;
int i,j,n,s,t,m,now;
int a[N],L[N],lo[N],ans[N],k[N],ll[N],rr[N];
int cnt[N],mip[N],mxp[N],ti[N],tx[N],tc[N];
bool ok[N];
int va[N],vL[N],tp[N];
struct ST{
	int st[19][N];
	long long ask(int l,int r){
		if(l>r||l<=0||r<=0||l>n||r>n)return 2147483647;int len=lo[r-l+1];
		return min(st[len][l],st[len][r-(1<<len)+1]);
	}
	void init(int a[]){
		for(int i=1;i<=n;i++)st[0][i]=a[i];
		for(int i=1;i<=18;i++)
		for(int j=1;j+(1<<i)-1<=n;j++)
		st[i][j]=min(st[i-1][j],st[i-1][j+(1<<i-1)]);
	}
	
}st_a,st_L;
struct qy{
	int x,rk;
	short op;
	friend bool operator <(const qy &a,const qy &b){
		return a.x<b.x;
	}
}q[N<<1],tq[N<<1];
namespace get_L{
	int top;
	int l[N],r[N],st[N];
	void solve(){
		for(int i=1;i<=n;i++){
			while(top&&a[st[top]]>=a[i])top--;
			l[i]=st[top];st[++top]=i;
		}
		top=0;
		for(int i=n;i>=1;i--){
			while(top&&a[st[top]]>a[i])top--;
			r[i]=st[top];st[++top]=i;
		}
		for(int i=1;i<=n;i++)
		L[i]=a[i]+max(a[l[i]],a[r[i]]);
	}
}
void clear(int i){tc[i]=cnt[i],tx[i]=mxp[i],ti[i]=mip[i];}
void cpy(int i){cnt[i]=tc[i],mxp[i]=tx[i],mip[i]=ti[i];}
void solve(int l,int r,int la,int ra,int lL,int rL,int lq,int rq){
	if(lq>rq)return ;
	if(l==r){
		for(i=lq;i<=rq;i++)ans[q[i].rk]=l;
		return ;
	}
	int mid=((long long)(l)+r)/2;
	int c=0,La=la,Ra=ra;
	auto pa=va+la,pL=vL+lL;
	int LL=lL,RL=rL,Lq=lq,Rq=rq;
	for(i=la;i<=ra;i++)if(a[va[i]]<=mid/2)tp[La++]=va[i];else tp[Ra--]=va[i];
	reverse(tp+La,tp+ra+1);memcpy(va+la,tp+la,sizeof(int)*(ra-la+1));
	for(i=lL;i<=rL;i++)if(L[vL[i]]<=mid)tp[LL++]=vL[i];else tp[RL--]=vL[i];
	reverse(tp+LL,tp+rL+1);memcpy(vL+lL,tp+lL,sizeof(int)*(rL-lL+1));
	for(i=lq;i<=rq;i++){
		while(*pa<=q[i].x&&pa!=va+Ra+1)pa++;
		while(*pL<=q[i].x&&pL!=vL+RL+1)c++,pL++;
		if(q[i].op==1){
			tc[q[i].rk]+=c;
			if(*(pa-1)>tx[q[i].rk]&&pa!=va+la)tx[q[i].rk]=*(pa-1);
		}
		else{
			tc[q[i].rk]-=c;
			if(*pa<ti[q[i].rk]&&pa!=va+Ra+1)ti[q[i].rk]=*pa;
		}
	}
	for(i=lq;i<=rq;i++){
		if(q[i].op==-1){
			int rk=q[i].rk,l=ti[rk]-1,r=tx[rk]+1,res=0;
			if(tc[rk]>=k[rk]-1){
				res=tc[rk]-(st_L.ask(ll[rk],l)<=mid)-(st_L.ask(r,rr[rk])<=mid);
				res=l>n?0:res+((min(st_a.ask(ll[rk],l),st_a.ask(r,rr[rk]))+max(::a[l+1],::a[r-1]))<=mid);
			}
			if(res>=k[rk])ok[rk]=1,tq[Lq++]=q[i],clear(rk);
			else cpy(rk),tq[Rq--]=q[i];
		}
		else{
			if(ok[q[i].rk])tq[Lq++]=q[i],ok[q[i].rk]=0;
			else tq[Rq--]=q[i];
		}
	}
	reverse(tq+Lq,tq+rq+1);memcpy(q+lq,tq+lq,sizeof(qy)*(rq-lq+1));
	solve(l,mid,la,Ra,lL,RL,lq,Rq);solve(mid+1,r,La,ra,LL,rL,Lq,rq);
}
signed main()
{
//	freopen("a.in","r",stdin);
//	freopen("1.out","w",stdout);
	read(n),read(m);
	for(lo[1]=0,i=2;i<N;i++)lo[i]=lo[i>>1]+1;
	for(i=1;i<=n;i++)read(a[i]);
	get_L::solve();
	st_a.init(a),st_L.init(L);
	int mxv=0;
	for(i=1;i<=n;i++)cmax(mxv,a[i]*2);
	for(i=1;i<=n;i++)va[i]=i,vL[i]=i;
	for(i=1;i<=m;i++){
		int l,r;ti[i]=mip[i]=INF,mxp[i]=0,ans[i]=0;
		ll[i]=read(l),rr[i]=read(r),read(k[i]);
		if(k[i]==1){
			ans[i]=st_a.ask(l,r)*2;
			continue;
		}
		q[i*2-1]=(qy{l-1,i,-1});
		q[i*2]=(qy{r,i,1});
	}
	sort(q+1,q+2*m+1);
	solve(0,mxv,1,n,1,n,1,2*m);
	for(i=1;i<=m;i++)printf("%d\n",ans[i]);
	return 0;
}


