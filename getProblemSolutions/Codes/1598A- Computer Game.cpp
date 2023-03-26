#include <bits/stdc++.h>
using namespace std;
int n; 
char x[102];
char y[102];
void test()
{
  scanf("%d %s %s", &n, x, y);
  bool ok = 1;
  for(int i = 0; i < n; i++)
  {
    if (x[i] == '1' && y[i] == '1')
      ok = 0;
  }
  if (ok)
    printf("Yes\n"); 
  else 
    printf("No\n");
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
