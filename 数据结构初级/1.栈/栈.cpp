#include<bits/stdc++.h>

using namespace std;

int m, top, s[100001];
char str[21];
int main(void) {
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		scanf("%s", str);
		if (str[1] == 'u') {
			int x;
			scanf("%d", &x);
			s[++top] = x;
		} else
			if (str[0] == 'p')
				--top;
				else
					printf("%d\n", s[top]);
	}
	return 0;
}