#include <bits/stdc++.h>
using namespace std;
int n;
void test()
{
 scanf("%d", &n);
 char input[4];
 bool ok = 0;
 vector<string> v;
 set<string> ignoreThird, notIgnore;
 for (int i = 0; i < n; i++)
 {
  scanf(" %s", input);
  v.push_back(input);
  if (v[i].size() == 1 || v[i][0] == v[i].back()) ok = 1;
 }
 for (int i = 0; !ok && i < n; i++)
 {
  if (v[i].size() == 2)
  {
   string tem = v[i];
   reverse(tem.begin(), tem.end());
   if (ignoreThird.find(tem) != ignoreThird.end())
    ok = 1;
   notIgnore.insert(v[i]);
   ignoreThird.insert(v[i]);
  }else
  {
   string tem = v[i];
   reverse(tem.begin(), tem.end());
   if (notIgnore.find(tem) != notIgnore.end()) ok = 1;
   tem.pop_back();
   if (notIgnore.find(tem) != notIgnore.end()) ok = 1;
   notIgnore.insert(v[i]);
   v[i].pop_back();
   ignoreThird.insert(v[i]);
  }
 }
 if (ok)
  printf("YES\n");
 else
  printf("NO\n");
}
int main()
{
 int t;
 scanf("%d", &t);
 while(t--)
  test();
}
