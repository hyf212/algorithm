#include<bits/stdc++.h>

using namespace std;

struct Node {
	int value;
	Node *next;
} a[81];
Node *head = NULL;
int n;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		a[i].value = x;
		if (head == NULL || head->value >= a[i].value) {
			a[i].next = head;
			head = &a[i];
		} else {
			for (Node *p = head; p; p = p->next) {
				if (p->value < a[i].value && (p->next == NULL) || a[i].value <= p->next->value) {
					a[i].next = p->next;
					p->next = &a[i];
					break;
				}
			}
		}
		
	}
	for (Node *p = head; p; p = p->next)
		printf("%d ", p->value);
	return 0;
}