//代码实现
#include <bits/stdc++.h>

using namespace std;

int n;
char s[2 * N + 2];

void getmin() {
	n = strlen(s + 1);
	for (int l = 1; l <= n; i++)
		s[l + n] = s[l];
	int i = 1, j = 2;
	while (j <= n) {
		int k = 0;
		while (k < n && s[i + k] == s[j + k])
			++k;
		if (s[i + k] > s[j + k])
			i += k + 1;
		else
			j += k + 1;
		if (i == j)
			j++;
		if (i > j)
			swap(i, j);
	}
	for (int l = i; l <= i + n - 1; l++)
		printf("%c", s[i]);
}
int main(void) {
	getmin();
	return 0;
}