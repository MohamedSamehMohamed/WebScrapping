#include <bits/stdc++.h>
using namespace std; 
vector<int> get_divisors(int x)
{
  vector<int> ret;
  for(int i = 1; i <= x/i; i++)
  {
    if (x % i == 0)
    {
      ret.push_back(i);
      if (i != x/i)
        ret.push_back(x/i);
    }
  }
  return ret; 
}
void test()
{
  int n;
  scanf("%d", &n);
  vector<int> v(n);
  for(int i = 0; i < n; i++)
    scanf("%d", &v[i]);
  sort(v.begin(), v.end());
  int shift = v[0] < 0? -v[0]: 0;
  for(int i = 0; i < n; i++)
    v[i] += shift; 
  int longest = 0;
  for(int i = 0; i < n; i++)
  {
    int j = i+1;
    while(j < n && v[i] == v[j])
      j++;
    longest = max(longest, j - i);
    i = j-1;
  }
  if (longest >= n/2)
  {
    printf("-1\n");
    return;
  }
  int ans = 0;
  for(int i = 0; i < n; i++)
  {
    int j = i+1;
    while(j < n && v[j] == v[i])
      j++; 
    int same = j - i;
    int me = v[i];  
    i = j-1; 
    map<int, int> divs; 
    for(; j < n; j++)
    {
      auto ret = get_divisors(v[j] - me);
      for(int d: ret)
        divs[d]++; 
    }
    for(auto cur: divs)
      if (cur.second + same >= n/2)
        ans = max(ans, cur.first); 
    
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
