#include<bits/stdc++.h>

using namespace std;

const int N = 10001;
const int M = 10001;
struct Node {
	int where;
	Node *next;
} *head[N + 1], a[M];
int n, father[N + 1], l = 0;
void addedge(int x, int y) {
	a[++l].where = y;
	a[l].next = head[x];
	head[x] = &a[l];
}
int main(void) {
	for (Node *p = head[x]; p; p = p->next) {
		p->where;
		....
	}
}