#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,n;
    cout<<"enter the size"<<endl;
    cin>>n;
    int dp[n+1];
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    dp[1]=1;
    //int l,r;
    for(i=0;i<=n;i++)
    {
       // cout<<dp[i]<<"==="<<endl;
    }
    for(i=2;i<=n;i++)
    {
        int l=0;
        int r=i-1;
        while(l<=(i-1))
        {
            dp[i]+=dp[l]*dp[r];
            l++;
            r--;
            //cout<<dp[i]<<"--"<<endl;    
        }
       // cout<<dp[i]<<"--"<<endl;
    }
    cout<<dp[n-1];
    return 0;
}