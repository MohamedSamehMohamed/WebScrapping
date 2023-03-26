#include <bits/stdc++.h>
using namespace std;
void read_file()
{
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif
}
const int N = 1e3 + 8;
int n;
void test()
{
  scanf("%d", &n);
  set<vector<int>> st;
  for(int i = 0; i < n; i++)
  {
    int l, r;
    scanf("%d%d", &l, &r);
    st.insert({l, r});
  }
  queue<vector<int>> q;
  q.push({1, n}); 
  vector<vector<int>> ans;
  while(!q.empty())
  {
    auto cur = q.front();
    q.pop();
    for(int i = cur[0]; i <= cur[1]; i++)
    {
      vector<vector<int>> take; 
      if (i - 1 >= cur[0])
        take.push_back({cur[0], i - 1});
      if (i + 1 <= cur[1])
        take.push_back({i + 1, cur[1]}); 
      bool ok = 1;
      for(auto j: take)
      {
        if (st.find(j) == st.end())
        {
          ok = 0;
          break;
        }
      }
      if (ok)
      {
        for(auto j: take)
          q.push(j);
        ans.push_back({cur[0], cur[1], i});
        st.erase(cur);
        break;
      }
    }
  }
  for(auto i: ans)
    printf("%d %d %d\n", i[0], i[1], i[2]); 
}
int main()
{
  read_file();
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}
