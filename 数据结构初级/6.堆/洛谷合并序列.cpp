#include<bits/stdc++.h>

using namespace std;
priority_queue<string, vector<string>, greater<string> > p;
int n;
string k, m, b;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		cin >> k;
		p.push(k);
	}
	cin >> m;
	for (int i = 1; i <= n; i++) {
		b = p.top();
		int cnt = 0;
		for (int j = 0; j < m.size(); j++)
			if (m[j] == b[j])
				cnt++;
		if (cnt == m.size())
			cout << p.top() << endl;
		p.pop();
	}
	return 0;
}