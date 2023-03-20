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
int n, k;
char s[N];
int last[26];
void test()
{
  scanf("%d%d", &n, &k);
  for(int i = 0; i < 26; i++)
    last[i] = i;
  scanf(" %s", s);
  for(int i = 0; i < n && k; i++)
  {
    vector<int> tm;
    tm.push_back(last[s[i] - 'a']);
    while (k && last[s[i] - 'a'] != 0)
    {
      k--;
      last[s[i] - 'a'] = last[s[i] - 'a' - 1];
      s[i]--;
      tm.push_back(last[s[i] - 'a' + 1]);
    }
    for(int j: tm)
      last[j] = last[s[i] - 'a'];
  }
  for(int i = 0; i < n; i++)
    printf("%c", 'a' + last[s[i] - 'a']);
  printf("\n");
}
int main()
{
  read_file();
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}
 
 
 
