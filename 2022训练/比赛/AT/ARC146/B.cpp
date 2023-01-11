#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
#define int long long
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
const int N=2e5+10;
int i,j,k,n,s,t,m,tp1,tp2;
int a[N],b[N];
int get(int val,int x){
	int v=val|x;
	for(int i=30;i>=0;i--){
		if(1<<i&x)continue;
		if((1<<i&v)&&(v-(1<<i))>=val)v-=1<<i;
	}
	return v;
}
int check(int x){
	long long sum=0;
	for(int i=1;i<=n;i++){
		if(a[i]<=x)b[i]=x-a[i];
		else b[i]=get(a[i],x)-a[i];
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=k;i++)sum+=b[i];
	return sum<=m;
}
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	read(n),read(m),read(k);
	for(i=1;i<=n;i++)
	read(a[i]);
	int mask=0;
	for(i=30;i>=0;i--){
		if(check(mask^(1<<i)))	
		mask^=1<<i;
	}
	cout<<mask<<endl;
	return 0;
}


