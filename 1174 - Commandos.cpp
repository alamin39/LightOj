#include<bits/stdc++.h>
using namespace std;
#define sf(x) scanf("%lld",&x)
#define ll long long int

vector<ll>g[101];
bool vis[101],v[101];
ll dis[101],d[101];

ll BFS(ll src,ll dest)
{
    queue<int>Q;
    int i,test=0;
    Q.push(src);
    vis[src]=1;
    ll cnt=0;dis[src]=0;
    while(!Q.empty())
    {
        src=Q.front();
        Q.pop();
        for(i=0; i<g[src].size(); i++)
        {
            test=g[src][i];
            if(!vis[test])
            {
                vis[test]=1;
                dis[test]=dis[src]+1;
                Q.push(test);
            }
        }
    }
    return dis[dest];
}


ll bfs(ll src,ll dest)
{
    queue<int>Q;
    int i,test=0;
    Q.push(src);
    v[src]=1;
    ll cnt=0;
    while(!Q.empty())
    {
        src=Q.front();
        Q.pop();
        for(i=0; i<g[src].size(); i++)
        {
            test=g[src][i];
            if(!v[test])
            {
                v[test]=1;
                d[test]=d[src]+1;
                Q.push(test);
            }
        }
    }
    return d[dest];
}

int main()
{
    ll i,k,j,n,t,r,u,V,src,ans=0,s,dest;
    sf(t);
    for(k=1; k<=t; k++)
    {
        sf(n);
        sf(r);
        ans=s=0;
        for(i=0; i<=n; i++)
        {
            vis[i]=dis[i]=0;
            v[i]=d[i]=0;
            g[i].clear();
        }
        for(j=0; j<r; j++)
        {
            sf(u);
            sf(V);
            g[u].push_back(V);
            g[V].push_back(u);
        }
        sf(src);
        sf(dest);
        BFS(src,dest);
        bfs(dest,src);
        ans=0;
        for(i=0;i<n;i++)
        {
           ans=max(ans,d[i]+dis[i]);
        }
        printf("Case %lld: %lld\n",k,ans);
    }
    return 0;
}
