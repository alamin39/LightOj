#include<bits/stdc++.h>
using namespace std;
#define ll long long int

char s[102];
ll len=0,dp[102][102];

ll cal(ll left,ll right)
{
    if(left>=right)
        return 0;

    if(dp[left][right]!=-1)
        return dp[left][right];

    if(s[left]==s[right])
    {
        return dp[left][right]= cal(left+1,right-1);
    }
    else
    {
        return dp[left][right]=1+min(cal(left+1,right),cal(left,right-1));
    }
}

int main()
{
    ll k,i,j,t,m,ans;
    scanf("%lld",&t);
    for(k=1; k<=t; k++)
    {
        scanf("%s",s);
        len =strlen(s)-1;
        memset(dp,-1,sizeof(dp));
        printf("Case %lld: %lld\n",k,cal(0,len));
    }
    return 0;
}
