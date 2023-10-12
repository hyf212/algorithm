#include <bits/stdc++.h>

using namespace std;

int n, c[31];

int nxt(int x) {
	int t = (x | (x - 1)) + 1;
	return t | (((t & -t) / (x & -x) >> 1) - 1);
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		printf("0");
	printf("\n");
	for (int i = 1; i <= n; i++) {
		for (int j = (1 << i) - 1; j < 1 << n; j = nxt(j)) {
			for (int k = 1, l = j; k <= n; l /= 2, k++)
				c[k] = l & 1;            
			for (int k = n; k; k--)
				printf("%d", c[k]);
			printf(" ");
		}
		printf("\n");
	}
}