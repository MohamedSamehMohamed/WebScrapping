#include <bits/stdc++.h>
using namespace std;
const int N = 41; 
int n, oa, ob;
char x[100]; 
int dp[N][N][N][N];
int vis[N][N][N][N], vid; 
int solve(int i = 0, int r = 0, int b = 0, int A = 0, int B = 0)
{
  A %= oa; 
  B %= ob; 
  if (i == n)
  {
    if (A == 0 && B == 0)
      return min(r, b) > 0? abs(r - b): 1e8; 
    return 1e8; 
  }
  int &ret = dp[i][r][A][B];
  if (vis[i][r][A][B] == vid)
    return ret; 
  vis[i][r][A][B] = vid; 
  int dig = x[i] - '0';
  int p1 = solve(i+1, r + 1, b, A * 10 + dig, B); 
  int p2 = solve(i+1, r, b + 1, A, B * 10 + dig); 
  return ret = min(p1, p2); 
} 
void build(int i = 0, int r = 0, int b = 0, int A = 0, int B = 0)
{
  A %= oa; 
  B %= ob; 
  if (i == n)
  {
    return;
  }
  int ret = dp[i][r][A][B];
  int dig = x[i] - '0';
  int p1 = solve(i+1, r + 1, b, A * 10 + dig, B); 
  int p2 = solve(i+1, r, b + 1, A, B * 10 + dig); 
  if (ret == p1)
  {
    printf("R");
    build(i+1, r + 1, b, A * 10 + dig, B);
  } else 
  {
    printf("B"); 
    build(i+1, r, b + 1, A, B * 10 + dig);
  }
} 
void test()
{
  scanf("%d%d%d %s", &n, &oa, &ob, x);
  vid++;
  int ans = solve();
  if (ans < (int)1e8)
  {
    build();
  }else 
  printf("-1"); 
  printf("\n"); 
}
int main()
{
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif
 
  int t;
  scanf("%d", &t);
  while(t--)
    test(); 
}   
