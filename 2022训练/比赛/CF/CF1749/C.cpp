#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
using namespace std;
template<typename T>
inline int read(T &x){
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch<'0'||ch>'9'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*=f;
}
template<typename T1,typename T2>void cmin(T1 &a,const T2 &b){if(a>b)a=b;}
template<typename T1,typename T2>void cmax(T1 &a,const T2 &b){if(a<b)a=b;}
const int N=105;
int n,m;
int a[N];
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	int t,i,j,k;
	read(t);
	while(t--){
		read(n);
		int cnt[N];
		for(i=1;i<=n;i++)read(a[i]);
		memset(cnt,0,sizeof(cnt));
		for(i=1;i<=n;i++)cnt[a[i]]++;
		for(i=1;i<=n;i++)cnt[i]+=cnt[i-1];
		sort(a+1,a+n+1);
		for(k=n;k>=0;k--){
			int sum[N];
			memcpy(sum,cnt,sizeof(sum));
			for(i=k;i>=1;i--){
				if(sum[i]<=0)break;
				int pos=lower_bound(sum+1,sum+n+1,sum[i])-sum;
				for(j=pos;j<=n;j++)sum[j]--;
				for(j=1;j<=n;j++)if(sum[j])sum[j]--;
			}
			if(i==0)break;
		}	
		cout<<k<<endl;
	}
	return 0;
}


