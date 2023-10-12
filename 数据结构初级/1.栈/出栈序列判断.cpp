#include<bits/stdc++.h>

 


using namespace std;

int n, s[100001], top = 0;
int main(void) {
	scanf("%d", &n);
	int l = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		if (s[top] != x) {
			for (int j = l + 1; j <= x; j++) {
				s[++top] = j;
				printf("push %d\n", j);
			}
			l = x;
		}
		printf("pop\n");
		--top;
	}
	return 0;
}