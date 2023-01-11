#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,cnt,ans[100009];
pair<int,int> ft[15];
int top;
int fctin(int x,int y){
	int tot=0;
	while(x){
		tot+=x/y;
		x/=y;
	}
	return tot;
}
signed main(){
	freopen("random.in","r",stdin);
	freopen("random.out","w",stdout);
	cin>>n>>m;n--;
	for(int i=2;i*i<=m;i++)
		if(m%i==0){
			ft[++top].first=i;
			while(m%i==0)m/=i,ft[top].second++;
		}
	if(m!=1)ft[++top]=make_pair(m,1);
	for(int i=0;i<=n;i++){
		bool fl=1;
		for(int j=1;j<=top;j++){
			int fv=ft[j].first,dv=ft[j].second;
			if(fctin(n,fv)-fctin(i,fv)-fctin(n-i,fv)!=dv){
				fl=0;
				break;
			}
		}
		if(fl)ans[++cnt]=i+1;
	}
	cout<<cnt<<endl;
	for(int i=1;i<=cnt;i++)cout<<ans[i]<<' ';puts("");
	return 0;
}
