#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
#define low(x) ((x)&(-(x)))
using namespace std;
template<typename _type>
inline void read(_type &x){
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
template<typename _type1,typename _type2>void cmin(_type1 &a,const _type2 b){if(a>b)a=b;}
template<typename _type1,typename _type2>void cmax(_type1 &a,const _type2 b){if(a<b)a=b;}
const int N=30,M=1.5e6;
int i,j,k,n,s,t,m,tp1,tp2,res=1.1e7,m1r,m2r;
int a[N],rk[N],ans[N];
int sum[1<<13];
struct S{
	int a,b,c,m1,m2;
	S(){}
	S(int aa,int bb,int cc,int m,int mm):a(aa),b(bb),c(cc),m1(m),m2(mm){}
	S(vector<int> nums,int m,int mm){
		a=nums[0],b=nums[1],c=nums[2];
		m1=m,m2=mm;
	}
	friend bool operator <(const S &y,const S &x){
		if(y.c-y.a!=x.c-x.a)return y.c-y.a<x.c-x.a;
		if(y.a!=x.a)return y.a<x.a;
		return y.b<x.b;
	}
	bool ok(){
		return a<=b&&b<=c;
	}
	
}b[M];
set<S> st;
bool cmp(int x,int y){
	return a[x]<a[y];
}
signed main()
{
 	freopen("treasure.in","r",stdin);
	freopen("treasure.out","w",stdout);
//	freopen(".in","w",stdout);
	read(n);
	for(i=1;i<=n;i++)read(a[i]),rk[i]=i;
//	sort(rk+1,rk+n+1);sort(a+1,a+n+1);
	int l=n/2,r=n-l;
	for(m=1;m<1<<l;m++)
	sum[m]=sum[m-low(m)]+a[int(log2(low(m)))+1];
	for(int m1=0;m1<1<<l;m1++)
	for(int m2=m1;;m2=(m2-1)&m1){
		S tp(vector<int>{sum[m1^m2],sum[m2],sum[(1<<l)-1]-sum[m1]},m1,m2);
		if(tp.ok())st.insert(tp);
		if(m2==0)break;
	}
	for(auto x:st)b[++t]=x;
	sort(b+1,b+t+1);
	for(m=1;m<1<<r;m++)
	sum[m]=sum[m-low(m)]+a[int(log2(low(m)))+1+l];
	
	for(int m1=0;m1<1<<r;m1++)
	for(int m2=m1;;m2=(m2-1)&m1){
		S now(vector<int>{sum[m1^m2],sum[m2],sum[(1<<r)-1]-sum[m1]},m1,m2);
		if(now.ok()){
			i=lower_bound(b+1,b+t+1,S(0,0,now.c-now.a-res,0,0))-b;
			for(;i<=t&&b[i].c-b[i].a<=res+now.c-now.a;i++){
				int x=now.a+b[i].c,y=now.b+b[i].b,z=now.c+b[i].a;
				int tmp=max(x,max(y,z))-min(x,min(y,z));
				if(tmp<=res){
					res=tmp;
					m1r=(now.m1<<l)|(((1<<l)-1)^(b[i].m1^b[i].m2));//c²¹¼¯ 
					m2r=(now.m2<<l)|b[i].m2;//b¼¯ºÏ 
				}
			}
		}
		if(m2==0)break;
	}
	for(i=1;i<=n;i++){
		int num=1<<i-1;
		ans[i]=bool(num&m1r)+bool(num&m2r);
	}	
	for(i=1;i<=n;i++)
	cout<<ans[i]+1<<' ';
	puts("");
//	cout<<res<<endl;
	return 0;
}
