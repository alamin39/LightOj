#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define sf(x) scanf("%lld",&x)

bool vis[1002];
ll a[102],visited[1002];
vector<ll>g[1002];

void init()
{
    for(int i=0; i<=1000; i++)
    {
        g[i].clear();
        vis[i]=a[i]=visited[i]=0;
    }
}


void BFS(ll src)
{
    ll i;
    queue<ll>q;
    q.push(src);
    vis[src]=1; visited[src]+=1;
    while(!q.empty())
    {
        src=q.front();
        q.pop(); //cout<<src<<endl;
        for(i=0; i<g[src].size(); i++)
        {
            if(!vis[g[src][i]])
            {
                vis[g[src][i]]=1;
                visited[g[src][i]]+=1;
                q.push(g[src][i]);
            }
        }
    }
}


int main()
{
    ll i,j,t,u,v,n,k,m,src,dest,cnt;
   // freopen("in.txt","r",stdin);
    sf(t);
    for(i=1; i<=t; i++)
    {
        sf(k);
        sf(n);
        sf(m);
        init();
        for(j=0; j<k; j++)
            sf(a[j]);
        for(j=0; j<m; j++)
        {
            sf(u);
            sf(v);
            g[u].push_back(v);
        }

        cnt=0;
        BFS(a[0]);
        for(j=1; j<k; j++)
        {
            memset(vis,0,n+1);
            BFS(a[j]);
        }

        for(j=1;j<=n;j++)
        {
            if(visited[j]==k)
                cnt++;
        }
        printf("Case %lld: %lld\n",i,cnt);
    }
    return 0;
}
