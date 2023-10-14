#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int N = 1010;
int dp[N];
int KillMostMice(vector<int> a,int l,int r)
{
    memset(dp,0,sizeof dp);
    dp[0]=a[0];
    dp[1]=max(a[0],a[1]);
    for(int i=2;i<a.size();i++)
    {
        dp[i]=max(dp[i-1],dp[i-2]+a[i]);
    }
    return dp[r];
}
int main()
{
    vector<int>a;
    int n;
    cin>>n;
    for(int i=0;i<n;i++) 
    {
        int x;
        cin>>x;
        a.push_back(x);
    }
    int ans1=KillMostMice(a,0,n-2);
    int ans2=KillMostMice(a,1,n-1);
    cout<<max(ans1,ans2)<<endl;
    return 0;
}