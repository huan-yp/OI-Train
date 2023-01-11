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
const int MAXN=160,MAXM=510,INF=1e9;
int n,m,a[MAXN][MAXM],ans=-INF;
int sum[MAXM][MAXN];
int qry(int x,int y,int c){
    if(x>y)return 0;
    return sum[c][y]-sum[c][x-1];
}
int f[2][13][MAXN][MAXN];
int suf1[MAXN][MAXN],suf2[MAXN][MAXN],suf3[MAXN][MAXN];
void tomax(int& x,int y){
    x=max(x,y);
}
int main(){
    ios::sync_with_stdio(false);
    freopen("noi.in","r",stdin);
    freopen("noi.out","w",stdout);
    cin>>n>>m;
    rep(i,1,n)rep(j,1,m)cin>>a[i][j];
    rep(j,1,m)rep(i,1,n)sum[j][i]=sum[j][i-1]+a[i][j];
    rep(i,0,m+5)rep(j,0,12)rep(k,0,n+5)rep(kk,0,n+5)f[i&1][j][k][kk]=-INF;
    f[0][0][0][0]=0;
    rep(j,1,m){
        rep(x,0,n+5)rep(y,0,n+5)suf1[x][y]=suf2[x][y]=suf3[x][y]=-INF;
        rep(x,1,n)per(y,n,x)suf1[x][y]=max(suf1[x][y+1],f[(j-1)&1][1][x][y]);
        rep(y,1,n)rep(x,1,y)suf2[x][y]=max(suf2[x-1][y],f[(j-1)&1][2][x][y]);
        rep(y,1,n)per(x,y,1)suf3[x][y]=max(suf3[x+1][y],f[(j-1)&1][2][x][y]);
        rep(z,0,12)rep(k,0,n+5)rep(kk,0,n+5)f[j&1][z][k][kk]=-INF;
        //计算第j列的答案
        //第0类
        tomax(f[j&1][0][0][0],0);
        //第1类
        rep(x,1,n)rep(y,x,n)tomax(f[j&1][1][x][y],f[(j-1)&1][0][0][0]+qry(x,y,j)),\
        tomax(f[j&1][1][x][y],f[(j-1)&1][1][x][y]+qry(x,y,j));
        //第2类
        rep(x,1,n)rep(y,x,n)tomax(f[j&1][2][x][y],f[(j-1)&1][2][x][y]+qry(x,y,j)),\
        tomax(f[j&1][2][x][y],suf1[x][y+1]+qry(x,y,j));
        rep(x,1,n){
            int tag=suf2[x-1][x-1];
            rep(y,x,n){
                tomax(tag,suf2[x][y]);
                tomax(f[j&1][2][x][y],tag+qry(x,y,j));
            }
        }
        //第3类
        rep(x,1,n)rep(y,x,n)tomax(f[j&1][3][x][y],f[(j-1)&1][3][x][y]+qry(x,y,j)),\
        tomax(f[j&1][3][x][y],suf3[x+1][y]+qry(x,y,j));
        //第4类
        tomax(f[j&1][4][0][0],f[(j-1)&1][4][0][0]);
        rep(x,1,n)rep(y,x,n)tomax(f[j&1][4][0][0],f[(j-1)&1][3][x][y]);
        //第5类
        rep(x,1,n)rep(y,x+2,n)tomax(f[j&1][5][x][y],f[(j-1)&1][4][0][0]+qry(x,y,j));
        //第6类
        rep(x,1,n)rep(y,x+2,n)tomax(f[j&1][6][x][y],f[(j-1)&1][6][x][y]+a[x][j]+a[y][j]),\
        tomax(f[j&1][6][x][y],f[(j-1)&1][5][x][y]+a[x][j]+a[y][j]);
        //第7类
        rep(x,1,n)rep(y,x+2,n)tomax(f[j&1][7][x][y],f[(j-1)&1][6][x][y]+qry(x,y,j));
        //第8类
        tomax(f[j&1][8][0][0],f[(j-1)&1][8][0][0]);
        rep(x,1,n)rep(y,x+2,n)tomax(f[j&1][8][0][0],f[(j-1)&1][7][x][y]);
        //第9类
        rep(x,1,n)rep(y,x+2,n)tomax(f[j&1][9][x][y],f[(j-1)&1][9][x][y]+a[x][j]+a[y][j]),\
        tomax(f[j&1][9][x][y],f[(j-1)&1][8][0][0]+a[x][j]+a[y][j]);
        //第10类
        rep(x,1,n)rep(y,x+2,n)tomax(f[j&1][10][x][y],f[(j-1)&1][10][x][y]+qry(x,y,j)),\
        tomax(f[j&1][10][x][y],f[(j-1)&1][9][x][y]+qry(x,y,j));
        //第11类
        rep(x,1,n)rep(y,x+2,n)tomax(f[j&1][11][x][y],f[(j-1)&1][11][x][y]+a[x][j]+a[y][j]),\
        tomax(f[j&1][11][x][y],f[(j-1)&1][10][x][y]+a[x][j]+a[y][j]);
        rep(x,1,n)rep(y,x+2,n)tomax(ans,f[j&1][11][x][y]);
    }
    cout<<ans;
    return 0;
}