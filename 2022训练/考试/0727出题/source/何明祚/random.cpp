#include<bits/stdc++.h>
#define ll long long
#define int long long 
#define vi vector<int>
#define pii pair<int,int>
#define pb(x) push_back(x)
#define lowbit(x) x&-x
using namespace std;
const int N=1e5+10;
vi ans;
int n,m,T,sum[N][20],prime[N],tot[20],cnt;
inline int read(){
	int s=0,f=0;
	char ch=getchar();
	while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
	while(ch<='9'&&ch>='0') s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return f?-s:s;
}
inline bool C(int n,int m,int k){
//	cout<<n<<" "<<m<<" "<<sum[n][k]-sum[m][k]-sum[n-m][k]<<endl;
	return sum[n][k]-sum[m][k]-sum[n-m][k]>=tot[k];
}
inline int ck(int i,int j){
	int res=0;
	while(i%j==0) ++res,i/=j;
	return res;
}
signed main(){
	freopen("random.in","r",stdin);
	freopen("random.out","w",stdout);
	n=read(),m=read();
	for(register ll i=2;i*i<=m;++i){
		if(m%i==0){
			prime[++cnt]=i;
			while(m%i==0) m/=i,++tot[cnt];
		}
	}
	if(m!=1) prime[++cnt]=m,tot[cnt]=1;
//	for(register int i=1;i<=cnt;++i) cout<<prime[i]<<" "<<tot[i]<<endl;
	for(register int i=1;i<=n;++i){
		for(register int j=1;j<=cnt;++j){
			sum[i][j]=sum[i-1][j]+ck(i,prime[j]);
		}
	}
	for(register int i=1;i<=n;++i){
		bool flag=1;
		for(register int j=1;j<=cnt;++j) flag&=C(n-1,i-1,j);
		if(flag) ans.pb(i);
	}
	printf("%d\n",ans.size());
	for(register int i=0;i<ans.size();++i) printf("%d ",ans[i]);
	return 0;
}
