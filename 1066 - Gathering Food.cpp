#include<bits/stdc++.h>
using namespace std;
#define ll int

map<char,ll>mm,nn;
ll dis[12][12],n;
bool vis[12][12];
char s[12][12];
int X[]= {1,0,-1,0};
int Y[]= {0,1,0,-1};

ll BFS(int src,int sr,int dest,int des)
{
    for(int i=0; i<=11; i++)
    {
        memset(vis[i],0,sizeof(vis[i]));
        memset(dis[i],0,sizeof(dis[i]));
    }
    queue<int>Q;
    ll r,c,Row=n,i,Col=n;
    ll R=0,C=0;
    vis[src][sr]=1;
    Q.push(src);
    Q.push(sr);
    s[src][sr]='.';
    dis[src][sr]=0;
    while(!Q.empty())
    {
        src = Q.front();
        Q.pop();
        sr = Q.front();
        Q.pop();
        for(i=0; i<4; i++)
        {
            r=c=0;
            R=src;
            C=sr;
            r = src+X[i];
            c = sr+Y[i];
            if(vis[r][c]==0&&r>=0 && c>=0 && r<Row && c<Col && (s[r][c]=='.'||(r==dest&&c==des)))
            {
                vis[r][c]=1;
                Q.push(r);
                Q.push(c);
                dis[r][c]=dis[R][C]+1;
                // cout<<dis[r][c]<<"a\n";
                if(r==dest && c==des)
                    return dis[r][c];
            }
        }
    }
    return dis[dest][des];
}


int main()
{
    int i,src,sr,j,k,t,cnt;
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%d",&n);
        cnt=0;
        for(j=0; j<n; j++)
        {
            scanf("%s",s[j]);
//            cout<<s[j]<<endl;
        }
        for(j=0; j<n; j++)
        {
            for(k=0; k<n; k++)
            {
                if(s[j][k]=='A')
                {
                    src=j;
                    sr=k;
                }
                else if(s[j][k]>'A' && s[j][k]<='Z')
                {
                    mm[s[j][k]]=j;
                    nn[s[j][k]]=k;
                }
            }
        }
        ll al=0,f=0;
        for(map<char,ll>::iterator it=mm.begin(); it!=mm.end(); it++)
        {
            al=BFS(src,sr,mm[it->first],nn[it->first]);
            src=mm[it->first];
            sr=nn[it->first];
            //  cout<<al<<endl;
            if(al==0)
            {
                printf("Case %d: Impossible\n",i);
                f=1;
                break;
            }
            cnt+= al;
        }
        mm.clear();
        nn.clear();
        if(f==0)
            printf("Case %d: %d\n",i,cnt);
    }
    return 0;
}
