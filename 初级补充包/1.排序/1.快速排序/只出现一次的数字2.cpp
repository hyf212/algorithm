#include<bits/stdc++.h>

using namespace std;

int n, a[1000001];
stack<int> s;
bool cmp(int x, int y) {
	return x > y;
}
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		if (s.empty())
			s.push(a[i]);
		else {
			if (a[i] == s.top())
				s.pop();
			else
				s.push(a[i]);
		}
	}
	while (!s.empty()) {
		printf("%d ", s.top());
		s.pop();
	}
	return 0;
}