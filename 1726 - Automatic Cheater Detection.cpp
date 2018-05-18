///Bismillahir Rahmanir Rahim.
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll i,j,d,l,k,n,m,t,sum=0,ans=0;
    cin>>t;
    char c;
    for(k=1; k<=t;k++)
    {
        cin>>n;
        ll a[11]={0},b[11]={0};ans=0;
        for(i=0; i<n; i++)
        {
            cin>>d>>l>>c;
            if(l==0 && c=='i')
                a[d]++;
            if(l==1&&c=='c')
                b[d]++;
        }
        for(i=10;i>0;i--)
        {
            for(j=i-1;j>0;j--)
                ans+= (b[i]*a[j]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
