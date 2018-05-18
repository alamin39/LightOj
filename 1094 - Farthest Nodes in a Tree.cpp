#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector<pair<ll,ll> >vv[30002];
bool vis[30002];ll mx=0,dis[30002];

ll bfs(ll src)
{
   queue<ll>q;ll v=0,last=src;
   q.push(src);
   vis[src]=1;
   dis[src]=0;
   while(!q.empty())
   {
       v=q.front();
       q.pop();
       for(ll i=0;i<vv[v].size();i++)
       {
           if(vis[vv[v][i].first]==0)
           {
                vis[vv[v][i].first]=1;
                q.push(vv[v][i].first);
                dis[vv[v][i].first]=dis[v]+vv[v][i].second;
                if(mx<dis[vv[v][i].first])
                    last = vv[v][i].first,mx=dis[vv[v][i].first];
           }
       }
   }
   return last;
}

int main()
{
    ll i,j,t,u,v,w,ans=0,n;
    scanf("%lld",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%lld",&n);mx=0;
        for(j=0;j<=n;j++)
        {
            vv[j].clear();
            vis[j]=dis[j]=0;
        }

        for(j=1;j<n;j++)
        {
            scanf("%lld %lld %lld",&u,&v,&w);
            vv[u].push_back(make_pair(v,w));
            vv[v].push_back(make_pair(u,w));
        }
        ans=bfs(0);
        for(j=0;j<=n;j++)
        {
            dis[j]=vis[j]=0;
        }
        ans=bfs(ans);
        //cout<< ans<<" "<<mx<<endl;
        //cout<<*max_element(dis,dis+n)<<endl;
        printf("Case %lld: %lld\n",i,mx);
    }
    return 0;
}
