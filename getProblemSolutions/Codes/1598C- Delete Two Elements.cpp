#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9; 
int n; 
int a[N];
void test()
{
  scanf("%d", &n);
  map<int, int> mp;
  long long sum = 0;
  long long ans = 0;
  for(int i = 0; i < n; i++)
  {
    scanf("%d", a+i); 
    mp[a[i]]++; 
    sum += a[i]; 
  }
  // (s1 * (n-2)) / n == s2
  // (s1 * n - s1 * 2)/n
  // (s1-s1*2/n)
  if ((sum * 2) % n)
  {
    printf("0\n");
    return;
  }
  long long s2 = (sum * 2)/n;
  for(int i = 0; i < n; i++)
  {
    mp[a[i]]--;
    ans += mp[s2 - a[i]]; 
  }
  printf("%lld\n", ans);
 
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
 
 
/*
(x + y + z + a + b) / 5 = (x + y + z) / 3 
s1 / n = s2 / (n-2)
 
sum1 / sum2 = (n-2) / n 
(sum1 * n) / sum2 = n-2 
 
*/
