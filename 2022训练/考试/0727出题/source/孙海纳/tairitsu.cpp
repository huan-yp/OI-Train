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
int n,m;
map<string,int> mp; 
string s[200010];
char str[200010];
int tc=0;
vector<PII> v[400010];
int I[400010],O[400010],cnt[400010];
vector<int> vr;
void dfs(int x)
{
	//cout <<x<<" ############\n";
	if (vr.size()==n) return;
	int xi=v[x][cnt[x]].Fst,yi=v[x][cnt[x]].Snd;
	cnt[x]++,vr.push_back(yi),dfs(xi);
}
inline void OUT()
{
	printf("%s",s[vr[0]].c_str());
	for (int i=1;i<n;i++) printf("%s",s[vr[i]].substr(m-1).c_str());
}
int main()
{
	freopen("tairitsu.in","r",stdin);
	freopen("tairitsu.out","w",stdout);
	scanf("%d%d",&n,&m),n=n-m+1;
	for (int i=0;i<n;i++)
	{
		scanf("%s",str),s[i]=str;
		mp[s[i].substr(0,m-1)]=mp[s[i].substr(1)]=-1;
	}
	for (map<string,int>::iterator it=mp.begin();it!=mp.end();it++) it->Snd=tc++;
	for (int i=0;i<n;i++)
	{
		int x=mp[s[i].substr(0,m-1)],y=mp[s[i].substr(1)];
		v[x].push_back(MP(y,i)),I[y]++,O[x]++;
	}
	int st=0;
	for (int i=0;i<tc;i++)
	{
		if (O[i]>I[i])
		{
			st=i;
			break;
		}
	}
	dfs(st);
	OUT();
	return 0;
}
