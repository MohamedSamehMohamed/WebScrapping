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
int a[N], n;
void test()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", a+i);
  sort(a, a+n);
  long long ans = a[0];
  long long sub = 0; 
  for(int i = 0; i < n; i++)
  {
    ans = max(ans, 1LL * a[i] - sub); 
    sub += (1LL * a[i] - sub); 
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
