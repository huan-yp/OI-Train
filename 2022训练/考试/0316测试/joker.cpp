#include<bits/stdc++.h>
#define INF 1000000000
#define int long long
#define LL long long
#define pii pair<int,int>
using namespace std;
template<typename _type>
inline void read(_type &x){
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
template<typename _type>void cmin(_type &a,_type b){a=min(a,b);}
template<typename _type>void cmax(_type &a,_type b){a=max(a,b);}
const int N=120005,T=1500; 
int i,j,k,n,s,t,m,A,B;
int a[N],f[N],g[N],ef[N],eg[N],block[N],lb[N],rb[N];
int Tail[T+5],Head[T+5],Q[T+5][T+5];
void ask(){
	LL opt=-INF,rk=0;
	for(j=1;j<=block[n];j++){
		LL l=1,r=Tail[j]-2,ans=Tail[j]-1;
		while(r>=l){
			int mid=(l+r)/2,pos1=Q[j][mid],pos2=Q[j][mid+1];
			if((f[pos1]-f[pos2])*A>=B*(g[pos2]-g[pos1]))
			r=mid-1,ans=mid;
			else 
			l=mid+1;
		}
		int res=Q[j][ans];
		if(1ll*(f[res]+ef[j])*A+1ll*(g[res]+eg[j])*B>opt)
		rk=res,opt=1ll*(f[res]+ef[j])*A+1ll*(g[res]+eg[j])*B;
	}
	printf("%lld\n",rk);
}
int check(int x,int y,int z){
	return !(1ll*(f[y]-f[z])*(g[z]-g[x])>1ll*(f[x]-f[z])*(g[z]-g[y]));
}
signed main()
{
 	freopen("joker.in","r",stdin);
	freopen("joker.out","w",stdout);
	read(n),read(m);
	
	for(i=1;i<=n;i++){
		block[i]=(i-1)/T+1;
		read(a[i]);f[i]=f[i-1],g[i]=g[i-1];
		if(a[i]>0)A+=a[i],g[i]+=a[i];
		else B+=-a[i],f[i]+=a[i];
	}
	for(i=1;i<=n;i++)lb[i]=(i-1)*T+1,rb[i]=i*T;
	rb[block[n]]=n;
	for(i=1;i<=block[n];i++){
		int pos=i;
		int &tail=Tail[pos],&head=Head[pos];auto &q=Q[pos];
		tail=head=1;q[tail++]=lb[pos];
		for(j=lb[pos]+1;j<=rb[pos];j++){
			if(g[j]==g[j-1])continue;
			while(tail-head>=2&&check(q[tail-2],q[tail-1],j))tail--;
			q[tail++]=j;
		}
	}	
	ask();
	for(i=1;i<=m;i++){
		int pos,val,df=0,dg=0;read(pos),read(val);
		if(val<0)df+=val,B-=val;else dg+=val,A+=val;
		if(a[pos]<0)df-=a[pos],B+=a[pos];else dg-=a[pos],A-=a[pos];
		for(j=pos;j<=rb[block[pos]];j++)
		f[j]+=df,g[j]+=dg;
		a[pos]=val;pos=block[pos];
		for(j=pos+1;j<=block[n];j++){
			ef[j]+=df,eg[j]+=dg;
		}	
		int &tail=Tail[pos],&head=Head[pos];auto &q=Q[pos];
		tail=head=1;q[tail++]=lb[pos];
		for(j=lb[pos]+1;j<=rb[pos];j++){
			if(g[j]==g[j-1])continue;
			while(tail-head>=2&&check(q[tail-2],q[tail-1],j))tail--;
			q[tail++]=j;
		}
		ask();
	}
	return 0;
}
