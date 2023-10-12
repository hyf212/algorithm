#include <iostream>
#include <math.h>
using namespace std;
bool check(int x) {
  bool ok = true;
  for (int i = 2; i <= sqrt(x) && ok; i++)
    if (x % i == 0)
      ok = false;
  return ok;
}
int main()
{
  // 请在此输入您的代码
  int cnt = 0;
  int i = 1;
  while (true) {
    i++;
    if (check(i))
      cnt++;
    if (cnt == 2019) {
      printf("%d", i);
      break;
    }
  }
  return 0;
}