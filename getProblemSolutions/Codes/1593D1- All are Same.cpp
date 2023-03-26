#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 9;
int n, k;
int a[N];
void test()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", a+i);
  sort(a, a+k);
  int g = 0;
  bool same = 1;
  for(int i = 1; i < n; i++)
    same &= (a[i] == a[i-1]); 
  for(int i = 1; i < n; i++)
    g = __gcd(g, abs(a[i] - a[i-1]));
  if (!same) 
    printf("%d\n", g);
  else 
    printf("-1\n");
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
