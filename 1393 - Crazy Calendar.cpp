#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll i,j,t,n,m,k,x;
    scanf("%lld",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%lld %lld",&n,&m);
        ll ans=0;
        for(j=1; j<=n; j++)
        {
            for(k=1; k<=m; k++)
            {
                scanf("%lld",&x);
                if((n+m)%2!=(j+k)%2)
                    ans^=x;
            }
        }
        if(ans==0)
            printf("Case %lld: lose\n",i);
        else
            printf("Case %lld: win\n",i);
    }
    return 0;
}
