#include <bits/stdc++.h>
using namespace std;
int n; 
set<int> a[5];
bool solve(int d1, int d2)
{
  set<int> a1 = a[d1];
  set<int> a2 = a[d2];
  vector<int> common; 
  for(int i: a1)
  {
    if (a2.find(i) != a2.end())
    {
      common.push_back(i);
    }
  }
  for(int i: common)
  {
    a1.erase(i);
    a2.erase(i); 
  }
  int s1 = a1.size(), s2 = a2.size(), extra = common.size();
  while (min(s1, s2) < n && extra > 0)
  {
    if (s1 <= s2)
      s1++;
    else 
      s2++;
    extra--; 
  }
  return min(s1, s2) >= n; 
}
void test()
{
  scanf("%d", &n);
  for(int i = 0; i < 5; i++)
    a[i].clear(); 
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < 5; j++)
    {
      int x;scanf("%d", &x);
      if (x)
        a[j].insert(i); 
    }
  }
  bool can = 0;
  n >>= 1; 
  for(int i = 0; i < 5; i++)
    for(int j = i+1; !can && j < 5; j++)
    {
      if (a[i].size() >= n && a[j].size() >= n)
      {
        if (solve(i, j))
        {
          can = 1;
          break; 
        }
      }
    }
  if (can)
    printf("Yes\n"); 
  else 
    printf("No\n"); 
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
