#include<bits/stdc++.h>
using namespace std;
char ch[105];
int cnt[2];
signed main()
{
	int t;cin>>t;
	while(t--){
		int a,b,n,i,ans=0;
		cnt[0]=cnt[1]=0;
		cin>>n>>a>>b;
		scanf("%s",ch+1);
		for(i=1;i<=n;i){
			while(ch[i+1]==ch[i])
			i++;
			cnt[ch[i]-'0']++;
			i++;
		}
		if(b>=0){
			cout<<n*a+n*b<<endl;
		}
		else{
			cout<<n*a+(min(cnt[0],cnt[1])+1)*b<<endl;
		}
	}
	return 0;
}

