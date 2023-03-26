#include <bits/stdc++.h>
using namespace std;
void read_file()
{
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif
}
vector<long long> v; 
void test()
{
  int n;
  scanf("%d", &n);
  int ans = 0;
  for(int i = 0; i < v.size(); i++)
  {
    if (v[i] > n)break;
    ans++; 
  }
  printf("%d\n", ans);
}
int main()
{
  set<long long> ss;
  int lim = 1e9; 
  for(int i = 1; i <= lim / i; i++)
  {
    ss.insert(1LL * i * i);
  }
  for (long long i = 1; 1LL * i * i * i <= lim; i++)
    ss.insert(1LL * i * i * i);
  for(auto i: ss)v.push_back(i);
  read_file();
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}
