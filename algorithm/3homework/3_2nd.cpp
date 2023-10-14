#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1e5 + 10;
typedef pair<double, int> PDD;
int n, m;
PDD a[N], b[N];
bool cmp(PDD a, PDD b)
{
    if (a.first < b.first)
        return true;
    else if (a.first == b.first && a.second < b.second)
        return true;
    else
        return false;
}
PDD quick_find(PDD a[], int l, int r, int k)
{
    if (l >= r)
        return a[l];
    int mid = (l + r) >> 1;
    PDD x = a[mid];
    int i = l - 1, j = r + 1;
    while (i < j)
    {
        do
            i++;
        while (cmp(a[i], x));
        do
            j--;
        while (cmp(x, a[j]));
        if (i < j)
            swap(a[i], a[j]);
    }
    // l~j,j+1~r;
    if (j - l + 1 >= k)
    {
        return quick_find(a, l, j, k);
    }
    else
    {
        return quick_find(a, j + 1, r, k - j - 1 + l);
    }
}
int main()
{
    int k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    PDD median;
    if (n & 1)
        median = quick_find(a, 1, n, (n + 1) / 2);
    else
    {
        PDD m1 = quick_find(a, 1, n, n / 2);
        PDD m2 = quick_find(a, 1, n, n / 2 + 1);
        median.first = (m1.first + m2.first) / 2;
        median.second = (m1.second + m2.second) / 2;
    }
    printf("median = %lf\nposition = %d\n", median.first, median.second);
    for (int i = 1; i <= n; i++)
    {
        b[i].first = abs(a[i].first - median.first);
        b[i].second = i;
    }
    printf("最接近中位数的%d个数为:\n", k);
    for (int i = 1; i <= k; i++)
    {
        PDD close = quick_find(b, 1, n, i);
        printf("%lf ", a[close.second].first);
    }
    cout << endl;
    return 0;
}