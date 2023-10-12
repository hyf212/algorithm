/*#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
	int l, r, fa;
} a[1025];
int n;
//先序遍历
inline void preorder(int t) {
	printf("%d ", t);
	if (a[t].l)
		preorder(a[t].l);
	if (a[t].r)
		preorder(a[t].r);
}
//中序遍历
inline void inorder(int t) {
	if (a[t].l)
		inorder(a[t].l);
	printf("%d ", t);
	if (a[t].r)
		inorder(a[t].r);
}
//后序遍历
inline void posorder(int t) {
	if (a[t].l)
		posorder(a[t].l);
	if (a[t].r)
		posorder(a[t].r);
	printf("%d ", t);
}
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (x)
			a[i].l = x, a[x].fa = i;
		if (y)
			a[i].r = y, a[y].fa = i;
	}
	preorder(1);
	printf("\n");
	inorder(1);
	printf("\n");
	posorder(1);
	return 0;
}*/
#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
	int value;
	TreeNode *fa, *l, *r;
} a[1025];
//先序遍历
inline void preorder(TreeNode *t) {
	printf("%d ", t->value);
	if (t->l)
		preorder(t->l);
	if (t->r)
		preorder(t->r);
}
//中序遍历
inline void inorder(TreeNode *t) {
	if (t->l)
		inorder(t->l);
	printf("%d ", t->value);
	if (t->r)
		inorder(t->r);
}
//后序遍历
inline void posorder(TreeNode *t) {
	if (t->l)
		posorder(t->l);
	if (t->r)
		posorder(t->r);
	printf("%d ", t->value);
}
int n;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		a[i].value = i;
		if (x)
			a[i].l = &a[x], a[x].fa = &a[i];
		if (y)
			a[i].r = &a[y], a[x].fa = &a[i];
	}
	preorder(&a[1]);
	printf("\n");
	inorder(&a[1]);
	printf("\n");
	posorder(&a[1]);
	return 0;
}