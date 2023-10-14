#include<iostream>
using namespace std;
const int N =1010;
int a[N],n;
int binary_search(int target)
{
    int l=0,r=n-1;
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(a[mid]<target)
        l=mid+1;
        else if(a[mid]>target)
        r=mid-1;
        else return mid;
    }
    return -1;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++) 
    cin>>a[i];
    int target;
    cin>>target;
    cout<<"The position of the target is: "<<binary_search(target)<<endl;
    return 0;
}

