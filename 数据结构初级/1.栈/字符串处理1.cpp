#include<bits/stdc++.h>

using namespace std;

int n, top = 0;
char s[100001], str[100001];
int main(void) {
	scanf("%d", &n);
	scanf("%s", str);
	for (int i = 0; i < n; i++) {
		if (top && str[i] == s[top])
			--top;
		else
			s[++top] = str[i];
	}
	for (int i = 1; i <= top; i++)
		printf("%c", s[i]);
	return 0;
}