#include<bits/stdc++.h>
#define int long long
using namespace std;
template<typename T>
void read(T &x){
	x=0;char ch=getchar();int f=1;
	while((ch<'0'||ch>'9')&&ch!=45)ch=getchar();
	if(ch==45)f=-1,ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
template<typename T1,typename T2>void cmax(T1 &x,const T2 &y){if(y>x)x=y;}
template<typename T1,typename T2>void cmin(T1 &x,const T2 &y){if(y<x)x=y;}
const int N=5e5+10;
int i,j,k,m,n,s,t,c,r,f,flag,now;
int a[N],b[N],rk[N],val[N],ans[N],pd[N];
struct seg{
	int l,r,v,ans;
	friend bool operator <(const seg &a,const seg &b){
		return a.l<b.l;
	}
};
set<seg> st;
bool cmp(int x,int y){return abs(a[x])<abs(a[y]);}
void erase(seg sg){now-=sg.ans;st.erase(sg);}
auto insert(seg sg){now+=sg.ans;return st.insert(sg).first;}
void print(){
	for(auto sg:st){
		if(sg.v==0){
			if(sg.l==1){
				ans[sg.r]=val[sg.r+1]==1?-1:1;
				for(i=sg.r-1;i>=1;i--)ans[i]=ans[i+1]==1?-1:1;
			}
			else{
				ans[sg.l]=val[sg.l-1]==1?-1:1;
				for(i=sg.l+1;i<=sg.r;i++)ans[i]=ans[i-1]==1?-1:1;
			}
		}
		else{
			for(ans[sg.r]=a[sg.r],i=sg.l;i<sg.r;i++)ans[i]=0;
		}
	}
	for(i=1;i<=n;i++)if(ans[i])ans[++k]=ans[i];
	for(i=1;i<k;i++)if(!((ans[i]<0)^(ans[i+1]<0)))ans[++i]=0;
	for(s=k,k=0,i=1;i<=s;i++)if(ans[i])ans[++k]=ans[i];printf("%lld\n",k);
	for(i=1;i<=k;i++)printf("%lld ",ans[i]);puts("");
}
auto merge(seg a,seg b){
	erase(a);erase(b);
	seg in={a.l,b.r,0,0};int len=in.r-in.l+1;
	auto it=st.insert(in).first;
	if(it==st.begin()||next(it)==st.end())return it;
	int o=(next(it)->v<0)^(prev(it)->v<0);
	if(o^(len&1))return it;
	else{
		auto w=*it;w.ans=1;
		st.erase(it);
		return insert(w);
	}
}
int solve(){
	int all=0,lst=0;
	for(i=1;i<=n;i++){
		if(a[i]==0)all++;
		else{
			if(val[i]==lst)pd[i]=1,all++;
			else lst=val[i];
		}
	}
	if(all*r>f)return 0;
	printf("%lld\n",n-all);
	for(i=1;i<=n;i++)if(!pd[i]&&a[i])printf("%lld ",a[i]);
	return 1;
}
signed main(){
//	freopen("wave.in","r",stdin);
//	freopen("wave.out","w",stdout);
	read(n),read(c),read(r),read(f);
	for(i=1;i<=n;i++)read(a[i]),rk[i]=i;
	sort(rk+1,rk+n+1,cmp);
	for(i=1;i<=n;i++)val[i]=a[i]<0?-1:1,flag|=a[i]==0;
	for(val[n+1]=0,s=1,i=1;i<=n;i++){
		if(val[i]!=val[i+1]){
			st.insert(seg{s,i,val[i],i-s}),now+=i-s;
			s=i+1;
		}
	}
	if(solve())return 0;
	for(i=1;i<=n;i++){
		int x=rk[i];auto it=prev(st.lower_bound(seg{x+1,0,0,0}));
		if(it->l==it->r){
			erase(*it);it=insert({x,x,0,0});
			if(x!=1&&prev(it)->v==0)it=merge(*prev(it),*it);
			if(x!=n&&next(it)->v==0)it=merge(*it,*next(it));
		}
		else{
			auto w=*it;
			erase(*it);it=insert({x,x,0,0});
			if(w.r!=x)insert({x+1,w.r,val[x],w.r-x-1});
			if(w.l!=x)insert({w.l,x-1,val[x],x-w.l-1});
			it=merge(*it,*it);
			if(w.l==x&&x!=1&&prev(it)->v==0)merge(*prev(it),*it);
			if(w.r==x&&x!=n&&next(it)->v==0)merge(*it,*next(it));
		}
		if((a[rk[i+1]]!=0||i==n)&&c*(abs(a[x])+1)+now*r<=f){
			print();break;
		}
	}
	return 0;
}
