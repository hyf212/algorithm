#include<bits/stdc++.h> 

using namespace std;

const int size = 1001;
int m, q[size + 1], front = 1, rear = size;
char str[1011];

int main(void) {
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		scanf("%s", str);
		if (str[2] == 's') {
			int x;
			scanf("%d", &x);
			rear = rear % size + 1;
			q[rear] = x;
		} else
			if (str[0] == 'p')
				front = front % size + 1;
			else {
				int x;
				scanf("%d", &x);
				if (front + x - 1 <= size)
					printf("%d\n", q[front + x - 1]);
				else
					printf("%d\n", q[(front + x - 1) % size]);
			}
	}
	return 0;
}