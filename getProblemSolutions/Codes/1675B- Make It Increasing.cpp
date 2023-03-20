#include <bits/stdc++.h>
using namespace std;
void read_file()
{
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif
}
const int N = 44;
int n, a[N];
void test()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", a+i);
  int answer = 0;
  bool can = 1;
  for(int i = n-2; i >= 0; i--)
  {
    while(a[i] && a[i] >= a[i+1])
    {
      answer++;
      a[i] /= 2;
    }
    if (a[i] >= a[i+1])
    {
      can = 0;break;
    }
  }
  if (!can)
    answer = -1;
  printf("%d\n", answer);
}
int main()
{
  read_file();
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}
