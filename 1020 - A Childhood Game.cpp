#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll i,t,n,ans;
    char s[10];
    scanf("%lld",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%lld",&n);
        scanf("%s",s);
        printf("Case %lld: ",i);
        if(s[0]=='A')
        {
            if(n%3==1)
                printf("Bob\n");
            else
                printf("Alice\n");
        }
        else
        {
            if(n%3==0)
                printf("Alice\n");
            else
                printf("Bob\n");
        }
    }
    return 0;
}
