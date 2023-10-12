#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
	scanf("%d", &n);
	printf("%lld", 1LL << (n * (n - 1)) / 2);
	return 0;
} 