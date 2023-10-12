//#include<bits/stdc++.h>
//
//using namespace std;
//int n, s[200001], a[200001], ans[2000001], top;
//int main(void) {
//	top = 0;
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//		scanf("%d", &a[i]);
//	for (int i = 1; i <= n; i++) {
//		while (top && a[i] > a[s[top]]) {
//			ans[s[top--]] = i;
//		}
//		s[++top] = i;
//	}
//	for (int i = 1; i <= top; i++)
//		ans[s[i]] = 0;
//	for (int i = 1; i <= n; i++)
//		printf("%d ", ans[i]);
//	printf("\n");
//	return 0;
//}
#include<bits/stdc++.h>

using namespace std;
int n, s[200001], a[200001], ans[200001], top;
int main(void) {
	top = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = n; i > 0; i--) {
		while (top && a[i] >= a[s[top]]) {
			--top;
		}
		if (top)
			ans[i] = s[top];
		else
			ans[i] = 0;
		s[++top] = i;
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}