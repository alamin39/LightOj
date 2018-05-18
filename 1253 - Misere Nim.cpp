/// Bismillahir Rahmanir Rahim.
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll i,j,t,n,ans,a;
    bool f;
    scanf("%lld",&t);
    for(j=1; j<=t; j++)
    {
        scanf("%lld",&n);
        ans=f=0;
        for(i=0; i<n; i++)
        {
            scanf("%lld",&a);
            if(a>1)
                f=1;
            ans^=a;
        }
        if(f)
        {
            if(ans)
                printf("Case %lld: Alice\n",j,ans);
            else
                printf("Case %lld: Bob\n",j,ans);
        }
        else
        {
            if(n%2==0)
                printf("Case %lld: Alice\n",j,ans);
            else
                printf("Case %lld: Bob\n",j,ans);
        }
    }
    return 0;
}

