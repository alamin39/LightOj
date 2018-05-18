///Title: joshep
///Bismillahir Rahmanir Rahim.
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll josephus(ll n, ll k)
{
    if(n==1)
        return 1;
    else
        return (josephus(n-1,k)+ k-1)%n + 1;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll i,j,k,a,b,f0,f1,n,m,t,sum=0,ans=0;
    bool f=0,flag=0;

    while(cin>>n)
    {
        ans=sum=0;
        while(1)
        {
            ans=josephus(n, 2);
            if(n==ans)
            {
               sum+=(n*2);break;
            }
            sum+= (n-ans);
            n=ans;
        }
        cout<<sum<<endl;
    }
    return 0;
}
