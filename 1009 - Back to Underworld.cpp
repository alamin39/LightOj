#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector<ll>g[20002];
bool vis[20005];
struct st
{
    ll sz,num;
};

void init(ll e)
{
    for(ll i=0; i<=e; i++)
    {
        vis[i]=0;
        g[i].clear();
    }
}


ll BFS(ll src)
{
    queue<int>Q;
    int i,test=0;
    Q.push(src);
    ll cnt=0;
    vis[src]=1;
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
                cnt++;
                Q.push(test);
            }
        }
    }
    return cnt;
}

bool comp(st a,st b)
{
    return a.sz>b.sz;

}


int main()
{
    ll i,k,j,n,e,t,node,edge,src,cnt,l,ans;
    scanf("%lld",&t);
    for(k=1; k<=t; k++)
    {
        scanf("%lld",&e);
        init(20000);
        map<ll,ll>mm;
        l=0;
        for(i=0; i<e; i++)
        {
            scanf("%lld %lld",&node,&edge);
            if(mm[node]==0)
                mm[node]=++l;
            if(mm[edge]==0)
                mm[edge]=++l;
            g[mm[node]].push_back(mm[edge]);
            g[mm[edge]].push_back(mm[node]);
        }
        vector<st>v;
        st temp;
        for(i=1; i<=l; i++)
        {
            temp.sz = g[i].size();
            temp.num=i;
            v.push_back(temp);
        }
        sort(v.begin(),v.end(),comp);
        ans=cnt=0;
        for(i=0; i<v.size(); i++)
        {
            if(vis[v[i].num]==0)
            {
                ans+=v[i].sz;
                BFS(v[i].num);
                cnt++;
            }
        }
        if(cnt==1)
        {
            memset(vis,0,l+1);
            for(i=1; i<v.size(); i++)
            {
                if(vis[v[i].num]==0)
                {
                    ans=ans+v[i].sz;
                    BFS(v[i].num);
                }
            }
        }
        printf("Case %lld: %lld\n",k,ans);
    }
    return 0;
}
