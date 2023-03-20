#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int n, a[N];
void test()
{
 scanf("%d", &n);
 for (int i = 0; i < n; i++)
   scanf("%d", a+i);
 long long s1, s2;
 s1 = 0;
 s2 = a[0];
 for (int i = 1; i < n; i++)
 {
  int d = a[i] - a[i-1];
  s1 += abs(d);
  if (d < 0)
   s2 += d;
 }
 s1 += abs(s2);
 printf("%lld\n", s1);
}
int main()
{
 int t;
 scanf("%d", &t);
 while(t--)
   test();
}
