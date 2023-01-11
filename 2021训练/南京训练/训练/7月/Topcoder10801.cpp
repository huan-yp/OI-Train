#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define next nxt
#define INF 1000000000
#define LL long long
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
const int N=9e5+10;
const int p[]={1,7,49,343,2401,16807,117649,823543};
int i,j,k,n,s,t,m,ans;
int cnt[N],next[N];
bitset<N> pd;
vector<int> v[55];
int nt(int x)
{
	if(next[x])return next[x];
	next[x]=x;
	for(int i=1;i<=k;i++)
	{
		if(x/p[i-1]%7==ans-1)continue;
		next[x]+=p[i-1];
	}
	return next[x];
}
class AmoebaCode{
	public:
	int find(string code, int K)
	{
		k=K;n=code.length();
		for(ans=k;ans>=1;ans--)
		{
			memset(next,0,sizeof(next));
			int opt=0;
			for(i=1;i<=k;i++)
			opt+=(ans-1)*p[i-1];
			v[0].push_back(opt);
			for(i=0;i<n;i++)
			{
				for(int mask:v[i])
				for(j=1;j<=k;j++)
				{
					if(mask/p[j-1]%7!=ans-1)continue;
					if(code[i]!='0'&&code[i]-'0'!=j)continue;
					int val=nt(mask);
					pd[val/p[j]*p[j]+val%p[j-1]]=1;
				}
				for(int mask=0;mask<=opt;mask++)
				if(pd[mask])
				v[i+1].push_back(mask);
				
				v[i].clear(),pd.reset();
			}
			if(v[n].size())
			return ans;
		}
	}
};
//signed main()
//{
//	//freopen(".in","r",stdin);
//	//freopen(".out","w",stdout);
//	//freopen(".ans","w",sdtout);
//	AmoebaCode solve;
//	cout<<solve.find(
//"10012031001",
//3);
//	return 0;
//}


