#include<iostream>
using namespace std;
int knapsack(int wt[],int val[],int w,int n)
{
    int dp[n+1][w+1];
    for(int i=0;i<=n;i++)
    {
        for( int j=0;j<=w;j++)
        {
            if(i==0 || j==0)
            dp[i][j]=0;
            else if(wt[i-1]<=j)
            {
                dp[i][j]=max(dp[i-1][j],val[i-1]+dp[i-1][j-wt[i-1]]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][w];
}
int main()
{
    int n;
    cin>>n;
    int wt[n],val[n];
    for(int i=0;i<n;i++)
    cin>>wt[i];
    for(int j=0;j<n;j++)
    cin>>val[j];
    int w;
    cin>>w;
    n=sizeof(wt)/sizeof(wt[0]);
    cout<<knapsack(wt,val,w,n);

}