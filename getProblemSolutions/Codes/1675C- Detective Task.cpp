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
int n;
char s[N];
int pre[N][3];
int count(int l, int r, int c)
{
  if (l > r)return 0;
  return pre[r][c] - (l-1 >= 0? pre[l-1][c]: 0);
}
void test()
{
  scanf(" %s", s);
  n = strlen(s);
  if (n == 1)
  {
    printf("1\n");
    return;
  }
  for(int i = 0; i < n; i++)
  {
    pre[i][0] = pre[i][1] = pre[i][2] = 0;
    if (s[i] == '0')
    {
      pre[i][0]++;
    }else if (s[i] == '1')
    {
      pre[i][1]++;
    }else 
    {
      pre[i][2]++;
    }
    for(int j = 0; i && j < 3; j++)
      pre[i][j] += pre[i-1][j];
  }
  int answer = 0;
  for(int i = 0; i < n; i++)
  {
    int zero_before = count(0, i-1, 0);
    int one_after = count(i+1, n-1, 1);
    if (zero_before == 0 && one_after == 0)
      answer++;
  }
  printf("%d\n", answer);
 
 
}
int main()
{
  read_file();
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}
