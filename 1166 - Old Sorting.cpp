#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int i,j,n,t,cnt=0;
    scanf("%lld",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%lld",&n);
        long long int sum, a[n+1];
        for(j=1; j<=n; j++)
        {
            scanf("%lld",&a[j]);
        }
        sum=0;
        while(1)
        {
            cnt=0;
            for(j=1; j<=n; j++)
            {
                if(a[j]!=j)
                {
                    cnt++;
                    swap(a[j],a[a[j]]);
                }
            }
            if(cnt==0)break;
            else
                sum+=cnt;
        }
        printf("Case %lld: %lld\n",i,sum);
    }
    return 0;
}
