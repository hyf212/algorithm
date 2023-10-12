#include<bits/stdc++.h>

using namespace std;

struct Node {
	int value;
	Node *next, *prev;
} a[101], *head, *tail;
int n, m;
int main(void) {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		a[i].value = i;
		if (head == NULL) {
			head = &a[i];
			tail = &a[i];
		} else {
			tail->next = &a[i];
			a[i].prev = tail;
			tail = &a[i];
		}
	}
	tail->next = head;
	head->prev = tail;
	Node *p = tail;
	int c = 0;
	while (true) {
		p = p->next;
		c++;
		if (c == m) {
			printf("%d ", p->value);
			c = 0;
			if (p == p->next)
				break;
			Node *x = p->prev, *y = p->next;
			x->next = y;
			y->prev = x;
		}
	}
	return 0;
}
