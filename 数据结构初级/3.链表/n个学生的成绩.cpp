#include<bits/stdc++.h>

using namespace std;

struct Node {
	int value;
	Node *next;
} a[1001];
Node *head = NULL, *tail = NULL;
int n;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i].value);
		if (head == NULL) {
			head = &a[i];
			tail = &a[i];
		} else {
			tail->next = &a[i];
			tail = &a[i];
		}
	}
	Node *a = head, *b = a->next, *c;
	a->next = NULL;
	while (b) {
		c = b->next;
		b->next = a;
		a = b;
		b = c;
	}
	head = a;
	for (Node *p = head; p; p = p->next)
		printf("%d\n", p->value);
	return 0;
}