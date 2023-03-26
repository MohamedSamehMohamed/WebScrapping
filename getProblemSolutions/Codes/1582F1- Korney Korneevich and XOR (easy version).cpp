#include <bits/stdc++.h>
using namespace std;
int n;
int dp[1<<10][2];
void test()
{
  scanf("%d", &n);
  int p = 0;
  for(int i = 0; i < (1<<10); i++)dp[i][0] = dp[i][1] = 501; 
  dp[0][p] = 0; 
  for(int i = 0; i < n; i++)
  {
    int x;scanf("%d", &x);
    p^= 1; 
    for(int j = 0; j < (1<<10); j++)
      dp[j][p] = dp[j][p^1]; 
    for(int j = 0; j < (1<<10); j++)
      if (dp[j][p^1] < x)
        dp[j^x][p] = min(dp[j^x][p], x); 
  }
 
  vector<int> ans; 
  for(int i = 0; i < (1<<10); i++)
    if (dp[i][p] < 501)
      ans.push_back(i); 
  printf("%d\n", (int)ans.size());
  for(int i: ans)printf("%d ", i);
  printf("\n");
}
int main()
{
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif
  test();
}
