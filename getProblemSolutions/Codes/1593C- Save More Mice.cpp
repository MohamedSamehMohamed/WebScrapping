#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 9;
int n, k, a[N];
bool can(int skip)
{
  int cat_pos = 0;
  for(int i = k-skip; i < k; i++)
  {
    if (cat_pos >= a[i])return 0;
    cat_pos += n - a[i];
  }
  return 1; 
}
void test()
{
  scanf("%d%d", &n, &k);
  for(int i = 0; i < k; i++)
    scanf("%d", a+i);
  sort(a, a+k);
  int l = 1, r = k, m, ans = 1;
  while(l <= r)
  {
    m = (l+r) >> 1;
    if (can(m))
      ans = m, l = m+1;
    else 
      r = m-1;
  }
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
  while(t--)
    test(); 
}   
