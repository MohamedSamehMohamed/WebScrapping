#include <bits/stdc++.h>
using namespace std;
void read_file()
{
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif
}
int n;
void test()
{
  scanf("%d", &n);
  long long cur = 1; 
  long long ans = 0;
  for(int i = 0; i < n; i++)
  {
    int x;scanf("%d", &x);
    if (x <= cur)
    {
      cur++;continue; 
    }else 
    {
      ans += x - cur; 
      cur = x + 1; 
    }
  }
  printf("%lld\n", ans); 
}
int main()
{
  read_file();
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}
