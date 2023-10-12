#include<bits/stdc++.h>

using namespace std;

const int maxn = 100010;
const int charsize = 26;//字符集大小
struct TreeNode {
	int nxt[charsize];
	bool isend;
} tree[maxn + 1];
//字符集较大时
struct TreeNode {
	unordered_map<char, int> nxt_map;
	bool isend;
} tree[maxn + 1];
//指针
struct TreeNode {
	TreeNode *nxt[charsize];
	bool isend;
} *root;
//记录该节点的子节点编号
//这里默认全为小写字母
int nxt[maxn + 1][charsize];

//表示该编号节点是否为终止节点
bool isend[maxn + 1];

//cnt 存储当前的节点编号
int root = 0, cnt = 0;
//s为等待插入的字符串，下标从1开始，len为字符串长度
void insret(char s[], int len) {
	int now = 0;
	for (int i = 1; i <= len; i++) {
		int x = s[i] - 'a';
		if (!nxt[now][x]) {
			nxt[now][x] = ++cnt;
		}
		now = nxt[now][x];
	}
	isend[now] = 1;
}
//s为等待查找的字符串，下标从1开始，len为字符串长度
bool search (char s[], int len) {
	int now = 0;
	for now = 0;
	for (int i = 1; i <= len; i++) {
		int x = s[i] - 'a';
		if (!nxt[now][x]) {
			return false;
		}
		now = nxt[now][x];
	}
	return isend[now];
}
int main(void) {
	.....
}