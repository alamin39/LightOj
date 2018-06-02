#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll cost[21][3],n,dp[21][3];

ll cal(ll clr,ll ind)
{
    if(ind==n)
        return 0;

    if(dp[ind][clr]!=-1)
        return dp[ind][clr];

    if(clr==0)
        return dp[ind][clr] = cost[ind][clr]+min(cal(clr+1,ind+1),cal(clr+2,ind+1));
    else if(clr==1)
        return dp[ind][clr] = cost[ind][clr]+min(cal(clr+1,ind+1),cal(clr-1,ind+1));
    else if(clr==2)
        return dp[ind][clr] = cost[ind][clr]+min(cal(clr-1,ind+1),cal(clr-2,ind+1));
}

int main()
{
    ll k,i,j,t,mn;
    scanf("%lld",&t);
    for(k=1; k<=t; k++)
    {
        scanf("%lld",&n);
        mn=1e18;
        for(i=0; i<n; i++)
        {
            scanf("%lld %lld %lld",&cost[i][0],&cost[i][1],&cost[i][2]);
        }
        memset(dp,-1,sizeof(dp));
        mn = cal(0,0);

        memset(dp,-1,sizeof(dp));
        mn = min(mn,cal(1,0));

        memset(dp,-1,sizeof(dp));
        mn = min(mn,cal(2,0));
        printf("Case %lld: %lld\n",k,mn);
    }
    return 0;
}
