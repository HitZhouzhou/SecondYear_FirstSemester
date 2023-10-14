#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1010;
int m, n, a[N], b[N];
double getKthElm(int k)
{
    int idx1 = 0, idx2 = 0;
    while (true)
    {
        if (idx1 == m)
            return b[idx2 + k - 1];
        if (idx2 == n)
            return a[idx1 + k - 1];
        if (k == 1)
            return min(a[idx1], b[idx2]);

        int newIndex1 = min(idx1 + k / 2 - 1, m - 1);
        int newIndex2 = min(idx2 + k / 2 - 1, n - 1);
        if (a[newIndex1] <= b[newIndex2])
        {
            idx1 = newIndex1 + 1;
            k -= newIndex1 - idx1 + 1;
        }
        else
        {
            idx2 = newIndex2 + 1;
            k -= newIndex2 - idx2 + 1;
        }
    }
}
double findMedianSortedArray()
{
    int totalLength = n + m;
    if (totalLength & 1)
        return getKthElm((totalLength + 1) / 2);
    else
        return (getKthElm(totalLength / 2) + getKthElm(totalLength / 2 + 1)) / 2.0;
}
int main()
{
    cin >> m >> n;
    for (int i = 0; i < m; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 1; i <= m + n; i++)
        cout << getKthElm(i) << ' ';
    cout << endl;
    cout << findMedianSortedArray() << endl;
    
    return 0;
}