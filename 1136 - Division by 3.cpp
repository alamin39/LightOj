#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll i,j,t,a,b,ans=0;
    scanf("%lld",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%lld %lld",&a,&b);
        a--;
        if(b>1)
            ans = b-1-((b-1)/3);
        else
            ans=0;

        if(a>1)
            ans -= (a-1-((a-1)/3));
        printf("Case %lld: %lld\n",i,ans);
    }
    return 0;
}
