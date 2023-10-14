#include<iostream>
#include<algorithm>
using namespace std;
const int N =1010;
typedef pair<int,int>PII;
PII a[N],b[N],c[N];
int postition[N];
int n,k;
PII find_the_kth_number(PII a[],int l,int r,int k)
{
    if(l>=r)return a[l];
    int mid=(l+r)>>1;
    PII x=a[mid];
    int i=l-1,j=r+1;
    while(i<j)
    {
        do i++;while(a[i].first<x.first);
        do j--;while(a[j].first>x.first);
        if(i<j)swap(a[i],a[j]);
    }
    //因此，现在比x小的数都在x的左边，比x大的数都在x的右边,此时x的坐标即为i(j)。
    if(i-l+1>=k)return find_the_kth_number(a,l,i,k);
    else return find_the_kth_number(a,i+1,r,k-i-1+l);
}
int main()
{
    cin>>n>>k; 
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        a[i].first=x,a[i].second=i;
    }
    PII median;
    if(n&1)
    median=find_the_kth_number(a,1,n,(n+1)/2);
    cout<<"median: "<<median.first<<endl<<"position:"<<median.second<<endl;
    for(int i=1;i<=n;i++)
    {
        b[i].first=abs(a[i].first-median.first);
    }
    printf("最接近中位数的%d个数为:\n",k);
    for(int i=1;i<=k;i++)
    {
        PII x = find_the_kth_number(b,1,n,i); 
        cout<<a[x.second].first<<' ';
    }
    cout<<endl;
    return 0;
}