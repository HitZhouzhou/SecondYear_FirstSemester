#include<iostream>
#include<algorithm>
using namespace std;
const int N =1010;
typedef pair<int,int>PII;
PII a[N];
bool cmp(PII a, PII b)
{
    if (a.first < b.first)
        return true;
    else if (a.first == b.first && a.second < b.second)
        return true;
    else
        return false;
}
PII quick_find(PII a[], int l, int r, int k)
{
    if (l >= r)
        return a[l];
    int mid = (l + r) >> 1;
    PII x = a[mid];
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
    int n,l=0x3f3f3f3f,r=-0x3f3f3f,k;
    cin>>n>>k;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if(!a[x].first)cnt++;
        a[x].first++;
        a[x].second=x;
        r=max(r,x);
        l=min(l,x);
    }
    for(int i=cnt;i>=cnt-k+1;i--)
    {
        printf("出现频率第%d大的数为:",cnt-i+1);
        cout<<quick_find(a,l,r,i).second<<endl;
    }
    return 0;
}