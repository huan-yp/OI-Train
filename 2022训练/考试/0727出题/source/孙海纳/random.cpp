#include <bits/stdc++.h>
#define ll long long
#define PII pair<int, int>
#define PIL pair<int, ll>
#define PLI pair<ll, int>
#define PLL pair<ll, ll>
#define PDD pair<double, double>
#define STR string
#define MP make_pair
#define Fst first
#define Snd second
using namespace std;
int n,m,tc=0;
int pr[550],cm[550],ci[550],fac[100010][550];
vector<int> vr;
inline void GETVP(ll x)
{
	for (int i=2;i*i<=x;i++)
	{
		if (x%i) continue;
		int t=0;
		while (x%i==0) x/=i,t++;
		pr[tc]=i,cm[tc]=t,tc++;
	}
	if (x!=1) pr[tc]=x,cm[tc]=1,tc++;
}
inline void BUILD()
{
	for (int i=1;i<=100005;i++)
	{
		int x=i;
		//cout <<i<<" ##################\n";
		for (int j=0;j<tc;j++)
		{
			//cout <<x<<" "<<pr[j]<<" ##\n";
			fac[i][j]=fac[i-1][j];
			while (x%pr[j]==0) x/=pr[j],fac[i][j]++;
		}
	}
}
int main()
{
	freopen("random.in","r",stdin);
	freopen("random.out","w",stdout);
	scanf("%d%d",&n,&m);
	//cout <<(double)clock()/CLOCKS_PER_SEC<<" ##\n";
	GETVP(m),BUILD();
	for (int i=0;i<n;i++)
	{
		fill(ci,ci+tc,0);
		bool fl=1;
		for (int j=0;j<tc;j++)
		{
			ci[j]=fac[n-1][j]-fac[i][j]-fac[n-1-i][j];
			if (ci[j]<cm[j])
			{
				fl=0;
				break;
			}
		}
		if (fl) vr.push_back(i);
	}
	printf("%d\n",(int)vr.size());
	for (int i=0;i<vr.size();i++) printf("%d ",vr[i]+1);
	//cout <<(double)clock()/CLOCKS_PER_SEC<<" ##\n";
	return 0;
}
