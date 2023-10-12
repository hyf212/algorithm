#include<bits/stdc++.h>

using namespace std;

const int base = 31;
const int p = 9999971;
int a[10001];
int Hash(char s[], int n) {
	int res = 0;
	for (int i = 1; i <= n; i++){
		res = (res * base + (s[i] - 'a' + 1)) % p;
		a[i] = res;
	}
		return res;
}
int CalcSubstringHash(int l, int r) {
	int t = a[l - 1] * pow(base, r - l + 1) % p;
	return (a[r] - t + p) % p;
}
int main(void) {
	char s[10001];
	int n;
	return 0;
}