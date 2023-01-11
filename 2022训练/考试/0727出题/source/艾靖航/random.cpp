#include<bits/stdc++.h>
#define LL long long
#define dv double
#define il inline
#define us unsigned
#define eps 1e-6
#define INF 0x3f3f3f3f
#define ls k<<1
#define rs k<<1|1
#define tmid ((tr[k].l+tr[k].r)>>1)
#define nmid ((l+r)>>1)
#define pub push_back
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define mkp make_pair
#define x first
#define y second
using namespace std;
#define int LL
il void Read(int &x){
  int f=1; x=0; char c=getchar();
  while(c<'0'||c>'9'){
    if(c=='-')f=-1; c=getchar();
  }
  while(c>='0'&&c<='9'){
    x=(x<<3)+(x<<1)+c-'0', c=getchar();
  }
  x*=f;
}
const int N=100010;
int n, m, cnt[N];
il void Modify(int x, int v){
  for(int i=2; i*i<=x; i++){
    if(x%i==0){
      while(x%i==0)cnt[i]+=v, x/=i;
    }
  }
  if(x>1)cnt[x]+=v;
}
signed main(){
  freopen("random.in", "r", stdin);
  freopen("random.out", "w", stdout);
  Read(n), Read(m);
  if(m==1){
    printf("%lld\n", n);
    for(int i=1; i<=n; i++)printf("%lld ", i);
    return 0;
  }
  vector<pii > t;
  for(int i=2; i*i<=m; i++){
    if(m%i==0){
      int tmp=0;
      while(m%i==0)tmp++, m/=i;
      t.pub(mkp(i, tmp));
    }
  }
  if(m>1)t.pub(mkp(m, 1));
  vector<int> ans;
  for(int i=1; i<n; i++){
    Modify(n-i, 1), Modify(i, -1);
    bool ff=1;
    for(auto o: t){
      if(o.x>=N||cnt[o.x]<o.y){
        ff=0; break;
      }
    }
    if(ff)ans.pub(i+1);
  }
  printf("%lld\n", (int)ans.size());
  for(int i: ans)printf("%lld ", i);
  return 0;
}
