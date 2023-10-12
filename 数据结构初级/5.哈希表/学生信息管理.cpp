#include<bits/stdc++.h>

using namespace std;

struct Info {
	int a, b, c;
};
int n, m;
unordered_map<string, Info> stu;
int main(void) {
	scanf("%d%d", &n, &m);
	stu.clear();
	for (int i = 1; i <= n; i++) {
		string str;
		char s[21];
		scanf("%s", s);
		str = s;
		Info p;
		scanf("%d%d%d", &p.a, &p.b, &p.c);
		stu[str] = p;
	}
	for (int i = 1; i <= m; i++) {
		string str;
		char s[21];
		scanf("%s", s);
		str = s;
		if (stu.find(str) == stu.end())
			printf("-1 -1 -1\n");
		else {
			printf("%d %d %d\n", stu[str].a, stu[str].b, stu[str].c);
		}
	}
	return 0;
}