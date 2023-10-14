#include<iostream>
using namespace std;
const int N =1010;
int w[N]={0,1,2,3,4},v[N]={0,2,4,4,5},dp[N][N];
int main()
{
    int n=4,m=5;
    for(int i=n;i>=1;i--)
    {
        for(int j=0;j<=m;j++)
        {
            dp[i][j]=dp[i+1][j];
            if(j>=w[i])
            dp[i][j]=max(dp[i][j],dp[i][j-w[i]]+v[i]);
        }
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            cout<<dp[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<dp[1][m]<<endl;
    return 0;
}