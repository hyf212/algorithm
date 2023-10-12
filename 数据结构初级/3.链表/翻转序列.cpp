#include<bits/stdc++.h>

using namespace std;

struct Node {
	int value;
	Node *next, *prev;
} a[2001], *head, *tail;
int n, m;
int main(void) {
	head = tail = NULL;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
		a[i].value = i;
		if(head == NULL) {
			head = tail = &a[i];
		}
		else {
			tail->next = &a[i];
			a[i].prev = tail;
			tail = &a[i];
		}
	}
	for(int i = 1; i <= m; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		if(l == r)
			continue;
		Node *pl = head, *pr = head;
		for(int j = 1; j < l; j++)
			pl = pl->next;
		for(int j = 1; j < r; j++)
			pr = pr->next;
		Node *x = pl, *y = x->next, *z, *u = pr->next, *v = pl->prev;
		while(x != pr) {
			z = y->next;
			y->next = x;
			x->prev = y;
			x = y;
			y = z;
		}
		if(head == pl) {
			head = pr;
			pr->prev = NULL;
		}
		else {
			Node *p = v;
			p->next = pr;
			pr->prev = p;
		}
		if(tail == pr) {
			tail = pl;
			pl->next = NULL;
		}
		else {
			Node *p = u;
			p->prev = pl;
			pl->next = p;
		}
	}
	for(Node *p = head; p; p = p->next)
		printf("%d ",p->value);
	return 0;
}