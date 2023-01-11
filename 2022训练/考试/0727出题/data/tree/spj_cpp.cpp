
	#include <cstdlib>
	#include <cstdio>
	#include <iostream>
	#include <string>

	using namespace std;

	char st[111];

	bool myread(string &res){
		res = "";
		char c;
		for(int i = 1; i <= 20; i++){
			c = getchar();
			if(c < 32)
				return true;
			res.push_back(c);
		}
		return false;
	}

	int main(int argc, char * argv[])
	{
		if (freopen("user_out", "r", stdin))
		{
			string res;
			if (myread(res))
			{
				freopen("answer", "r", stdin);
				string ans[3];
				cin >> ans[0];
				cin >> ans[1];
				cin >> ans[2];
				if (res == ans[0] || res == ans[1] || res == ans[2]) {
					fprintf(stderr, "Correct.\n");
					printf("100\n");
				} else {
					fprintf(stderr, "Incorrect.\n");
					printf("0\n");
				}
			}
			else {
				fprintf(stderr, "Couldn't read a value.\n");
				printf("0\n");
			}
		}
		else {
			fprintf(stderr, "Couldn't find output file.\n");
			printf("0\n");
		}
		return 0;
	}
