#include <bits/stdc++.h>
using namespace std;
void read_file()
{
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif
}
int n, m, r1, r2, c1, c2;
void test()
{
  scanf("%d%d%d%d%d%d", &n, &m, &r1, &c1, &r2, &c2); 
  int ans = 0;
  int dr, dc;
  dr = dc = 1;
  while(r1 != r2 && c1 != c2)
  {
    if (r1 + dr > n || r1 + dr < 1)
      dr *= -1; 
    if (c1 + dc > m || c1 + dc < 1)
      dc *= -1; 
    r1 += dr;
    c1 += dc; 
    ans++;
  }
  printf("%d\n", ans);
}
int main()
{
  read_file();
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}
