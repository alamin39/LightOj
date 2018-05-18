///Bismillahir Rahmanir Rahim.
#include<bits/stdc++.h>
using namespace std;

bool a[1001],vis[1001];
vector<int>b,v[1001];
int dis[1001];

int BFS(int src,int dest)
{
    queue<int>Q;
    int i,test=0;
    Q.push(src);
    vis[src]=1;
    dis[src]=0;
    while(!Q.empty())
    {
        src=Q.front();
        Q.pop();
        for(i=0; i<v[src].size(); i++)
        {
            test=v[src][i];
            if(src+test<=dest && !vis[src+test])
            {
                vis[src+test]=1;
                dis[src+test]=dis[src]+1;
                Q.push(src+test);
                if(src+test == dest)
                    return dis[src+test];
            }
        }
    }
    return dis[dest];
}

void seive()
{
    int i,j;
    b.push_back(2);
    for(i=3; i*i<=1000; i+=2)
    {
        if(a[i]==false)
        {
            b.push_back(i);
            for(j=2; i*j<=1000; j++)
            {
                a[i*j]=true;
            }
        }
    }
}

void divisor_count(int num,int ind)
{
    int i=0;
    while(i<b.size() && b[i]<num)
    {
        if(num%b[i]==0)
        {
            v[ind].push_back(b[i]);
            while(num%b[i]==0)
            {
                num/=b[i];
            }
        }
        i++;
    }
    if(num>1&&num!=ind)
    {
        v[ind].push_back(num);
    }
}


int main()
{
    int i,t,j,ans=0,s,d;
    seive();
    for(i=4; i<=1000; i++)
    {
        divisor_count(i,i);
//        cout<<"ind "<<i<<endl;
//        for(j=0;j<v[i].size();j++)
//            cout<<v[i][j]<<" ";
//        cout<<endl;
    }

    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        ans=0;
        memset(vis,0,sizeof(vis));
        memset(dis,0,sizeof(dis));
        scanf("%d %d",&s,&d);
        ans = BFS(s,d);
        if(ans==0&&s!=d)
            ans=-1;
        printf("Case %d: %d\n",i,ans);
    }
    return 0;
}
