#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>

#define sqr(x) ((x) * (x))
#define minn(x,y) (x=(y)<(x)?(y):(x))
#define maxx(x,y) (x=(y)>(x)?(y):(x))
#define pluss(x,y) (x+=(y),x%=mod)

using namespace std;

typedef	long long	int64;

FILE	*Finn, *Fout, *Fstd, *Fres;

void	Return(double p, char* s)
{
	fprintf(Fres, "%.3lf\n%s\n", p, s);
	exit(0);
}

int T,cnt;
char c[20],s[20];

int	main(int args, char** argv)
{

	Finn = fopen(argv[1], "r");
	Fstd = fopen(argv[2], "r");
	Fout = fopen(argv[3], "r");
	Fres = fopen(argv[4], "w");
	
	fscanf(Finn,"%d",&T);
	for (;T--;)
	{
		 memset(c,0,sizeof(c)); memset(s,0,sizeof(s));
		 fscanf(Fstd,"%s",c); fscanf(Fout,"%s",s);
		 string A=(string)c,B=(string)s;
		 if (A==B) ++cnt;
	} 
	int score=cnt/100;
	Return(score/100.,"???");
	return 0;
}
