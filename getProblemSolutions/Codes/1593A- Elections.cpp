#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 9; 
int a[3];
void test()
{
  scanf("%d%d%d", a+0, a+1, a+2);
  for(int i = 0; i < 3; i++)
  {
    int x = a[(i-1+3)%3];
    int y = a[(i+1)%3]; 
    printf("%d ", max(0, 1 +  max(x, y) - a[i])); 
  }
  printf("\n");
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
