#include<bits/stdc++.h>

using namespace std;
priority_queue<int, vector<int>, greater<int> > a;
int n;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		if (x == 1) {
			int y;
			scanf("%d", &y);
			a.push(y);
		} else 
			if (x == 2) {
				printf("%d\n", a.top());
			} else {
				a.pop();
			}
	}
	return 0;
}