#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 9;
int a[N], is[N], n;
bool up(int i)
{
    if (i - 1 < 0 || i + 1 > n-1)return 0;
    return a[i] > max(a[i-1], a[i+1]);
}
bool down(int i)
{
    if (i - 1 < 0 || i + 1 > n-1)return 0;
    return a[i] < min(a[i-1], a[i+1]);
}
bool isCountable(int i)
{
    return (up(i) || down(i));
}
void test()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", a+i);
    int tot = 0;
    for (int i = 0; i < n; i++)
    {
        is[i] = isCountable(i);
        tot += is[i];
    }   
    int ans = tot;
    for (int i = 1; i < n - 1; i++)
    {
        int temp = a[i];
        vector<int> values{a[i-1], a[i+1]};
        for (int &v: values)
        {
            a[i] = v;
            ans = min(ans, tot - is[i] - is[i-1] - is[i+1] + isCountable(i-1) + isCountable(i) + isCountable(i+1)); 
        }
        a[i] = temp;
    }
    printf("%d\n", ans);
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
        test();
}
