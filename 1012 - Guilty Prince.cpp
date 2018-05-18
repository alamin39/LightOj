#include<bits/stdc++.h>
using namespace std;
#define sf(x) scanf("%d",&x)
#define sf2(x,y) scanf("%d %d",&x,&y)

int X[]= {1,-1,0,0};
int Y[]= {0,0,1,-1};

bool vis[22][22];
string g[22];

long long int BFS(long long int r,long long int c,long long int src,long long int dest)
{
    queue<long long int>Q;
    long long int i=0,j=0,p=0,p1=0,cnt=0;

    Q.push(src);
    Q.push(dest);
    vis[src][dest]=1;
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
            if(src>0 && i>=0 && src<=r && i<c && g[src][i]=='.')
            {
                if(vis[src][i]==0 )
                {
                    vis[src][i]=1;
                    Q.push(src);
                    Q.push(i);
                    cnt++;
                }
            }
        }
    }
    return cnt;
}


int main()
{
    long long int j,row,i,col,ans=0,t,src,dest;
    ///freopen("in.txt","r",stdin);
    scanf("%lld",&t);
    for( j=1; j<=t; j++)
    {
        scanf("%lld %lld",&row,&col);
        memset(vis,0,sizeof(vis));
        bool f=0;
        for(i=1; i<=col; i++)
        {
            g[i].clear();
            cin>>g[i];
            for(int k=0; k<g[i].size()&& !f; k++)
            {
                if(g[i][k]=='@')
                {
                    f=1;
                    src=i;
                    dest=k;
                }
            }
        }
        ans=0;
        ans=BFS(col,row,src,dest);
        printf("Case %lld: %lld\n",j,ans);
    }
    return 0;
}
