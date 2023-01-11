#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
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
template<typename _type1,typename _type2>void cmin(_type1 &a,const _type2 b){if(a>b)a=b;}
template<typename _type1,typename _type2>void cmax(_type1 &a,const _type2 b){if(a<b)a=b;}
const int N=200005+10;
int i,j,k,n,s,t,m,tp1,tp2,cnt;
array<int,N> p,ps;
array<int,N> erase(array<int,N> a,int x,int l,int r,int lim=0){
	auto res=a,pos=a;
	set<int> st;st.clear();
	s=0;int src=x;
	for(i=1;i<=n;i++)pos[a[i]]=i,res[i]=0;
	for(i=l;i<=l+x&&i<=r;i++)st.insert(a[i]);
	for(i=l;i<=r;){
		res[++s]=*st.begin();st.erase(res[s]);
		int pn=pos[res[s]];
		while(i<=pn&&i<=r)st.erase(a[i++]);
		if(l+x+1<=r)st.insert(a[l+ ++x]);
	}
	for(i=r-l+2-src;i<=r-l+1&&!lim;i++)res[i]=0;
	for(i=1;i<=r-l+1&&lim;i++)if(res[i]>lim)res[i]=0;
	return res;
}
int length(array <int,N>a){
	for(i=1;i<=n;i++)
	if(a[i]==0)return i-1;
}
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	read(n),read(k);
	for(i=1;i<=n;i++)read(p[i]),ps[p[i]]=i;
	auto a1=erase(p,k,1,n);
	auto tp=p;int len=0;
	for(i=1;i<=n;i++){
		if(n-ps[i]+1>k)continue;
		len=n-ps[i]+1;
		for(j=1;j<=len;j++)
		tp[j]=p[j+ps[i]-1];
		for(j=len+1;j<=n;j++)
		tp[j]=p[j-len];
		break;	
	}
	auto a2_1=erase(tp,k-len,len+1,n);
	auto a2_2=erase(tp,len,1,len,a2_1[1]);
	auto a2=a2_2;len=length(a2_1);int len2=length(a2_2);
	for(i=1;i<=len;i++)
	a2[i+len2]=a2_1[i];
	
	cmin(a1,a2);
	for(i=1;i<=n+1;i++)if(a1[i]==0||i>n){
		cnt=i-1;break;
	}
	for(i=1;i<=cnt;i++)cout<<a1[i]<<' ';
	return 0;
}
