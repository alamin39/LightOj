#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll dp[200][101],n,a[200][101];

ll cal(ll r,ll c)
{
    if(r==2*n-1 || c==n || c==-1)
        return 0;
    if(dp[r][c]!=-1)
        return dp[r][c];
    if(r<n-1)
    {
        if(a[r+1][c]==0 && a[r+1][c+1]==0)
            return dp[r][c]=a[r][c];
        else if(a[r+1][c]==0 && a[r+1][c+1]!=0)
            return dp[r][c]=a[r][c]+cal(r+1,c+1);
        else if(a[r+1][c]!=0 && a[r+1][c+1]==0)
            return dp[r][c]=a[r][c]+cal(r+1,c);
        else if(a[r+1][c]!=0 && a[r+1][c+1]!=0)
            return dp[r][c]=a[r][c]+max(cal(r+1,c),cal(r+1,c+1));
    }
    else
    {
        if(c==0)
        {
            if(a[r+1][c]==0)
                return dp[r][c]=a[r][c];
            else if(a[r+1][c]!=0)
                return dp[r][c]=a[r][c]+cal(r+1,c);
        }
        else
        {
            if(a[r+1][c]==0 && a[r+1][c-1]==0)
                return dp[r][c]=a[r][c];
            else if(a[r+1][c]==0 && a[r+1][c-1]!=0)
                return dp[r][c]=a[r][c]+cal(r+1,c-1);
            else if(a[r+1][c]!=0 && a[r+1][c-1]==0)
                return dp[r][c]=a[r][c]+cal(r+1,c);
            else
                return dp[r][c]=a[r][c]+max(cal(r+1,c),cal(r+1,c-1));
        }
    }
}

int main()
{
    ll k,i,j,t,m,ans;
    scanf("%lld",&t);
    for(k=1; k<=t; k++)
    {
        scanf("%lld",&n);
        ans=0;
        memset(a,0,sizeof(a));
        for(i=0; i<n; i++)
        {
            for(j=0; j<=i; j++)
                scanf("%lld",&a[i][j]);
        }
        m=n-1;
        for(i=n; i<2*n-1; i++,m--)
        {
            for(j=0; j<m; j++)
                scanf("%lld",&a[i][j]);
        }
        memset(dp,-1,sizeof(dp));
        ans=cal(0,0);
        printf("Case %lld: %lld\n",k,ans);
    }
    return 0;
}
