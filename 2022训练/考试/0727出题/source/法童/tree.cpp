#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define F first
#define S second
using namespace std;
int n,pos[200005],a[200005],ans;
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr);
	cout<<fixed<<setprecision(9);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x;cin>>x;
		pos[x-1]=i;
	}
	for(int i=0;i<n;i++)
		cin>>a[i],--a[i];
	ans=2;
	for(int i=1;i<n;i++)
	{
		if (i==1||pos[a[i]]<pos[a[i-1]])
			ans+=2;
		else if (pos[a[i]]==pos[a[i-1]]+1)
			ans++;
	}
	cout<<(double)(ans*0.5)<<endl;
	return 0;
}
