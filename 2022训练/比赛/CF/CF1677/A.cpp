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
const int N=5005;
int i,j,k,n,s,t,m;
int a[N],sum[N][N],all[N];
signed main()
{
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".in","w",stdout);
	read(t);
	while(t--){
		int ans=0;
		memset(all,0,sizeof(all));
		read(n);memset(sum,0,sizeof(int)*N*(n+5));
		for(i=1;i<=n;i++)read(a[i]);
		for(i=1;i<=n;i++){
			for(j=i+2;j<n;j++){
				if(a[j]>a[i])
				{
					sum[i+1][j+1]++;
					sum[j][j+1]--;
				}
			}
		}
		for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		sum[i][j]+=sum[i-1][j];
		
//		for(i=1;i<=n;i++)
//		for(j=1;j<=n;j++)
//		sum[i][j]+=sum[i][j-1];
		
		for(i=n;i>=1;i--){
			for(j=a[i];j<=n;j++)all[j]++;
			for(j=i-1;j>=1;j--)
			ans+=sum[j][i]*all[a[j]];
		}
		cout<<ans<<endl;
	}
	return 0;
}


