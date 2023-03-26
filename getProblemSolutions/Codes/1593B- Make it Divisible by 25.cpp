#include <bits/stdc++.h>
using namespace std;
char x[100];
int n;
void test()
{ 
  scanf(" %s", x);
  n = strlen(x);
  int num = (x[n-2] - '0') * 10 + (x[n-1] - '0'); 
  if (num % 25  == 0|| (x[n-1] == '0' && x[n-2] == '0'))
  {
    printf("0\n"); 
    return; 
  }
  int ans = 1e9;
  for(int i = n-1; i >= 0; i--)
  {
    for(int j = i-1; j >= 0; j--)
    {
      bool ok = 0;
      if (x[i] == '0' && x[j] == '0')
        ok = 1; 
      int num = (x[j] - '0') * 10 + (x[i] - '0'); 
      if (num % 25 == 0)
        ok = 1; 
      if (!ok)
        continue; 
      ans = min(ans, n - i - 1 + (i-j-1));
    }
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
