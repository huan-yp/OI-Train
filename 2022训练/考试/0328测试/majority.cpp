#include<bits/stdc++.h>
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
template<typename _type>void cmin(_type &a,_type b){a=min(a,b);}
template<typename _type>void cmax(_type &a,_type b){a=max(a,b);}
const int N=3e6+10;
int i,j,k,n,s,t,m;
LL ans;
int a[N],cnt[N],cntans[N],sum[N];
vector<int> e1[N],e2[N];
void solve(int l,int r){
	if(l==r){
	//	printf("%d %d,ans:%lld\n",l,r,1ll);
		ans++;return ;
	}
	int mid=(l+r)/2,lst=0;LL tmp=0;
	solve(l,mid);
	solve(mid+1,r);
	for(i=mid;i>=l;i--){
		cnt[a[i]]++;
		if(cnt[lst]>(mid-i+1)/2){
			cntans[lst]++;
			e1[lst].push_back(2*cnt[lst]-(mid-i+1)-1);
			continue;
		}
		lst=0;
		if(cnt[a[i]]>(mid-i+1)/2){
			lst=a[i];cntans[a[i]]++;
			e1[a[i]].push_back(2*cnt[a[i]]-(mid-i+1)-1);
		}
	}
	for(i=mid;i>=l;i--)cnt[a[i]]=0;lst=0;
	for(i=mid+1;i<=r;i++){
		cnt[a[i]]++;
		if(cnt[lst]>(i-mid)/2){
			tmp-=cntans[lst];
			e2[lst].push_back(2*cnt[lst]-(i-mid)-1);
			continue;
		}
		lst=0;
		if(cnt[a[i]]>(i-mid)/2){
			lst=a[i];tmp-=cntans[a[i]];
			e2[a[i]].push_back(2*cnt[a[i]]-(i-mid)-1);
		}
	}
	for(i=l;i<=r;i++)cntans[a[i]]=cnt[a[i]]=0;
	for(j=mid+1;j<=r;j++){
		if(e2[a[j]].size()==0)continue;
		for(i=0;i<=mid-l+1;i++)sum[i]=0;
		int count=0;
		for(i=mid;i>=l;i--){
			if(a[i]==a[j])count++;
			if(count*2-(mid-i+1)>=0)sum[0]++;
			else sum[(mid-i+1)-count*2]++;
		}
		for(i=1;i<=mid-l+1;i++)sum[i]=sum[i-1]+sum[i];
		for(auto x:e2[a[j]])tmp+=sum[x];
		e2[a[j]].clear();
	}
	for(j=mid;j>=l;j--){
		if(e1[a[j]].size()==0)continue;
		for(i=0;i<=r-mid;i++)sum[i]=0;
		int count=0;
		for(i=mid+1;i<=r;i++){
			if(a[i]==a[j])count++;
			if(count*2-(i-mid)>=0)sum[0]++;
			else sum[(i-mid)-count*2]++;
		}
		for(i=1;i<=r-mid;i++)sum[i]=sum[i-1]+sum[i];
		for(auto x:e1[a[j]])tmp+=sum[x];
		e1[a[j]].clear();
	}
	ans+=tmp;
}
signed main()
{
 	freopen("majority.in","r",stdin);
	freopen("majority.out","w",stdout);
	read(n);
	for(i=1;i<=n;i++)read(a[i]);
	solve(1,n);
	cout<<ans<<endl;
	return 0;
}
