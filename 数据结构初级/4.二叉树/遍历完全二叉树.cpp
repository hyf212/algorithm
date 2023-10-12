#include<bits/stdc++.h>

using namespace std;

int n;
//先序遍历
inline void preorder(int t) {
	printf("%d ", t);
	if (t + t <= n)
		preorder(t + t);
	if (t + t + 1 <= n)
		preorder(t + t + 1);
}
//中序遍历
inline void inorder(int t) {
	if (t + t <= n)
		inorder(t + t);
	printf("%d ", t);
	if (t + t + 1 <= n)
		inorder(t + t + 1);
}
//后序遍历
inline void posorder(int t) {
	if (t + t <= n)
		posorder(t + t);
	if (t + t + 1 <= n)
		posorder(t + t + 1);
	printf("%d ", t);
}


int main(void) {
	scanf("%d", &n);
	preorder(1);
	printf("\n");
	inorder(1);
	printf("\n");
	posorder(1);
	return 0;
}