#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll i,j,t,n,l,p,m,k,x;
    char c;
    scanf("%lld",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%lld %lld %lld",&n,&m,&k);
        vector<ll>v[n];
        map<ll,bool>mm;
        for(j=0; j<n; j++)
        {
            for(l=0; l<k; l++)
            {
                getchar();
                scanf("%c%lld",&c,&x);
                //cout<<c<<"   "<<x<<endl;
                if(c=='-')
                    v[j].push_back(x);
            }
        }
        scanf("%lld",&p);;
        for(j=0; j<p; j++)
        {
            scanf("%lld",&x);
            mm[x]=1;
        }

        bool f=0;
        for(j=0; !f&&j<n; j++)
        {
            for(l=0; l<v[j].size(); l++)
            {
                if(mm[v[j][l]])
                {
                    f=1;
                    break;
                }
            }
        }
        if(f)
            printf("Case %lld: No\n",i);
        else
            printf("Case %lld: Yes\n",i);
    }
    return 0;
}
