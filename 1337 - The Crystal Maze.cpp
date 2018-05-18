#include<bits/stdc++.h>
using namespace std;
#define sf(x) scanf("%lld",&x)
#define sf2(x,y) scanf("%lld %lld",&x,&y)
#define ll long long int

int X[]= {1,-1,0,0};
int Y[]= {0,0,1,-1};

char g[502][502];
bool vis2[502][502],vis[502][502];
ll dis[502][502],cnt=0;

ll BFS(ll r, ll c, ll src, ll dest)
{
    queue<ll>Q;
    ll i=0,j=0,p=0,p1=0;
    cnt=0;
    Q.push(src);
    Q.push(dest);
    vis[src][dest]=1;
    if(g[src][dest]=='C')
        cnt++;

    while(!Q.empty())
    {
        p=Q.front();
        Q.pop();
        p1=Q.front();
        Q.pop();
        for(j=0; j<4; j++)
        {
            src=i=0;
            src =(p+X[j]);
            i =(p1+Y[j]);
            if(vis[src][i]==0 && g[src][i]!='#' && src>0 && i>=0 && src<=r && i<c)
            {
                if(g[src][i]=='C')
                    cnt++;
                vis[src][i]=1;
                Q.push(src);
                Q.push(i);
            }
        }
    }
}

ll BFS2(ll r, ll c, ll src, ll dest)
{
    queue<ll>Q;
    ll i=0,j=0,p=0,p1=0;
    Q.push(src);
    Q.push(dest);
    dis[src][dest]=cnt;
    vis2[src][dest]=1;
    while(!Q.empty())
    {
        p=Q.front();
        Q.pop();
        p1=Q.front();
        Q.pop();
        for(j=0; j<4; j++)
        {
            src=i=0;
            src =(p+X[j]);
            i =(p1+Y[j]);
            if(vis2[src][i]==0 &&g[src][i]!='#'&& src>0 && i>=0 && src<=r && i<c)
            {
                dis[src][i]=cnt;
                vis2[src][i]=1;
                Q.push(src);
                Q.push(i);
            }
        }
    }
}

int main()
{
    ll j,row,i,col,ans=0,n,t,src,dest;
    // freopen("in.txt","r",stdin);
    scanf("%lld",&t);
    for( j=1; j<=t; j++)
    {
        scanf("%lld %lld %lld",&row,&col,&n);
        for(i=1; i<=row; i++)
        {
            scanf("%s",g[i]);
            //cout<<g[i]<<endl;
        }
        printf("Case %lld:\n",j);
        memset(vis,0,sizeof(vis));
        memset(vis2,0,sizeof(vis2));
        memset(dis,0,sizeof(dis));
        for(i=0; i<n; i++)
        {
            sf2(src,dest);
            if(vis[src][dest-1]==0)
            {
                BFS(row,col,src,dest-1);
                BFS2(row,col,src,dest-1);
            }
            printf("%lld\n",dis[src][dest-1]);
        }
    }
    return 0;
}
