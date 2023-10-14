#include<iostream>
using namespace std;
int a[10]={5,7,8,9,4,1,3,2,6,10},tmp[20];
void merge_sort(int l,int r)
{
    if(l>=r)return;
    int mid=(l+r)>>1;
    merge_sort(l,mid);
    merge_sort(mid+1,r);
    int k=0,i=l,j=mid+1;
    while(i<=mid&&j<=r)
    {
        if(a[i]<a[j])tmp[k++]=a[i++];
        else tmp[k++]=a[j++];
    }
    while(i<=mid)tmp[k++]=a[i++];
    while(j<=r)tmp[k++]=a[j++];
    for(int i=l,j=0;i<=r;i++,j++)
    {
        a[i]=tmp[j];
    }
}
int main()
{
    merge_sort(0,9);
    for(int i=0;i<10;i++)
    cout<<a[i]<<' ';
    cout<<endl;
    return 0;
}