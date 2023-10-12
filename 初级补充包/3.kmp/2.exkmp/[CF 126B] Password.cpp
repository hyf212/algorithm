#include <bits/stdc++.h>

using namespace std;

int n, z[1000001];
char s[1000011];

void exkmp() {
	n = strlen(s + 1);
	z[1] = 0;
	int L = 1, R = 0;
	for (int i = 2; i <= n; i++) {
		if (i > R)
			z[i] = 0;
		else {
			int k = i - L + 1;
			z[i] = min(z[k], R - i + 1);
		}
		while (i + z[i] <= n && s[z[i] + 1] == s[i + z[i]])
			++z[i];
		if (i + z[i] - 1 > R)
			L = i, R = i + z[i] - 1;
	}
	int x = 0, ans = 0;
	for (int i = 1; i <= n; i++) {
		if (i + z[i] - 1 == n)
			if (x >= z[i])
				ans = max(ans, z[i]);
		x = max(x, z[i]);	
	}
	if (!ans)
		printf("Just a legend\n");
	else {
		for (int i = 1; i <= ans; i++)
			printf("%c", s[i]);
	}
}
int main(void) {
	scanf("%s", s + 1);
	exkmp();
	return 0;
}