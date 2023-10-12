#include<bits/stdc++.h>

using namespace std;

int n, top = 0;
char s[100001], str[100001];
int main(void) {
	scanf("%d", &n);
	scanf("%s", str);
	bool ok = true;
	for (int i = 0; i < n && ok; i++) {
		if (str[i] == '[' || str[i] == '(')
			s[++top] = str[i];
		else
			if (str[i] == ']')
				if (s[top] == '[')
					--top;
				else
					ok = false;
		else
			if (str[i] == ')')
				if (s[top] == '(')
					--top;
				else
					ok = false;
	}
	if (top)
		ok = false;
	if (ok)
		printf("Yes");
	else
		printf("No");
	return 0;
}