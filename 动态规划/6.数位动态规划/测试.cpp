#include <bits/stdc++.h>

using namespace std;

int n;
char a[101][101];
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int min1 = min(i, n - i + 1);
			int min2 = min(j, n - j + 1);
			int minn = min(min1, min2);
			if (minn % 2)
				printf("+");
			else
				printf(".");
		}
		printf("\n");
	}
}