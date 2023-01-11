#include<cstdio>
#include<algorithm>
#include<cstring>
#define INF 0x3f3f3f3f
#define int long long
#define _ 0
#define re register
#define drep(k ,l ,r) for(re int k = (r) ; k >= (l) ; -- k)
#define rep(k ,l ,r) for(re int k = l ; k <= r ; ++ k)
int c ,t ,n;
long double l;
int read() {
	char cc = getchar();re int cn = 0 ,flus = 1;
	while(cc < '0' || cc > '9') {if(cc == '-') flus = - flus ; cc = getchar();}
	while(cc >= '0' && cc <= '9') cn = cn * 10 + cc - '0' ,cc = getchar();
	return cn * flus;
}
signed main() {
	scanf("%lld%lld%200Lf" ,&c ,&t ,&l);
	while(t --) {
		n = read();
		if(n == 1) printf("0 0\n");
		else if(n == 2) printf("%.200Lf %.200Lf\n" ,l ,l);
		else if(n == 3) printf("0 %.200Lf\n" ,l);
		else if(n == 4) printf("%.200Lf 0\n" ,l);
		else {
			re int tot = 4 ,tmp = 2;
			rep(i ,1 ,1000) {
				tot += (tmp - 1) * (tmp - 1);
				if(tot >= n) {
					tot -= (tmp - 1) * (tmp - 1) ,n -= tot;
					printf("%.200Lf %.200Lf\n" ,((n - 1) / (tmp - 1) << 1 | 1 ) * l / (tmp - 1 << 1) ,(((n - 1) % (tmp - 1) + 1 << 1) - 1) * l / (tmp - 1 << 1));
					break;
				}
				tmp =(tmp << 1) - 1;
				if(tmp * tmp >= n) {
					n -= tot;
					if((n - 1) % tmp < (tmp >> 1)) printf("%.200Lf %.200Lf\n",((n - 1) / tmp << 1) * l / (tmp - 1) ,((n - 1) % tmp << 1 | 1) * l / (tmp - 1));
					else printf("%.200Lf %.200Lf\n",((n - 1) / tmp << 1 | 1) * l / (tmp - 1) ,((n - 1 - (tmp >> 1)) % tmp << 1) * l / (tmp - 1));
					break;
				}
				tot = tmp * tmp;
			}
		}
	}
	return ~~(0^_^0);
}
