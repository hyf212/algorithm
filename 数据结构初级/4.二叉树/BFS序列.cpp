#include<bits/stdc++.h>

using namespace std;

const int N = 100001
struct TreeNode {
	int value;
	TreeNode *fa, *l, *r;
	TreeNode(int x) {
		value = x;
	}
} *q[N];
void Bfs(TreeNode *root) {
	int front = 1, rear = 1;
	q[1] = root;
	while (front <= rear) {
		TreeNode *p = q[front];
		front++;
		cout << p->value << endl;
		if (p->l)
			q[++rear] = p->l;
		if (p->r)
			q[++rear] = p->r;
	}
}
int main(void) {
	TreeNode *root = new TreeNode(1);
	Bfs(root);
}