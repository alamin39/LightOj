/// Bismillahir Rahmanir Rahim.
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll i,j,t,n,ans,a,m,k,d;
    scanf("%lld",&t);
    for(j=1; j<=t; j++)
    {
        scanf("%lld %lld",&n,&m);
        ans=0;
        for(i=0; i<n; i++)
        {
            d=0;
            for(k=0;k<m;k++)
            {
                scanf("%lld",&a);
                d+=a;
            }
            ans^=d;
        }
        if(ans)
            printf("Case %lld: Alice\n",j,ans);
        else
            printf("Case %lld: Bob\n",j,ans);
    }
    return 0;
}
