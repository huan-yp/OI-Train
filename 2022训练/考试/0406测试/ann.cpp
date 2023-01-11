#include<bits/stdc++.h>
#define LL long long
#define INF 1000000000
#define y1 y3647
#define pii pair<int,int>
using namespace std;
void read(int &x){
	char ch=getchar();x=0;int f=1;
	while((ch>'9'||ch<'0')&&ch!=45)ch=getchar();
	if(ch==45)f=-1,ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	x*=f;
}
template<typename _type>void cmax(_type &x,const _type &y){x=max(x,y);}
template<typename _type>void cmin(_type &x,const _type &y){x=min(x,y);}
const int N=1e6+10;
int i,j,k,m,n,s,t,q;
struct SegmentTree{
	int a[N<<2],val[N],b[N<<2];
	void push_up(int rt){
		a[rt]=max(a[rt<<1],a[rt<<1|1]);
		b[rt]=min(b[rt<<1],b[rt<<1|1]);
	}
	void updata(int l,int r,int rt,int x,int c){
		if(l==r){
			b[rt]=val[l]=a[rt]=c;return ;
		}
		int mid=(l+r)/2;
		if(x<=mid)updata(l,mid,rt<<1,x,c);
		else updata(mid+1,r,rt<<1|1,x,c);
		push_up(rt);
	}
	int find_left(int l,int r,int rt,int x,int c){
		if(a[rt]<c)return 0;
		if(l==r)return l;
		int mid=l+r>>1,ret=0;
		if(x>mid)ret=find_left(mid+1,r,rt<<1|1,x,c);
		if(!ret)ret=find_left(l,mid,rt<<1,x,c);
		return ret;
	}
	int find_right(int l,int r,int rt,int x,int c){
		if(a[rt]<c)return 0;
		if(l==r)return l;
		int mid=(l+r)/2,ret=0;
		if(x<=mid)ret=find_right(l,mid,rt<<1,x,c); 
		if(!ret)ret=find_right(mid+1,r,rt<<1|1,x,c);
		return ret;
	}
	int quert(int l,int r,int rt,int x,int y){
		if(x<=l&&y>=r)return b[rt];
		int mid=(l+r)/2,ret=INF;
		if(x<=mid)cmin(ret,quert(l,mid,rt<<1,x,y));
		if(y>mid)cmin(ret,quert(mid+1,r,rt<<1|1,x,y));
		return ret;
	}
}H,V;
int main(){
//	freopen("ann.in","r",stdin);
//	freopen("ann.out","w",stdout);
	read(n),read(m),read(q);
	for(i=1;i<=q;i++){
		int op,x,y,x1,y1,y2,x2;
		read(op);
		if(op==1){
			read(x);
			H.updata(1,n,1,x,i);
		}
		if(op==2){
			read(y);
			V.updata(1,m,1,y,i);
		}
		if(op==3){
			read(x1),read(y1),read(x2),read(y2),read(k);
			int lim=i-k,base=abs(x1-x2)+abs(y1-y2);
			if(x1==x2&&y1==y2&&(H.val[x1]>=lim||V.val[y1]>=lim)){
				puts("0");
				continue;
			}
			if(x1==x2&&H.val[x1]>=lim){
				printf("%d\n",base);
				continue;
			}
			if(y1==y2&&V.val[y1]>=lim){
				printf("%d\n",base);
				continue;
			}
			if((H.val[x1]>=lim&&V.val[y2]>=lim)||(V.val[y1]>=lim&&H.val[x2]>=lim)){
				printf("%d\n",base);
				continue;
			}
			if(H.val[x1]>=lim&&H.val[x2]>=lim){
				int l=x1,r=x2,res=INF;if(l>r)swap(l,r);
				if(H.quert(1,n,1,l,r)>=lim){
					printf("%d\n",base);
					continue;
				}
				l=y1,r=y2,res=INF;if(l>r)swap(l,r);
				int pos1=V.find_left(1,m,1,r,lim);
				int pos2=V.find_right(1,m,1,l,lim);
				if((pos1<=r&&pos1>=l)||(pos2<=r&&pos2>=l))res=0;
				if(pos1&&pos1<l)cmin(res,l-pos1);
				if(pos2&&pos2>r)cmin(res,pos2-r);
				if(res!=INF){
					printf("%d\n",base+res*2);
					continue;
				}
			}
			if(V.val[y1]>=lim&&V.val[y2]>=lim){
				int l=y1,r=y2,res=INF;if(l>r)swap(l,r);
				if(V.quert(1,m,1,l,r)>=lim){
					printf("%d\n",base);
					continue;
				}
				l=x1,r=x2,res=INF;if(l>r)swap(l,r);
				int pos1=H.find_left(1,n,1,r,lim);
				int pos2=H.find_right(1,n,1,l,lim);
				if((pos1<=r&&pos1>=l)||(pos2<=r&&pos2>=l))res=0;
				if(pos1&&pos1<l)cmin(res,l-pos1);
				if(pos2&&pos2>r)cmin(res,pos2-r);
				if(res!=INF){
					printf("%d\n",base+res*2);
					continue;
				}
			}
			puts("-1");
		}
	}
	return 0;
}

