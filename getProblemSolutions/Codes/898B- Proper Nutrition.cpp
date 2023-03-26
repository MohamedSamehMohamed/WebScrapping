#include <bits/stdc++.h>
using namespace std;
void read_file(){
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif
}
long long n, a, b;
int main()
{
  read_file(); 
  scanf("%lld%lld%lld", &n, &a, &b); 
  for(long long i = 0; i <= (int)1e7; i++)
  {
    long long cur = n - 1LL * i * a; 
    if (cur >= 0 && cur % b == 0)
    {
      printf("YES\n%lld %lld\n", i, cur / b); 
      return 0;
    }
  }  
  printf("NO\n");
}
