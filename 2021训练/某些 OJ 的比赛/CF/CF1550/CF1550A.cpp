#include<bits/stdc++.h>
using namespace std;
signed main()
{
	int i,t,n;
	cin>>t;
	while(t--){
		cin>>n;
		for(i=1;i<=n;i++){
			if(i*i>=n){
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}

