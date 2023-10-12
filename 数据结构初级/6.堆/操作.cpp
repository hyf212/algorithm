#include<bits/stdc++.h>
using namespace std;
const int Maxsize = 100000;
int len = 0;
int heap[Maxsize + 1];
//小根堆插入数据
void Insert(int x) {
	heap[++len] = x;
	Up(len);
}
void Up(int k) {
	while (k > 1 && heap[k] < heap[k / 2]) {
		swap(heap[k], heap[k / 2]);
		k /= 2;
	}
}
//删除数据
void Pop() {
	swap(heap[1], heap[len]);
	len--;
	Down(heap[1]);
}
void Down(int k) {
	while (k + k <= len) {
		int j = k + k;
		if (j + 1 <= len && heap[j + 1] < heap[j])
			j++;
		if (heap[k] <= heap[j])
			break;
		swap(heap[k], heap[j]);
		k = j;
	}
}
void Delete(int p) {
	if (p == len) {
		heap[p] = 0;
		len--;
		return;
	}
	int x = heap[p], y = heap[len];
	swap(heap[p], heap[len]);
	len--;
	if (y < x) {
		Up(p); // 队尾的数比原数小， 尝试上移
	} else {
		Down(p);// 队尾的数比原数大， 尝试下移
	}
}
int main(void) {
	Insert(2);
}