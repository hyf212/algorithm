#include<bits/stdc++.h>

using namespace std;
int top, n;
char s[100005], str[100005];
int main(void) {
	top = 0;
	scanf("%d", &n);
	getchar();
	scanf("%s", str) ;
	int len = strlen(str);
	for(int i = 0; i < len; i++) {
		if(top == 0) {
			s[++top] = str[i];
		} else{
		if(s[top] == str[i] - 32 || s[top] == str[i] + 32) {
			--top;
		}
		else {
			s[++top] = str[i];
		}
	}
	}
	s[++top] = '\0';
	printf("%s\n", &s[1]);
	return 0;
}