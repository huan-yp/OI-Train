#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
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
void cmin(int &a,int b){a=min(a,b);}
void cmax(int &a,int b){a=max(a,b);}
const int N=1e6+10;
int i,j,k,n,s,t,m;
map<int,int> cnt;
int a[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	int T;
	read(T);
	while(T--)
	{
		read(n);
		cnt.clear();
		int sum=0;
		for(i=1;i<=n;i++)
		{
			read(a[i]);
			sum+=a[i];
			cnt[a[i]]++;
		}
		if(sum*2%n)
		{
			printf("0\n");
			continue;
		}
		int ans=0,ave=sum*2/n;
		for(i=1;i<=n;i++)
		{
			cnt[a[i]]--;
			ans+=cnt[ave-a[i]];
			cnt[a[i]]++;
		}
		cout<<ans/2<<endl;
	}

	return 0;
}

