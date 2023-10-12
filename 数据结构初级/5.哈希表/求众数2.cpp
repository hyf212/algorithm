#include<bits/stdc++.h>

using namespace std;

unordered_map<int, int> c;
int n, a[200001];
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		c[x]++;
	}
	int x = 0, l = 0;
	for (auto its : c) {
		if (its.second > x)
			x = its.second, l = 0;
		if (its.second == x)
			a[++l] = its.first;
	}
	sort(a + 1, a + l + 1);
	for (int i = 1; i <= l; i++)
		printf("%d ", a[i]);
	return 0;
}