#include <bits/stdc++.h>
using namespace std;
int a, b, c;
void test()
{
  scanf("%d%d%d", &a, &b, &c);
  if ((a + c) % 2==0)
    printf("0\n"); 
  else 
    printf("1\n");
}
int main()
{
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif
  int t;
  scanf("%d", &t);
  while (t--)
  {
    test();
  }
}
