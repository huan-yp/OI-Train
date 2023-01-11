#include <bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
using namespace std;
inline void read(int &x)
{
    x = 0;int f = 1;char ch = getchar();
    while (ch != 45 && (ch > '9' || ch < '0'))ch = getchar();
    if (ch == 45) {f = -1, ch = getchar();}
    while (ch <= '9' && ch >= '0') {x = x * 10 + ch - 48;ch = getchar();}
    x *= f;
}
/*
Attention:
斜率优化除法的时候记得乘 1.0
STL的 queue 无O2很慢 
from:https://szkopul.edu.pl/problemset/problem/HH7LQVRVHom1g8YRe9423d1P/site/?key=statement
*/
const int N = 1005;
const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int i, j, k, n, s, t, m, x1, x2, y1, y2;
int dis[N][N], p[N][N], ans[N][N], now[N];
pair<int, int> q[N * N];
struct line {

    int k, b;
    int calc(int x)
    {
        return k * x + b;
    }
};
inline bool ok(int x, int y) 
{
    return x && y && x <= n && y <= m;
}
void bfs() {
    int head = 1, tail = 1;
    dis[x1][y1] = 1;
    q[tail++] = make_pair(x1, y1);
    while (tail != head) 
	{
        int x = q[head].first, y = q[head++].second;
        for (i = 0; i < 4; i++) 
		{
       	 	if (~dis[x + dx[i]][y + dy[i]] || !ok(x + dx[i], y + dy[i]))continue;
            dis[x + dx[i]][y + dy[i]] = dis[x][y] + 1;
            q[tail++] = (make_pair(x + dx[i], y + dy[i]));
        }
        if ((~dis[x2][y2]) && dis[x2][y2] != INF)return;
    }
}
bool check(int x)
{

    for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++)
    if (ans[i][j] < x)
    dis[i][j] = INF;
    else
    dis[i][j] = -1;
    
    bfs();
    return (~dis[x2][y2]) && dis[x2][y2] != INF;
}
double insection(line a, line b)
{
    return 1.0 * (b.b - a.b) / (a.k - b.k);
}
void init() {
    memset(ans, 15, sizeof(ans));
    int tail = 1, head = 1;
    line q[N];
    for (i = n; i >= 1; i--) {
        head = tail = 1;
        for (j = 1; j <= m; j++)
        {
            if (p[i][j])
            now[j] = i;
            if (now[j])
            {
				line tmp = (line) {-2 * j, j *j + (i - now[j])*(i - now[j])};
                while (tail - 2 >= head && insection(tmp, q[tail - 1]) <= insection(tmp, q[tail - 2]))
                tail--;
                q[tail++] = tmp;
            }
            while (head + 1 < tail && q[head].calc(j) >= q[head + 1].calc(j))
            head++;
            if (head != tail)
            ans[i][j] = min(ans[i][j], j * j + q[head].calc(j));
        }
        head = tail = 1;
        for (j = m; j >= 1; j--)
        {
            if (now[j])
            {
                line tmp = (line) {-2 * j, j *j + (i - now[j])*(i - now[j])};
                while (tail - 2 >= head && insection(tmp, q[tail - 1]) >= insection(tmp, q[tail - 2]))
                tail--;
                q[tail++] = tmp;
            }
            while (head + 1 < tail && q[head].calc(j) >= q[head + 1].calc(j))
            head++;
            if (head != tail)
            ans[i][j] = min(ans[i][j], j * j + q[head].calc(j));
        }
    }
    for (i = 1; i <= n; i++)
    {
        head = tail = 1;
        for (j = 1; j <= m; j++)
        {
            if (p[i][j])
            now[j] = i;
            if (now[j])
            {
                line tmp = (line) {-2 * j, j *j + (i - now[j])*(i - now[j])};
                while (tail - 2 >= head && insection(tmp, q[tail - 1]) <= insection(tmp, q[tail - 2]))
                tail--;
                q[tail++] = tmp;
            }
            while (head + 1 < tail && q[head].calc(j) >= q[head + 1].calc(j))
            head++;
            if (head != tail)
			ans[i][j] = min(ans[i][j], j * j + q[head].calc(j));
        }
        head = tail = 1;
        for (j = m; j >= 1; j--)
        {
            if (now[j])
            {
                line tmp = (line) {-2 * j, j *j + (i - now[j])*(i - now[j])};
                while (tail - 2 >= head && insection(tmp, q[tail - 1]) >= insection(tmp, q[tail - 2]))
                    tail--;
                q[tail++] = tmp;
            }
            while (head + 1 < tail && q[head].calc(j) >= q[head + 1].calc(j))
                head++;
            if (head != tail)
                ans[i][j] = min(ans[i][j], j * j + q[head].calc(j));
        }
    }
}
signed main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    //freopen(".ans","w",sdtout);
    read(n), read(m);
    read(x1), read(y1), read(x2), read(y2);
    read(s);
    for (i = 1; i <= s; i++)
    {
        int x, y;
        read(x), read(y);
        p[x][y] = 1;
    }
    init();
    int l = 0, r = ans[x1][y1], opt = 0;
    while (r >= l)
    {
        int mid = (l + r) / 2;
        if (check(mid))
            l = mid + 1, opt = mid;
        else
            r = mid - 1;
    }
    cout << opt << endl;
    return 0;
}
