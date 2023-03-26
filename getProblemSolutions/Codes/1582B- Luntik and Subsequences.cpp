#include <bits/stdc++.h>
using namespace std;
long long dp[60][2]; 
int a[60], n;
long long solve(int i = 0, int cur = 0)
{
  if (i == n)
    return cur == 1; 
  if (cur > 1)return 0;
  long long& ret = dp[i][cur];
  if (~ret)return ret; 
  return ret = solve(i+1, cur) + solve(i+1, cur + a[i]); 
}
void test()
{
  memset(dp, -1, sizeof dp);
  scanf("%d", &n);
  for(int i = 0; i < n; i++)scanf("%d", a+i); 
  printf("%lld\n", solve());
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
