#include<bits/stdc++.h>

using namespace std;

struct Node {
	int value;
	Node *next, *prev;
} a[10001];
void Insert(Node *p, Node *now) {
	Node *q = p->next;
	p->next = now;
	now->next = p;
	now->next = q;
	q->prev = now;
}
void Delete(Node *now) {
	Node *p = now->prev, *q = now->next;
	p->next = q;
	q->prev = p;
}
int main(void) {
	return 0;
}