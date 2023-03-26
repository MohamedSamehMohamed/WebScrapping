#include <bits/stdc++.h>
using namespace std;
void read_file()
{
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif
}
char s[100];
char x[100]; 
void test()
{
  scanf(" %s", x); 
  map<char, int> mp;
  for(int i = 0; i < 26; i++)
    mp[x[i]] = i; 
  scanf(" %s", s);
  int n = strlen(s);
  long long ans = 0;
  for(int i = 1; i < n; i++)
    ans += abs(mp[s[i]] - mp[s[i-1]]); 
  printf("%lld\n", ans);
}
int main()
{
  read_file();
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}
