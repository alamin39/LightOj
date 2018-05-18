#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll solve(ll n)
{
    ll i,k,ans=0;string s="";
    while(n!=0)
    {
        s+= ((n%2)+'0');
        n/=2;
    }
    s+="0";
    reverse(s.begin(),s.end());
    //cout<<s<<endl;
    next_permutation(s.begin(),s.end());
    if(s[0]=='0')
        s.erase(s.begin());
   // cout<<s<<endl;
    for(i=s.size()-1,k=0;i>=0;k++,i--)
    {
        ans+=((s[i]-'0')*pow(2,k));
    }
    return ans;
}

int main()
{
    ll i,j,t,n,ans;
    scanf("%lld",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%lld",&n);
        printf("Case %lld: %lld\n",i,solve(n));
    }
    return 0;
}
