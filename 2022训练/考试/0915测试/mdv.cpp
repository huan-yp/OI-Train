#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
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
const int N=2e6+10;
int i,j,k,n,s,t,m,tp1,tp2;
int cnt[N],a[N];
signed main()
{
 	freopen("mdv.in","r",stdin);
	freopen("mdv.out","w",stdout);
//	freopen(".in","w",stdout);
	read(n),read(m);
	for(i=1;i<=n;i++)read(a[i]),cnt[a[i]]++;
	for(i=1;i<=m;i++)if(cnt[i]==0){puts("0"),exit(0);}
	int l=1,r=n;LL ans=0;
	while(cnt[a[r]]>1)cnt[a[r--]]--;
	for(i=1;i<=n;i++){
		ans+=n-r+1;
		cnt[a[i]]--;
		while(cnt[a[i]]==0&&r<=n)cnt[a[++r]]++;
	}
	cout<<ans<<endl;
	return 0;
}


