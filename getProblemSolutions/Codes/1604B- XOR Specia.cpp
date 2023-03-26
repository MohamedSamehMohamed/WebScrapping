#include <bits/stdc++.h>
using namespace std;
void read_file()
{
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif
}
const int N = 1e5 + 9; 
int a[N], n;
void test()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", a+i);
  bool ok = 0;
  for(int i = 0; i + 1 < n; i++)
  {
    if (a[i] >= a[i+1])ok = 1; 
  }
  if (n % 2 == 0 || ok)
  {
    printf("YES\n");
  }else 
  {
    printf("NO\n");     
  }
 
}
int main()
{
  read_file();
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}
