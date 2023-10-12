#include<bits/stdc++.h>

using namespace std;

const int modnum = 11;
vector<int> HashTable[modnum];
void Hash(int x) {
	return x % modnum;
}
//插入新值
void Insert(int x) {
	int addr = Hash(x);
	HashTable[addr].push_back(x);
}
//查找元素
bool IsExist(int x) {
	int addr;
	int l = HashTable[addr].size();
	for (int i = 0; i < l; i++) {
		if (HashTable[addr][i] == x)
			return true;
	}
	return false;
}
int main(void) {
	Insert(...);
}