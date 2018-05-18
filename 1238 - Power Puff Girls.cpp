#include<bits/stdc++.h>
using namespace std;
#define sf(x) scanf("%d",&x)

int X[]= {1,0,-1,0};
int Y[]= {0,1,0,-1};

bool vis[22][22];
int dis[22][22];
string g[22];

int BFS(int r,int c)
{
    memset(vis,0,sizeof(vis));
    bool f;
    int i=0,j=0,p=0,p1=0,src,ans=0,cnt=0;
    for(int k=1; k<=r && cnt<3; k++)
    {
        for(int l=0; l<c && cnt<3; l++)
        {
            if((g[k][l]=='a' || g[k][l]=='b' || g[k][l]=='c') && !vis[k][l])
            {
                queue<int>Q;
                Q.push(k);
                Q.push(l);
                vis[k][l]=1;
                dis[k][l]=0;
                f=0;
                while(!Q.empty() && !f)
                {
                    p=Q.front();
                    Q.pop();
                    p1=Q.front();
                    Q.pop();
                    for(j=0; j<4; j++)
                    {
                        src=i=0;
                        src=(p+X[j]);
                        i=(p1+Y[j]);
                        if(vis[src][i]==0 && src>0 && i>=0 && src<=r && i<c && g[src][i]!='#' &&  g[src][i]!='m')
                        {
                            vis[src][i]=1;
                            dis[src][i]=dis[p][p1]+1;
                            Q.push(src);
                            Q.push(i);
                            if(g[src][i]=='h')
                            {
                                ans=max(dis[src][i],ans);
                               // cout<<dis[src][i]<<" "<<g[k][l]<<endl;
                                f=1; cnt++;
                                memset(vis,0,sizeof(vis));
                                memset(dis,0,sizeof(dis));
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    return ans;
}


int main()
{
    int i,j,t,row,col;
    sf(t);
    for(i=1; i<=t; i++)
    {
        sf(row);
        sf(col);
        for(j=1; j<=row; j++)
        {
            g[j].clear();
            cin>>g[j];
        }
        cout<<"Case "<<i<<": "<<BFS(row,col)<<"\n";
    }
    return 0;
}
