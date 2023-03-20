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
int n, P[N];
vector<int> adj[N];
vector<vector<int>> answer;
vector<int> temp;
int lst;
vector<vector<int>> pairs;
void dfs(int u, int id)
{
  pairs.push_back({id, u});
  bool f = 1;
  for(int& v: adj[u])
  {
    if (f)
      dfs(v, id);
    else 
      dfs(v, lst++);
    f = 0;
  }
}
void test()
{
  scanf("%d", &n);
  for(int i = 1; i <= n; i++)
    scanf("%d", P + i);
  for(int i = 1; i <= n; i++)
    adj[i].clear();
  int root = -1;
  for(int i = 1; i <= n; i++)
  {
    int u, v;
    u = P[i];
    v = i;
    if (u == v)
      root = u;
    else 
      adj[u].push_back(v);
  }
  answer.clear();
  pairs.clear();
  lst = 1;
  dfs(root, 0);
  answer = vector<vector<int>>(lst);
  for(int i = 0; i < pairs.size(); i++)
  {
    answer[pairs[i][0]].push_back(pairs[i][1]);
  }
  printf("%d\n", (int)answer.size());
  for(auto i: answer)
  {
    printf("%d\n", (int)i.size());
    for(int j: i)
      printf("%d ", j);
    printf("\n");
  }
  
}
int main()
{
  read_file();
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}
