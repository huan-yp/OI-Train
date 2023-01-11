#include<bits/stdc++.h>
using namespace std;
bool isprime(int n) {
	int stop=n/6+1,Tstop=sqrt(n)+5;
	if(n==2||n==3||n==5||n==7||n==11)
		return 1;
	if(n%2==0||n%3==0||n%5==0||n==1)
		return 0;
	for(int i=1;i<=stop;i++) {
		if(i*6>=Tstop) break;
		if(n%(i*6+1)==0||n%(i*6+5)==0)
			return 0;
	}
	return 1;
}
vector<pair<int,int> > t;
vector<int> ans;
int main() {
	freopen("random.in","r",stdin);
	freopen("random.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(m>n&&isprime(m)) {
		cout<<0<<endl;
		return 0;
	}
	if(m==1) {
		cout<<n<<endl;
		for(int i=1;i<=n;i++)
			cout<<i<<" ";
		cout<<endl;
	}
	int num=m;
	for(int i=2;i<=sqrt(m);i++) {
		while(num%i==0) {
			if(!t.empty()&&t[t.size()-1].first==i)
				t[t.size()-1].second++;
			else t.push_back({i,1});
			num/=i;
		}
	}
	if(num>1) t.push_back({num,1});
	if(num>n) {
		cout<<0<<endl;
		return 0;
	}
	n--;
	int nowcnt=t.size();
	for(int i=0;i<n;i++) {
		num=n-i;
		for(auto &j:t) {
			while(num%j.first==0) {
				j.second--;
				if(j.second==0) nowcnt--;
				num/=j.first;
			}
		}
		num=i+1;
		for(auto &j:t) {
			while(num%j.first==0) {
				j.second++;
				if(j.second==1) nowcnt++;
				num/=j.first;
			}
		}
		if(nowcnt<=0) ans.push_back(i+2);
	}
	cout<<ans.size()<<endl;
	if(ans.size()) {
		for(int i:ans) cout<<i<<" ";
		cout<<endl;
	}
	return 0;
}