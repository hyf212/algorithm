#include<iostream>
#include<string>
using namespace std;
int top, s[100001], m;
string str;
int main()
{
	cin >> m;
	top = 0;
	for (int i = 1; i <= m; i++) {
		cin >> str;
		if (str[2] == 's') {
			int x;
			cin >> x;
			s[++top] = x;
		}
		else if (str[0] == 'p') {
			--top;
		}
		else {
			int k;
			cin>>k;
			cout << s[top+1-k] << endl;
		}
	}
	return 0;

}