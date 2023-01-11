#include<bits/stdc++.h>
//#define int long long
using namespace std;

vector<int>ans;
map<int,int>mp1,mp2;
signed main() {
    ios::sync_with_stdio(false),cin.tie(nullptr);
    freopen ("random.in","r",stdin);
    freopen ("random.out","w",stdout);
    mp1.clear(); mp2.clear();
    int n , m;
    cin >> n >> m;
    if(n==1 && m==1){
    	cout << 1 <<endl << 1 << endl;
    	return 0;
	}
    n--;
    int mm = m;
    for(int i = 2; i*i <= mm; i++) {
        if(mm%i==0) {
            while(mm%i==0) {
                mm/=i;
                mp2[i]++;
            }
        }
    }
    if(mm > 1) mp2[mm]++;
    int cnt=1;
    if(cnt%m == 0) {
        ans.push_back(1);
    }
    for(int i = 2; i <= n; i++) {
        if(i >= 2) {
            int x = n-i+2;
            for(int j = 2; j*j <= x; j++) {
                if(x%j==0) {
                    while(x%j==0) {
                        x/=j;
                        mp1[j]++;
                    }
                }
            }
            if(x > 1) mp1[x]++;
			x = i-1;
			for(int j = 2; j*j <= x; j++) {
                if(x%j == 0) {
                    while(x%j == 0) {
                        x/=j;
                        mp1[j]--;
                    }
                }
            }
            if(x>1) mp1[x]--;
        }
        bool f=true;
        for(map<int,int>::iterator i = mp2.begin(); i !=mp2.end() ;i++) {
        	if((i->second)>mp1[(i->first)]) {
        		f=false;
        		break;
			}
		}
		if(f){
			ans.push_back(i);
		}
    }
    if(1%m == 0) {
        ans.push_back(n+1);
    }
    cout << ans.size() << endl;
    for(int i=0; i<ans.size(); i++) {
    	cout<<ans[i]<<' ';
    }
    return 0;
}
/*
1
1 2 1
1 3  3 1
1 4 6 4 1
93750
100000 1000000000
*/
