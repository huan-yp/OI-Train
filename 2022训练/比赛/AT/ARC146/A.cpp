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
const int N=1e6+10;
int i,j,k,n,s,t,m,tp1,tp2;
int a[N];
bool cmp(string a,string b){
	return a+b>b+a;
}
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	read(n);
	for(i=1;i<=n;i++)read(a[i]);
	sort(a+1,a+n+1);
	string s[4];
	for(i=1;i<=3;i++)
	s[i]=to_string(a[n-i+1]);
	sort(s+1,s+4,cmp);
	for(i=1;i<=3;i++)
	cout<<s[i];
	puts("");
	return 0;
}


