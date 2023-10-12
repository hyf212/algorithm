#include<bits/stdc++.h>

using namespace std;

struct Node {
	int value;
	Node *next;
	Node *prev;
};
void Insert(Node *p, Node *now) {
	now->next = p->next;
	p->next = now;
}
void Delete(Node *p, Node *now) {
	p->next = now->next;
	now->next = NULL;
}
int main(void) {
	Node *p1, *p2;
	Insert(p1, p2);
	Delete(p1, p2);
	return 0;
}