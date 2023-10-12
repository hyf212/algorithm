#include<bits/stdc++.h>

using namespace std;

int n, q[100001], front = 1, rear = 0;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		char str[10];
		scanf("%s", str);
		if (str[2] == 's') {
			int x;
			scanf("%d", &x);
			q[++rear] = x;
		} else
			if (str[2] == 'e'){
				int y;
				scanf("%d", &y);
				printf("%d\n", q[front + y - 1]);
			} else
				++front;
	}
	return 0;
}
