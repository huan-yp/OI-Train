#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
const int MAXN=1e5+10,LIM=1e5+5;
int n,m;
map<int,int>f,g;
vector<int>ret,d;
void output(){
    cout<<ret.size()<<endl;
    for(auto u:ret)cout<<u<<' ';
}
void pre(){
    int num=m;
    rep(i,2,m){
        if(i*i>m)break;
        if(num%i)continue;
        d.push_back(i);
        while(num%i==0)num/=i,f[i]++;
    }
    if(num>1)f[num]++,d.push_back(num);

}
void add(int num,int val){
    for(auto u:d){
        int tmp=num,cnt=0;
        while(tmp%u==0)tmp/=u,cnt++;
        g[u]+=val*cnt;
    }
}
int check(){
    for(auto u:d)if(g[u]<f[u])return 0;
    return 1;
}
int main(){
    freopen("random.in","r",stdin);
    freopen("random.out","w",stdout);
    cin>>n>>m;
    if(m==1){
        cout<<n<<endl;
        rep(i,1,n)cout<<i<<' ';return 0;
    }
    //对m分解质因数
    pre();
    rep(i,1,n-1){
        add((n-i),1);
        add((i),-1);
        if(check())ret.push_back(i+1);
    }
    output();
    return 0;
}