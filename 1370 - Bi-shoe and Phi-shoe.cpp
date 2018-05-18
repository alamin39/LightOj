#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define M 1000105

ll phi[M];
bool a[M];
vector<ll>vv;

void seive()
{
    vv.push_back(2);
    for(ll i=3; i<M; i+=2)
    {
        if(a[i]==0)
        {
            vv.push_back(i);
            for(ll j=2; i*j<M; j++)
            {
                a[i*j]=1;
            }
        }
    }
}

void calculatePhi()
{
    for(ll i=1; i<M; i++)
    {
        phi[i]=i;
    }
    for(ll p=2; p<M; p++)
    {
        if(phi[p]==p)   // p is a prime
        {
            for(ll k=p; k<M; k+=p)
            {
                phi[k]-=(phi[k]/p);
            }
        }
    }
}


int main()
{
    seive();
    calculatePhi();
    ll i,j,t,k,n,ans,m,sum;
    scanf("%lld",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%lld",&n);
        ans=sum=0;
        for(j=0; j<n; j++)
        {
            scanf("%lld",&m);
            ans = lower_bound(vv.begin(),vv.end(),m)-vv.begin();
            for(k=vv[ans]; k<=vv[ans+1]; k++)
            {
                if(phi[k]>=m)
                {
                    sum+=k;
                    break;
                }
            }
        }
        printf("Case %lld: %lld Xukha\n",i,sum);
    }
    return 0;
}
