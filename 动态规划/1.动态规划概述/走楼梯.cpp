#include<bits/stdc++.h>

using namespace std;

int n;
long long a[51];
int main(void) {
	scanf("%d", &n);
	a[1] = 1;
	a[2] = 2;
	for (int i = 3; i <= n; i++)
		a[i] = a[i - 1] + a[i - 2];
	printf("%lld", a[n]);
	return 0;
}