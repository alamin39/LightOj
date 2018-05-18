#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool isLeapYear(ll year)
{
    if (year % 400 == 0) return true;
    else if(year % 100 == 0) return false;
    else if(year % 4 == 0) return true;
    else return false;
}

int main()
{
    ll i,j,t,y1,y,d,m,ans,m1,d1;
    char a[15],b[15];
    char month[13][15]= {"January", "February", "March", "April", "May", "June", "July", "August",
                         "September", "October", "November", "December"
                        };
    scanf("%lld",&t);
    for(j=1; j<=t; j++)
    {
        scanf("%s %lld, %lld",a,&d,&y);
        scanf("%s %lld, %lld",b,&d1,&y1);
        m=m1=ans=0;
        for(i=0; i<12; i++)
        {
            if(strcmp(a,month[i])==0)
            {
                m=i+1;
                break;
            }
        }
        for(i=0; i<12; i++)
        {
            if(strcmp(b,month[i])==0)
            {
                m1=i+1;
                break;
            }
        }
        //cout<<d<<" "<<m<<" "<<y<<endl;
        //cout<<d1<<" "<<m1<<" "<<y1<<endl;
       if(m>2)
            y++;
       if(m1<2|| (m1==2 && d1!=29))
            y1--;

       ll start=0,End=y1;
       for(i=y;i<=y1;i++)
       {
           if(isLeapYear(i))
           {
               start= i; ans=1;
               break;
           }
       }

       if(start>0)
            ans += ((End/4)-(start/4))-((End/100)-(start/100))+((End/400)-(start/400));
       printf("Case %lld: %lld\n",j,ans);
    }
    return 0;
}
