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
int a[N], n;
char x[N]; 
int pre[N];
void test()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++)scanf("%d", a+i);
  scanf(" %s", x);
  vector<int> inc, dec; 
  for(int i = 0; i < n; i++)
  {
    if (x[i] == 'B')
    {
      if (a[i] >= 1)
      {
        dec.push_back(min(n, a[i])); 
      }
    }else 
    {
      if (a[i] <= n)
      {
        inc.push_back(max(1, a[i])); 
      }
    }
  }
  sort(inc.begin(), inc.end());
  sort(dec.begin(), dec.end());
  int cur = 1, j = 0; 
  // for(int i: inc)cout << i <<" ";cout <<"\n";
  
  // for(int i: dec)cout << i <<" ";cout <<"\n"; 
  for(int i = 0; i < inc.size(); i++)
  {
    if (j < dec.size() && dec[j] >= cur)
    {
      cur++;
      j++;
      i--;
      continue; 
    }
    if (inc[i] <= cur)
    {
      cur++; 
    }else 
    {
      if (j < dec.size() && dec[j] >= cur)
      {
        cur++;
        j++; 
        i--; 
      }else 
        break;
    }
  }
  while(j < dec.size() && cur <= n)
  {
    if (dec[j]>=cur)
    {
      j++;cur++;
    }else 
    break;
  }
  if (cur == n+1)
    printf("YES\n"); 
  else 
    printf("NO\n"); 
}
int main()
{
  read_file();
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}
