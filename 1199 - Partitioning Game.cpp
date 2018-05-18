#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll grundy[100005];
void Grundy()
{
    grundy[0]=grundy[1]=grundy[2]=0;

}


int main()
{
    ll i,j,t,n,ans;
    scanf("%lld",&t);
    for(j=1;j<=t;j++)
    {
        scanf("%lld",&n);
        ll a[n];ans=0;
        for(i=0;i<n;i++)
            scanf("%lld",&a[i]);


        if(ans==0)
            printf("Case %lld: Bob\n",j);
        else
            printf("Case %lld: Alice\n",j);
    }
    return 0;
}
