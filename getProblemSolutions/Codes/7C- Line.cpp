#include <bits/stdc++.h>
using namespace std;
void read_file(){
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif
}
long long gcd(long long a, long long b, long long& x, long long& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
bool find_any_solution(long long a, long long b, long long c, long long &x0, long long &y0, long long &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }
 
    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}
long long n, a, b;
int main()
{
  read_file(); 
  scanf("%lld%lld%lld", &a, &b, &n); 
  n *= -1; 
  long long x, y, g = __gcd(a, b);
  if (find_any_solution(a, b, n, x, y, g))
    printf("%lld %lld\n", x, y); 
  else 
    printf("-1\n");
}
