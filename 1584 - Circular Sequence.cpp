#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int minimumExpression(string s)
{
    s=s+s;
    int len=s.size(),i=0,j=1,k=0;
    while(i+k<len && j+k<len)
    {
        if(s[i+k] == s[j+k]) k++;
        else if(s[i+k]>s[j+k])
        {
            i=i+k+1 ; ///surely can escape this points
            if(i<=j) i=j+1; ///as j is smallest now we will start from j+1 minimum
            k=0;
        }
        else if(s[i+k]<s[j+k])
        {
            j=j+k+1 ;
            if(j<=i) j=i+1;
            k=0;
        }
    }
    return min(i,j);
}


int main()
{
    string s,b,a;
    int t,i,ans;
    scanf("%d",&t);
    while(t--)
    {
        cin>>s;
        a=b="";
        b=s;
        ans=0;
        ans=minimumExpression(s);
       // cout<<ans<<"\n";

        for(i=0; i<ans; i++)
        {
            a+=s[i];
            b.erase(b.begin());
        }
        cout<<b<<a<<"\n";
    }
    return 0;
}
