#include<set>
#include<map>
#include<queue>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
#define pr pair
#define f first
#define s second
#define ll long long
#define mp make_pair
#define pll pr<ll,ll>
#define pii pr<int,int>
#define piii pr<int,pii>
#define piiii pr<pii,pii>
using namespace std;
int s[100002];
int main()
{
	freopen("random.in","r",stdin);
	freopen("random.out","w",stdout);
	int n,m;
	cin>>n>>m;
	s[0]=1;
	for(int i=1;i<n;i++)
	{
		for(int j=i;j>0;j--) s[j]+=s[j-1],s[j]%=m;
	}
	vector<int> ans;
	for(int i=0;i<n;i++) if(s[i]==0) ans.push_back(i);
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++) cout<<ans[i]+1<<' ';
	cout<<endl;
	return 0;
}
