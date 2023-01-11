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
const int MAXN=2e5+10;
int n,dfn[MAXN],bfn[MAXN];
int to[MAXN];
int ord[MAXN],tag[MAXN];
int sum[MAXN],tag2[MAXN];
int qry(int L,int R){if(L>R)return 0;return sum[R]-sum[L-1];}
void upd(int L,int R){
    if(L>R)return;
    tag2[L]++;tag2[R+1]--;
}
db ans;
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    rep(i,1,n)cin>>dfn[i];
    rep(i,1,n)cin>>bfn[i],to[bfn[i]]=i;
    rep(i,1,n)dfn[i]=to[dfn[i]];
    rep(i,1,n)ord[dfn[i]]=i;
    tag[1]=1;
    rep(i,2,n)tag[i]=(ord[i]>ord[i+1]);
    rep(i,1,n)sum[i]=sum[i-1]+tag[i];
    rep(i,1,n-1)if(qry(dfn[i],dfn[i+1]-1))upd(dfn[i],dfn[i+1]-1);
    rep(i,1,n)tag2[i]+=tag2[i-1];
    rep(i,1,n)if(tag[i])ans=ans+1;else if(!tag2[i])ans=ans+0.5;
    printf("%.6f",ans);
    return 0;
}