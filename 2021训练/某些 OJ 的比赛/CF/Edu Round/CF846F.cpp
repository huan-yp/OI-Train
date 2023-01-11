#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
using namespace std;
inline void read(int &x)
{
	x=0;int f=1;
	char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}
	x*=f;
}
const int N=1e6+10; 
int i,j,k,n,s,t,m;
int a[N];
vector<int> b[N];
double ans;
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n);
	for(i=1;i<N;i++)
	b[i].push_back(0);
	for(i=1;i<=n;i++)
	{
		read(a[i]);
		b[a[i]].push_back(i);
	}
	for(i=1;i<N;i++)
	b[i].push_back(n+1);
	
	for(i=1;i<N;i++)
	{
		LL sum=0,all=1ll*n*n;
		if(b[i].size()==2)continue;
		for(j=1;j<b[i].size();j++)
		sum+=1ll*(b[i][j]-b[i][j-1]-1)*(b[i][j]-b[i][j-1]-1);
		
		ans+=1.0*(all-sum)/all;
	}
	printf("%0.9lf",ans);
	return 0;
}


