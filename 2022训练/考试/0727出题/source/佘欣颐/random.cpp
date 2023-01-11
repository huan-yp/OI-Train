#include <bits/stdc++.h>
using namespace std;

#define int long long
#define LD long double
#define forn(i,a,n) for (int i=a; i<n; i++)

int n,m;
const int N = 114514;

struct _ {
	vector<pair<int,int> > v;
	void cal(int x){
		vector<int> f;
		for (int i=1; i*i<=x; i++){
			if (x%i==0){
				f.push_back(i);
				if (x/i!=i) f.push_back(x/i);
			}
		}
		sort(f.begin(),f.end());
		for (auto u : f){
			if (u==1) continue;
			int cnt=0;
			while (x%u==0){
				cnt++;
				x/=u;
			}
			if (cnt) v.push_back({u,cnt});
		}
	}
	_ operator * (const int &x){
		map<int,int> c;
		_ X; X.cal(x);
		for (auto u : X.v) c[u.first]=u.second;
		vector<pair<int,int> > w=v;
		for (auto &u : w) u.second+=c[u.first],c[u.first]=-1;
		for (auto u : c) if (u.second!=-1 && u.second!=0)
			w.push_back({u.first,u.second});
		sort(w.begin(),w.end()); 
		_ res; res.v=w;
		return res;
	}
	_ operator - (const _ &x){
		map<int,int> c;
		vector<pair<int,int> > w=v; 
		for (auto p : x.v) c[p.first]=p.second;
		for (auto &p : w) p.second-=c[p.first];
		_ res;
		for (auto p : w) if (p.second>0) res.v.push_back({p.first,p.second});
		return res;
	}
	_ operator + (const _ &x){
		map<int,int> c;
		vector<pair<int,int> > w=v; 
		for (auto p : x.v) c[p.first]=p.second;
		for (auto &p : w) p.second+=c[p.first];
		_ res; res.v=w;
		return res;
	}
	bool operator >= (const _ &x){
		map<int,int> c; 
		for (auto p : v) c[p.first]=p.second;
		for (auto p : x.v) if (p.second>c[p.first]) return false;
		return true;
	}
} a[N],M;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	freopen("random.in","r",stdin);
	freopen("random.out","w",stdout);
	cin>>n>>m;
	M.cal(m);
	forn(i,2,n) a[i]=a[i-1]*i;
	vector<int> res;
	forn(i,0,n){
		_ p=a[n-1];
		if (!i){
			if (m==1) res.push_back(i+1);
			continue;
		}
		p=p-a[i];
		if (i>1) p=p+a[i-1];
		if (p>=M) res.push_back(i+1);
	}
	cout<<res.size()<<endl;
	for (auto u : res) cout<<u<<" ";
	cout<<endl;
	return 0;
}

