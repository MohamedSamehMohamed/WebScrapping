#include <bits/stdc++.h>
using namespace std;
void read_file()
{
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif
}
const int N = 2e5 + 9;
int l, r; 
int pre[N][26]; 
void test()
{
  scanf("%d%d", &l, &r);
  bool non = 0; 
  int mn = 1e9; 
  for(int i = 25; i >= 0; i--)
  {
    if (pre[r][i] - pre[l-1][i] == r - l + 1)
      non = 1; 
    else 
      mn = min(mn, (r - l + 1) - (pre[r][i] - pre[l-1][i]));
  }    
  if (non)
  {
    mn = 0;
  }
  printf("%d\n", mn);
}
int main()
{
  for(int i = 1; i < N; i++)
  {
    for(int j = 25; j >= 0; j--)
    {
      if (i & (1<<j))
        pre[i][j] = 1; 
      pre[i][j] += pre[i-1][j]; 
    }
  }
  read_file();
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}
