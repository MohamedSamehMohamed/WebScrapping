#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 9;
int n, k;
set<int> adj[N];
int vis[N]; 
void test()
{
  scanf("%d%d", &n, &k);
  for(int i = 0; i < n; i++)
  {
    adj[i].clear();
    vis[i] = 0;
  }
  for(int i = 0; i < n-1; i++)
  {
    int u, v;
    scanf("%d%d", &u, &v);
    u--;v--;
    adj[u].insert(v);
    adj[v].insert(u);
  }
  set<int> leaves; 
  for(int i = 0; i < n; i++)
    if (adj[i].size() <= 1)
      leaves.insert(i);
  while (k > 0 && leaves.size() > 0)
  {
    set<int> new_leaves; 
    for(auto& i: leaves)
    {
      vis[i] = 1; 
      if (adj[i].size() == 0)continue; 
      int p = *adj[i].begin();
      adj[p].erase(i);
      if (adj[p].size() <= 1)
        new_leaves.insert(p); 
    }
    k--; 
    leaves.clear();
    leaves = new_leaves; 
  }
  
  int ans = count(vis, vis + n, 0);
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
