#include<bits/stdc++.h>
#define ll long long
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll Rand(ll l,ll r){
    uniform_int_distribution<long long> rd(l,r);
    return rd(rnd);
}
int main(){
    for(int T=1;T<=40;T++){
        // stringstream ss;
        // ss<<"city"<<T<<".in";
        // ofstream in(ss.str());
        // if(T<=5) in<<Rand(50,100)<<' '<<0;
        // else if(T<=15) in<<Rand(50,100)<<' '<<Rand(15000,20000);
        // else if(T<=25) in<<Rand(50,100)<<' '<<Rand(1e12,1e18);
        // else in<<Rand(1500,2000)<<' '<<Rand(1e12,1e18);
        stringstream ss2;
        ss2<<"a < city"<<T<<".in > city"<<T<<".out";
        system(ss2.str().c_str());
    }
}