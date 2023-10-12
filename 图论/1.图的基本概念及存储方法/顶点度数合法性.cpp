#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
	scanf("%d", &n);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		ans += x;
	}
	if(ans & 1)
		printf("No\n");
	else
		printf("Yes\n");
	return 0;	
}