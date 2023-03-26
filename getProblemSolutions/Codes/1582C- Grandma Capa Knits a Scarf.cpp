#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9; 
char x[N];
int n;
int solve(int del)
{
  int l = 0, r = n-1, ret = 0;
  while(l <= r)
  {
    if (x[l] == x[r])
    {
      l++;r--;
    }else if (x[l] - 'a'== del)
      l++, ret++;
    else if (x[r]-'a' == del)
      r--, ret++;
    else 
      return n+1; 
  }
  return ret; 
}
void test()
{
  scanf("%d %s", &n, x); 
  int ans = 2 * n;
  for(int i = 0; i < 26; i++)
  {
    int cur = solve(i);
    if (cur <= n)
    {
      ans = min(ans, cur);
    } 
  }
  if (ans == 2 * n) ans = -1;
  printf("%d\n", ans); 
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
