#include<bits/stdc++.h>
#define ll long long
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll Rand(ll l,ll r){
    uniform_int_distribution<long long> rd(l,r);
    return rd(rnd);
}
int main(){
    for(int T=6;T<=13;T++){
        stringstream ss1;
        ss1<<"number"<<T<<".in";
        ofstream asd(ss1.str());
        asd<<Rand(5000,50000)<<' '<<Rand(1,10^9)<<' '<<Rand(1,10^9)<<endl;
        stringstream ss2;
        ss2<<"a < number"<<T<<".in > number"<<T<<".out";
        system(ss2.str().c_str());
    }
}