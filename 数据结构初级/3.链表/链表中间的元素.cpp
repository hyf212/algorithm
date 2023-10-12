#include<bits/stdc++.h>

using namespace std;

struct Node {
	int value;
	Node *next;
} a[100001];
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
	Node *p = head, *t = head;
	while(t->next) {
		if(t == head) {
			t = t->next;
		} else{
		p = p->next;
		t = t->next->next;
		}
	}
	printf("%d", p->value);
	return 0;
		
}