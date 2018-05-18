#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll i,j,n,t,ans;
    scanf("%lld",&t);
    for(j=1;j<=t;j++)
    {
        scanf("%lld",&n);
        ll a[n];
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
        }
        ans=0;
        for(i=0;i<n;i++)
        {
            ans=__gcd(a[i],ans);
        }
        printf("Case %lld: %lld\n",j,ans);
    }
    return 0;
}
