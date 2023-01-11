#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>

#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=z;x>=y;x--)

using namespace std;
const int N=1e5+10;

vector<int>e[N];
bool ha[N];
int le[N];
double dp[N][2];

void dfs(int cur)
{
	double mi=1e9;
	for(int ni=0;ni<e[cur].size();ni++)
	{
		int nt=e[cur][ni];
		dfs(nt);
		le[cur]+=le[nt];
		mi=min(mi,dp[nt][1]-dp[nt][0]*2-3);
		dp[cur][0]+=(dp[nt][0]+2)*2;
	}
	if(!le[cur]) le[cur]=1;
	else dp[cur][1]=dp[cur][0]+mi;
}

int main()
{
	freopen("street.in","r",stdin);
	freopen("street.out","w",stdout);
	int n;
	scanf("%d",&n);
	rep(i,2,n)
	{
		int f;
		char c[2];
		scanf("%d %s",&f,c);
		if(*c=='Y') ha[i]=1;
		else ha[i]=0;
		e[f].push_back(i);
	}
	dfs(1);
	printf("%.4lf",1.0*dp[1][1]/le[1]);
	return 0;
}

