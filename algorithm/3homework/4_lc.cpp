#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1010;
int m, n, nums1[N], nums2[N];
int getKthElement(int k)
{
    int index1 = 0, index2 = 0;
    while (true)
    {
        // 边界情况
        if (index1 == m)
        {
            return nums2[index2 + k - 1];
        }
        if (index2 == n)
        {
            return nums1[index1 + k - 1];
        }
        if (k == 1)
        {
            return min(nums1[index1], nums2[index2]);
        }

        // 正常情况
        int newIndex1 = min(index1 + k / 2 - 1, m - 1);
        int newIndex2 = min(index2 + k / 2 - 1, n - 1);
        int pivot1 = nums1[newIndex1];
        int pivot2 = nums2[newIndex2];
        if (pivot1 <= pivot2)
        {
            k -= newIndex1 - index1 + 1;
            index1 = newIndex1 + 1;
        }
        else
        {
            k -= newIndex2 - index2 + 1;
            index2 = newIndex2 + 1;
        }
    }
}

double findMedianSortedArrays()
{
    int totalLength = m + n;
    if (totalLength % 2 == 1)
    {
        return getKthElement((totalLength + 1) / 2);
    }
    else
    {
        return (getKthElement(totalLength / 2) + getKthElement(totalLength / 2 + 1)) / 2.0;
    }
}
int main()
{
    cin >> m >> n;
    for (int i = 0; i < m; i++)
        cin >> nums1[i];
    for (int i = 0; i < n; i++)
        cin >> nums2[i];
    printf("The median number of these two sequence is: %lf\n",findMedianSortedArrays());
    return 0;
}

