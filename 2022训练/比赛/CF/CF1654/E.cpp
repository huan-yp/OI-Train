#include<bits/stdc++.h>
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
template<typename _type>void cmin(_type &a,_type b){a=min(a,b);}
template<typename _type>void cmax(_type &a,_type b){a=max(a,b);}
const int N=1e5+10;
int i,j,k,n,s,t,m,ans;
int a[N],b[N];
map<int,int> mp;
signed main()
{
 	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	read(n);ans=INF;
	for(i=1;i<=n;i++)read(a[i]);
	for(i=1;i<=n;i++){
		mp.clear();
		for(j=i-1;j>=1&&j>=i-255;j--){
			if((a[i]-a[j])%(i-j))continue;
			mp[(a[i]-a[j])/(i-j)]++;
		}
		for(auto tmp:mp)cmin(ans,n-tmp.second-1);
	}
	for(i=-405;i<=405;i++){
		b[0]=-1e18;
		for(j=1;j<=n;j++){
			b[j]=a[j]+i*(n-j);
		}
		sort(b+1,b+n+1);
		int lst=0;
		for(j=1;j<=n;j++){
			if(b[j]!=b[lst]){
				cmin(ans,n-j+lst);
				lst=j;
			}
		}
		cmin(ans,lst-1);
	}
	cout<<ans<<endl;
	return 0;
}


