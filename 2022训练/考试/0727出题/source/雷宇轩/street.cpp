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
const int MAXN=1e5+10;
const db EPS=1e-8;
int n;
int tag[MAXN];
vector<int>e[MAXN];
int sz[MAXN];
db f[MAXN];
ll g[MAXN];
db tmp[MAXN];
int tot;
bool cmp(const db& d1,const db& d2){
    return d1-d2<EPS;
}
void dfs(int u){
    if(e[u].empty())sz[u]=1;
    ll all=0;
    for(auto v:e[u]){
        dfs(v);
        g[u]+=g[v];
        all+=g[v];
        sz[u]+=sz[v];
    }
    if(tag[u])g[u]=0;
    g[u]+=2;
    tot=0;
    for(auto v:e[u]){
        tmp[++tot]=1.00*sz[v]/sz[u]*g[v];
        f[u]+=1.00*sz[v]/sz[u]*(f[v]+1);
    }
    f[u]+=all;
    sort(tmp+1,tmp+1+tot,cmp);
    rep(i,1,tot){
        f[u]-=tmp[i]*i;
    }
}
int main(){
    freopen("street.in","r",stdin);
    freopen("street.out","w",stdout);
    cin>>n;
    rep(i,2,n){
        int fa;char tmp;
        cin>>fa>>tmp;
        if(tmp=='Y')tag[i]=1;
        e[fa].push_back(i);
    }
    dfs(1);
    printf("%.7f",f[1]);


    return 0;
}