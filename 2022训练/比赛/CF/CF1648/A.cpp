#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
#define pii pair<int,int>
using namespace std;
template<typename _type>
inline void read(_type &x)
{
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
template<typename _type>
void cmin(_type &a,_type b){a=min(a,b);}
template<typename _type>
void cmax(_type &a,_type b){a=max(a,b);}
const int N=2e5+10;
int i,j,k,n,s,t,m;
int sum[N],cnt[N];
map<int,int> mp1[N],mp2[N];
signed main()
{
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	read(n),read(m);
	int a[n+1][m+1];
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++){
		read(a[i][j]);
		mp1[a[i][j]][i]++;
		mp2[a[i][j]][j]++;
	}
	int ans=0;
	for(i=1;i<=1e5;i++){
		int sum=0,cnt=0;
		for(auto tmp:mp1[i]){
			int val=tmp.second,pos=tmp.first;
			ans+=val*pos*cnt-sum*val,cnt+=val,sum+=val*pos;
		}
		sum=0,cnt=0;
		for(auto tmp:mp2[i]){
			int val=tmp.second,pos=tmp.first;
			ans+=val*pos*cnt-sum*val,cnt+=val,sum+=val*pos;
		}
	}
	cout<<ans<<endl;
	return 0;
}

