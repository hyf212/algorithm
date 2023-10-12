#include<bits/stdc++.h>

using namespace std;

unordered_map<int, int> c;
int n;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		c[x]++;
	}
	int cnt = 0;
	for (auto its : c) {
		cnt += its.second / 2 * 2;
	}
	if (cnt < n)
		printf("%d\n", cnt + 1);
	else
		printf("%d\n", cnt);
	return 0;
}
