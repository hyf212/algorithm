#include<bits/stdc++.h>

using namespace std;

struct Node {
	int value;
	Node *next;
} a[100001], b[100001];
Node *h1, *h2;
int n, m;
Node *Merge(Node *h1, Node *h2) {
	Node *p1 = h1, *p2 = h2, *p = NULL, *t = NULL;
	while (p1 || p2) {
		if (p1 && (p2 == NULL || p1->value < p2->value)) {
			if (p == NULL) {
				p = p1;
				t = p1;
			} else {
				t->next = p1;
				t = p1;
			}
			p1 = p1->next;
		} else {
			if(p == NULL) {
				p = p2;
				t = p2;
			} else {
				t->next = p2;
				t = p2;
			}
			p2 = p2->next;
		}
	}
	return p;
}
int main(void) {
	h1 = h2 = NULL;
	Node *t1 = NULL, *t2 = NULL;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i].value);
		if (h1 == NULL) {
			h1 = &a[i];
			t1 = &a[i];
		} else {
			t1->next = &a[i];
			t1 = &a[i];
		}
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d", &b[i].value);
		if (h2 == NULL) {
			h2 = &b[i];
			t2 = &b[i];
		} else {
			t2->next = &b[i];
			t2 = &b[i];
		}
	}
	Node *p = Merge(h1, h2);
	for (; p; p = p->next)
		printf("%d ", p->value);
	return 0;
}