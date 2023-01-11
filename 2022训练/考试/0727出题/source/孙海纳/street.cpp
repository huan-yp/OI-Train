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
int n;
vector<int> v[100010];
bool cn[100010];
char str[3];
ll fnd[100010],lst[100010],cnt[100010];
inline bool cmp(PLL x,PLL y)
{
	return x.Fst*y.Snd<y.Fst*x.Snd;
}
void dfslst(int x)
{
	if (v[x].empty())
	{
		cnt[x]=1,lst[x]=2;
		return;
	}
	cnt[x]=0,lst[x]=2;
	for (int i=0;i<v[x].size();i++)
	{
		int xi=v[x][i];
		dfslst(xi),cnt[x]+=cnt[xi];
		if (!cn[x]) lst[x]+=lst[xi];
	}
}
void dfsfnd(int x)
{
	fnd[x]=0;
	if (v[x].empty()) return;
	vector<PLL> vt;
	for (int i=0;i<v[x].size();i++)
	{
		int xi=v[x][i];
		dfsfnd(xi),fnd[x]+=fnd[xi];
		vt.push_back(MP(lst[xi],cnt[xi])); 
	}
	sort(vt.begin(),vt.end(),cmp);
	//cout <<x<<" ##\n";
	ll pre=1;
	for (int i=0;i<vt.size();i++)
	{
		int lt=vt[i].Fst,ct=vt[i].Snd;
		fnd[x]+=pre*ct,pre+=lt;
	}
	//cout <<x+1<<" "<<lst[x]<<" "<<fnd[x]<<" #############\n";
}
int main()
{
	freopen("street.in","r",stdin);
	freopen("street.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		int x;
		scanf("%d%s",&x,str),x--;
		v[x].push_back(i),cn[i]=(str[0]=='Y' ? 1 : 0);
	}
	if (n==1)
	{
		printf("0.0000000");
		return 0;
	}
	dfslst(0),dfsfnd(0);
	printf("%.7lf",(1.0*fnd[0])/cnt[0]);
	return 0;
}
