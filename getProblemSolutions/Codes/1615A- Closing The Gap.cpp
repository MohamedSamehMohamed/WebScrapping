#include <bits/stdc++.h>
using namespace std;
void read_file()
{
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif
}
int n;
long long sum;
void test()
{
  scanf("%d", &n);
  sum = 0;
  for(int i = 0; i < n; i++)
  { 
    int x;scanf("%d", &x); 
    sum += x; 
  } 
  printf("%d\n", (sum % n? 1: 0)); 
}
int main()
{
  read_file();
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}
