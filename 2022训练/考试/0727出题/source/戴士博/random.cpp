#include<bits/stdc++.h>
#define N 100010
using namespace std;
int n,m,num[N],cnt;
vector<int> op;

int main(){
	
	freopen("random.in","r",stdin);
	freopen("random.out","w",stdout);
	
	cin>>n>>m;
	for(int i=2;i<=n;i++){
		if(m%i==0) cnt++;
		while(m%i==0) m/=i,num[i]--;
	}
	if(m>1){
		cout<<0;
		return 0;
	}
	for(int i=2;i<=n;i++){
		int ss=sqrt(i-1),fz=i-1;
//		printf("-%d +%d\n",i-1,n-i+1);
		for(int j=2;j<=ss;j++) while(fz%j==0){
			if(!num[j]) cnt++;
			num[j]--;
			fz/=j;
		}
		if(fz>1){
			if(!num[fz]) cnt++;
			num[fz]--;
			fz/=fz;
		}
		fz=n-i+1;ss=sqrt(fz);
		for(int j=2;j<=ss;j++) while(fz%j==0){
			num[j]++;
			if(!num[j]) cnt--;
			fz/=j;
		}
		if(fz>1){
			num[fz]++;
			if(!num[fz]) cnt--;
			fz/=fz;
		}
		if(!cnt) op.push_back(i);
	}
	cout<<op.size()<<endl;
	for(auto i:op) cout<<i<<' ';
	return 0;
}