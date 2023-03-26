#include <bits/stdc++.h>
using namespace std;
void read_file()
{
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif
}
int a, b, c, x, y;
void test()
{
  scanf("%d%d%d%d%d", &a, &b, &c, &x, &y);
  int needx = max(0, x - a);
  int needy = max(0, y - b);
  if (needx + needy <= c)
    printf("Yes\n");
  else 
    printf("No\n");
}
int main()
{
  read_file();
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}
