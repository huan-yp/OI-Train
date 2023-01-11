#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
template<typename T>
void read(T &x){
	x=0;char ch=getchar();int f=1;
	while((ch<'0'||ch>'9')&&ch!=45)ch=getchar();
	if(ch==45)f=-1,ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
template<typename T1,typename T2>void cmax(T1 &x,const T2 &y){if(y>x)x=y;}
template<typename T1,typename T2>void cmin(T1 &x,const T2 &y){if(y<x)x=y;}
const int N=305;
int i,j,k,m,n,s,t,top;
int dp[N][N],Q[N][N],ans[N][N][N],sum[N][N],st[N][2];
struct query{
	signed l,r;int sum;
	bool operator <(const query &b){
		return sum<b.sum;
	}
};
double slope(int* p1,int* p2){
	return 1.0*(*(p2+1)-*(p1+1))/(*p2-*p1);
}
double slope(int* p1,pii p2){
	return 1.0*(p2.second-*(p1+1))/(p2.first-*p1);
}
int get_ans(int *p1,vector<query>::iterator p2){
	return *(p1+1)-*p1*p2->sum;
}
vector<pii> e[N];
vector<query> q[N];
signed main(){
	freopen("array.in","r",stdin);
	freopen("array.out","w",stdout);
//	read(n),read(m),cout<<n<<' '<<m<<endl;
	read(n);
	for(i=1;i<=n;i++)
	for(j=i;j<=n;j++)
	read(Q[i][j]),sum[i][j]=sum[i][j-1]+Q[i][j],dp[i][j]=-2e18;
	for(i=1;i<=n;i++){
		read(k);
		for(j=1;j<=k;j++){
			int v,c;read(v),read(c);
			e[i].push_back(make_pair(v,c));
		}
	}
	for(i=1;i<=n;i++)for(k=i;k<=n;k++){
		int sm=0;
		for(j=i;j>=1;j--){
			sm+=sum[j][k]-sum[j][i-1];
			q[i].push_back(query{j,k,sm});
		}
	}
	
	for(i=1;i<=n;i++){
		sort(q[i].begin(),q[i].end());
		sort(e[i].begin(),e[i].end());
		top=0;
		for(auto [k,b]:e[i]){
			while(top&&st[top][1]>=b)top--;
			st[++top][0]=k,st[top][1]=b;
			while(top&&st[top][0]==st[top-1][0])top--;
		}
		for(e[i].clear(),j=1;j<=top;j++)
		e[i].push_back(make_pair(-st[j][0],-st[j][1]));
		for(top=0,j=0;j<(int)e[i].size();j++){
			while(top>=2&&slope(st[top],st[top-1])>slope(st[top],e[i][j]))top--;
			tie(st[top+1][0],st[top+1][1])=e[i][j];top++;
		}
		auto now=q[i].begin();
		for(j=1;j<top;j++){
			while(now!=q[i].end()&&get_ans(st[j],now)>get_ans(st[j+1],now)){
				ans[i][now->l][now->r]=get_ans(st[j],now);
				now++;
			}
		}
		while(now!=q[i].end())ans[i][now->l][now->r]=get_ans(st[top],now),now++;
	}
	for(int len=1;len<=n;len++)
	for(int l=1,r=len;r<=n;l++,r++)
	for(k=l;k<=r;k++){
	//	printf("%lld %lld %lld %lld\n",l,r,k,ans[k][l][r]);
		cmax(dp[l][r],dp[l][k-1]+dp[k+1][r]+ans[k][l][r]);
	}
	cout<<dp[1][n]<<endl;
	return 0;
}

