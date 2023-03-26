#include <bits/stdc++.h>
using namespace std;
void read_file()
{
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif
}
const int N = 30; 
char a[N], s[N]; 
int n, m;
void test()
{
  
  scanf(" %s %s", a, s);
  m = strlen(a);
  n = strlen(s); 
  string out = "";
  int j = n-1; 
  bool ok = 1;
  for(int i = m-1; i >= 0; i--)
  {
    int d1 = a[i] - '0';
    int sum = s[j] - '0';
    if (sum - d1 < 0 || sum - d1 > 9)
    {
      j--;
      if (j < 0)
      {
        ok = 0;break;
      }
      sum += 10 * (s[j] - '0'); 
    }
    if (sum - d1 >= 0 && sum - d1 <= 9)
    {
      out += (sum - d1) + '0'; 
    }else 
    {
     ok = 0;
     break;
    }
    j--; 
  }
  if (!ok)
  {
    printf("-1\n"); 
    return;
  }
  while(j >= 0)
  {
    out += s[j];
    j--; 
  }
  while(out.back() == '0')
    out.pop_back();
  reverse(out.begin(), out.end()); 
  printf("%s\n", out.c_str()); 
  
}
int main()
{
  read_file();
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}
