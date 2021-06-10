#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 9;
int st[N], en[N], tour[N], ti, n, m; 
vector<int> adj[N];
int seg[4*N], lazy[4*N], sum[4*N], laz[4*N], par[N], colr[N]; 
void push_down(int node)
{
 if (laz[node] != -1)
 {
  int n1 = node * 2 + 1;
  int n2 = n1 + 1; 
  sum[n1] = laz[node];
  sum[n2] = laz[node];
  laz[n1] = laz[n2] = laz[node]; 
  laz[node] = -1; 
 }
}
void push_down(int node, int l, int r)
{
 if (lazy[node] != -1)
 {
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  int m = (l+r)>>1;
  int lsz =  m-l+1;
  int rsz = r - m; 
  seg[n1] = lsz * lazy[node];
  seg[n2] = rsz * lazy[node];
  lazy[n1] = lazy[n2] = lazy[node];
  lazy[node] = -1; 
 }
}
void build(int node = 0, int l = 0, int r = ti-1)
{
  if (l == r)
  {
   seg[node] = colr[tour[l]];
   lazy[node] = laz[node] = -1;  
   return; 
  }
  int m = (l+r)>>1;
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  build(n1, l, m);
  build(n2, m+1, r);
  seg[node] = seg[n1] + seg[n2];  
  lazy[node] = laz[node] = -1;
}
void update(int le, int re, int val, int node = 0, int l = 0, int r = ti-1)
{
 if (l > re || r < le)
  return; 
 if (l >= le && r <= re)
 {
  seg[node] = val * (r-l+1);
  lazy[node] = val;
  return; 
 }
 push_down(node, l, r); 
 int m = (l+r)>>1;
 int n1 = node * 2 + 1; 
 int n2 = n1 + 1; 
 update(le, re, val, n1, l, m);
 update(le, re, val, n2, m+1, r);
 seg[node] = seg[n1] + seg[n2]; 
}
int query(int le, int re, int node = 0, int l = 0, int r = ti-1)
{
 if (l > re || r < le)
  return 0; 
 if (l >= le && r <= re)
 {
  return seg[node];  
 } 
 push_down(node, l, r);
 int m = (l+r)>>1;
 int n1 = node * 2 + 1;
 int n2 = n1 + 1; 
 return query(le, re, n1, l, m) + query(le, re, n2, m+1, r); 
}
void upd(int le, int re, int val, int node = 0, int l = 0, int r = ti-1)
{
 if (l > re || r < le)
  return; 
 if (l >= le && r <= re)
 {
  sum[node] = val;
  laz[node] = val; 
  return; 
 }
 push_down(node); 
 int m = (l+r)>>1;
 int n1 = node * 2 + 1; 
 int n2 = n1 + 1; 
 upd(le, re, val, n1, l, m);
 upd(le, re, val, n2, m+1, r);
 sum[node] = sum[n1] + sum[n2]; 
}
int qur(int le, int re, int node = 0, int l = 0, int r = ti-1)
{
 if (l > re || r < le)
  return 0;
 if (l >= le && r <= re)
  return sum[node];
 push_down(node);
 int m = (l+r) >> 1;
 int n1 = node * 2 + 1;
 int n2 = n1 + 1; 
 return qur(le, re, n1, l, m) + qur(le, re, n2, m+1, r); 
}
void dfs(int u = 0, int p = -1)
{
  par[u] = p; 
  st[u] = ti;
  tour[ti++] = u; 
  for (int i: adj[u])
   if (i != p)
    dfs(i, u); 
  en[u] = ti; 
  tour[ti++] = u;  
}
pair<int, int> get_range(int u)
{
 return {st[u], en[u]}; 
}
int main()
{
 
  scanf("%d", &n);
  for (int i = 0; i < n-1; i++)
  {
    int u, v;
    scanf("%d%d", &u, &v);
    u--;v--;
    adj[u].push_back(v);
    adj[v].push_back(u); 
  }
  dfs(); 
  build();
  scanf("%d", &m); 
  while(m--)
  {
   int ty, v; 
   scanf("%d%d", &ty, &v);
   v--;
   auto rng = get_range(v);
   if (ty == 1)
   {
    update(rng.first, rng.second, 1);
    int cursum = qur(rng.first, rng.second);
    if (!cursum)continue; 
    upd(rng.first, rng.second, 0); 
    int p = par[v];
    if (~p)
    {
     upd(st[p], st[p], 1);
    }
   }
   else if (ty == 2)
   {
    upd(st[v], st[v], 1);
   }else 
   {
    int bad = qur(rng.first, rng.second); 
    int ini = query(st[v], st[v]);
    if (bad || !ini)
     printf("0\n");
    else 
     printf("1\n"); 
   }
  }
}
