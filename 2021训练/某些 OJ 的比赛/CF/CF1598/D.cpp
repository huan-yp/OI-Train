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
int i,j,k,n,s,t,m;
const int N=1e6+10;
int cnt1[N],cnt2[N];
vector<int> e[N];
int C3(int x)
{
	if(x<3)return 0;
	return x*(x-1)*(x-2)/6;
}
int C2(int x)
{
	if(x<2)return 0;
	return x*(x-1)/2;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	{
		read(n);
		for(i=1;i<=n;i++)
		e[i].clear(),cnt1[i]=cnt2[i]=0;
		for(i=1;i<=n;i++)
		{
			int x,y;
			read(x),read(y);
			cnt1[x]++,cnt2[y]++;
			e[x].push_back(y);
		}
		int ans=C3(n);
//		for(i=1;i<=n;i++)
//		{
//			ans-=C3(cnt1[i]),ans-=C3(cnt2[i]);
//			ans-=C2(cnt1[i])*(n-cnt1[i]),ans-=C2(cnt2[i])*(n-cnt2[i]);
//		}
		for(i=1;i<=n;i++)
		{
			for(int v:e[i])
			{
				ans-=(cnt1[i]-1)*(cnt2[v]-1);
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}

