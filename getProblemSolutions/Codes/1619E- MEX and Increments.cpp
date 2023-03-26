#include <bits/stdc++.h>
using namespace std;
void read_file()
{
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif
}
const int N = 2e5 + 9;
int frq[N], n;
int can[N];
void test()
{
  scanf("%d", &n);
  for(int i = 0; i <= n; i++)frq[i] = 0, can[i] = 0; 
  for(int i = 0; i < n; i++)
  {
    int x;
    scanf("%d", &x); 
    frq[x]++;
  }
  int extra = 0;
  priority_queue<int> pq;
  bool bad = 0;
  long long sum = 0;
  for(int i = 0; i <= n; i++)
  {
    if (bad)
    {
      printf("-1 ");
      continue;
    }
    if (frq[i] + extra > 0)
    {
      printf("%lld ", sum + frq[i]);
      if (frq[i] == 0)
      {
        sum += i - pq.top();
        extra--;
        pq.pop();
      }
    }else 
    {
      printf("%lld ", sum);
      bad = 1;
    }
    while(frq[i] > 1)
    {
      pq.push(i);
      extra++;
      frq[i]--;
    }
  }
  printf("\n");
}
int main()
{
  read_file();
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}
