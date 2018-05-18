#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool a[5000002];
vector<ll>b;

void seive()
{
    ll i,j;
    b.push_back(2);
    for(i=3; i<=5000000; i+=2)
    {
        if(a[i]==false)
        {
            b.push_back(i);
            for(j=2; i*j<=5000000; j++)
            {
                a[i*j]=true;
            }
        }
    }
}

ll divisor_count(ll num,ll n)
{
    ll res,cnt=1,ans=1,i=0;
    while(i<b.size() && b[i]*b[i]<=num)
    {
        if(num%b[i]==0)
        {
            res=0;
            while(num%b[i]==0)
            {
                num/=b[i];
                res++;
            }
            cnt*=(res+1);
        }
        i++;
    }
    if(num>=n && num*num<=d)
        cnt*=2;
}

int main()
{
    seive();
    ll i,j,t,n,area,k,ans;
    scanf("%lld",&t);
    for(k=1; k<=t; k++)
    {
        scanf("%lld %lld",&area,&n);
        ans=j=0;
        ans=divisor(area,n);
        printf("Case %lld: %lld\n",k,ans);
    }
    return 0;
}
