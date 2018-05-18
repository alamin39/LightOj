
#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int i,t;double ans=0,r,a,b,c;
    scanf("%lld",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%lf %lf %lf %lf",&a,&b,&c,&r);
        ans=0;
        ans = a*sqrt(r/(r+1));
        printf("Case %lld: %.10lf\n",i,ans);
    }
    return 0;
}
