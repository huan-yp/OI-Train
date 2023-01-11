#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
using namespace std;
inline void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
void cmin(int &a,int b){a=min(a,b);}
void cmax(int &a,int b){a=max(a,b);}
const int N=2e5+10; 
int i,j,k,n,s,t,m,len;
int a[N],b[N],dp[N];
vector<pii> e[N];
multiset<int> st;
signed main()
{
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	read(n);
	for(i=1;i<=n;i++)read(a[i]);
	read(m);
	for(i=1;i<=m;i++)read(b[i]),st.insert(b[i]);
	sort(b+1,b+m+1);
	m=unique(b+1,b+m+1)-b-1;
	for(i=1;i<=n;i++)dp[i]=INF*2;
	for(i=1;i<=n;i++){
		if(a[i]!=-1){
			int l=1,r=n,res=0;
			while(r>=l){
				int mid=l+r>>1;
				if(a[i]>dp[mid])
				l=mid+1,res=mid;
				else
				r=mid-1;
			}
			if(dp[res+1]>a[i])dp[res+1]=a[i],e[res+1].push_back(make_pair(i,a[i]));
		}
		else{
			int pos=n+1;
			for(j=m;j>=1;j--){
				while(b[j]<=dp[pos-1])pos--;
				while(b[j-1]>dp[pos-1])j--;
				if(dp[pos]>b[j])dp[pos]=b[j],e[pos].push_back(make_pair(i,b[j]));
			}
		}
	}
	for(i=n;i>=1;i--)if(dp[i]<=INF)break;
	for(int now=n+1;i>=1;i--){
		for(auto it=e[i].rbegin();it!=e[i].rend();it++){
			if(it->first>=now)continue;
			now=it->first;int val=it->second;
			if(a[now]==-1)a[now]=val,st.erase(st.find(val));
			break;
		}
	}
	for(i=1;i<=n;i++){
		if(a[i]==-1)
		a[i]=*st.begin(),st.erase(st.begin());
	}
	for(i=1;i<=n;i++)
	printf("%d ",a[i]);
	return 0;
}

