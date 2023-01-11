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
const int N=1e6+10;
int i,j,k,n,s,t,m,tp1,tp2;
int a[N],b[N];
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	read(t);
	while(t--){
		read(n),read(m);s=0;
		for(i=1;i<=m;i++)read(a[i]);
		sort(a+1,a+m+1);
		for(i=2;i<=m;i++){
			if(a[i]>a[i-1]+1)
			b[++s]=a[i]-a[i-1]-1;
		}
		if(n-a[m]+a[1]-1)b[++s]=n-a[m]+a[1]-1;
		sort(b+1,b+s+1);
		int pro=0,day=0;
		for(i=s;i>=1;i--){
			if(day*2>=b[i])break;
			if(b[i]-day*2==1){
				pro++,day++;
				continue;
			}
			pro+=b[i]-day*2-1;
			day+=2;
		}
		cout<<n-pro<<endl;
	}
	return 0;
}


