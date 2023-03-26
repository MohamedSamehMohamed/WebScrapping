#include <bits/stdc++.h>
using namespace std;
void read_file()
{
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif
}
const int N = 1e5 + 9;
int n;
char x[N], y[N];
int state[2][2];
void test()
{
  scanf("%d %s %s", &n, x, y); 
  memset(state, 0, sizeof state);
  for(int i = 0; i < n; i++)
  {
    state[x[i] - '0'][y[i] - '0']++; 
  }
  if (state[0][0] + state[1][1] == n)
  {
    printf("0\n");
    return;
  }
  if (state[1][0] + state[1][1] + state[0][1] == 0)
  {
    printf("-1\n");
    return;
  }
  queue<vector<int>> q; 
  map<vector<int>, bool> mp; 
  q.push({state[0][0], state[0][1], state[1][0], state[1][1], 0}); 
  while(!q.empty())
  {
    auto cur = q.front();
    q.pop(); 
    int steps = cur[4];
    state[0][0] = cur[0];
    state[0][1] = cur[1];
    state[1][0] = cur[2];
    state[1][1] = cur[3];
    if (state[0][0] + state[1][1] == n)
    {
      printf("%d\n", steps);
      return;
    }
    if (state[1][1])
    {
     swap(state[0][1], state[1][1]); 
     swap(state[0][0], state[1][0]); 
     state[1][1]++; 
     state[0][1]--; 
     if (mp.find({state[0][0], state[0][1], state[1][0], state[1][1]}) == mp.end())
     {
       mp[{state[0][0], state[0][1], state[1][0], state[1][1]}] = 1; 
       q.push({state[0][0], state[0][1], state[1][0], state[1][1], steps + 1}); 
     }
    }
    state[0][0] = cur[0];
    state[0][1] = cur[1];
    state[1][0] = cur[2];
    state[1][1] = cur[3];
    if (state[1][0])
    {
     swap(state[0][1], state[1][1]); 
     swap(state[0][0], state[1][0]); 
     state[1][0]++; 
     state[0][0]--; 
     if (mp.find({state[0][0], state[0][1], state[1][0], state[1][1]}) == mp.end())
     {
       mp[{state[0][0], state[0][1], state[1][0], state[1][1]}] = 1; 
       q.push({state[0][0], state[0][1], state[1][0], state[1][1], steps + 1}); 
     }
    }
 
  }
  printf("-1\n"); 
}
int main()
{
  read_file();
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}
