#include<bits/stdc++.h>
#define int long long
#define ebk emplace_back
using namespace std;
const string NAME="notebook";
namespace IN{
    char *ptr;
    #define gchar() (*ptr++)
    template<typename _Tp>inline void read(_Tp &x){
       cin>>x;
    }
    template<typename _Tp,typename ...Args>
    inline void read(_Tp &x,Args &...args){read(x),read(args...);}
}using IN::read;
const int S=1e7;
int n,K,ans;
int fpow(unsigned int a,int b){
    unsigned int res=1;
    for(;b&&res<=n&&a<=n;a*=a,b>>=1)
        if(b&1)res*=a;
    return res>n||b?n+1:res;
}
int f(int x){return x*(x+1)*(2*x+1)/6;}
vector<int>pri;
vector<pair<int,int>>g;
bitset<S+10>vis;
void dfs(int p,int s){
    if(p==g.size()){
        int k=n/s-s+1;
        if(k<=0||k&1)return;
        ans=max(ans,s);
        return;
    }
    for(int t=0,d=1;t<=g[p].second;t++,d*=g[p].first)
        dfs(p+1,s*d);
}
signed main(){
    freopen("notebook.out","w",stdout);
	freopen("notebook.in","r",stdin);
    for(int i=2;i<=S;i++){
        if(!vis[i])pri.ebk(i);
        for(int j=i;j*i<=S;j++)vis[j*i]=1;
    }
    int Task;read(Task);
    while(Task--){
        read(n,K);
        if(K==1){
            ans=1,g.clear();
            int nn=(n<<=1);
            for(int i:pri)if(!(nn%i)){
                int t=0;
                while(!(nn%i))t++,nn/=i;
                g.ebk(i,t);
            }else if(i*i>nn)break;
            if(nn>1)g.ebk(nn,1);
            dfs(0,1);
            printf("%lld\n",ans);
            continue;
        }
        if(K==2){
            ans=-1;
            for(int i=1;i<=n;i++){
                int mn=f(i);
                if(mn>n)break;
                int l=1,r=sqrt(n)-i+1,res=-1;
                while(l<=r){
                    int mid=(l+r)>>1;
                    int sm=f(mid+i-1)-f(mid-1);
                    // printf("%lld %lld %lld %lld:%lld\n",i,l,r,mid,sm);
                    if(sm<=n)l=mid+1,res=mid;
                    else r=mid-1;
                }
                assert(~res);
                int sm=f(res+i-1)-f(res-1);
                if(sm==n)ans=i;
            }
            printf("%lld\n",ans);
            continue;
        }
        int l=1,r=0,s=0;
        ans=-1;
        for(int i=1;i<=n;i++){
            int d=fpow(++r,K);
            if(d>n)break;
            s+=d;
            while(s>n)s-=fpow(l++,K);
            if(s==n)ans=max(ans,r-l+1);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
