#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0)
#define bfast cin.tie(0)
#define outs(x) cout << x << " "
#define outn(x) cout << x << "\n"
#define sf scanf
#define pf printf
#define nl puts("")
#define psb push_back
#define mset(c,v) memset(c , v , sizeof c)
#define loop0(n) for(int i=0; i<n; i++)
#define loop1(n) for(int i=1; i<=n; i++)
#define mpair(x , y) make_pair(x , y)
#define all(x) x.begin(), x.end()
#define pi acos(-1.0)
#define psb push_back
#define clr clear()

typedef unsigned long long ull;
typedef long long LL;
typedef vector<int>vii;
typedef vector<LL>vll;
typedef vector<string>vs;
typedef map<int, int>mpii;
typedef map<string, int>mpsi;
typedef map<char, int>mpci;
typedef map<LL, LL>mpll;

const int mod = 1000007;
const int high = 503;
const int inf = 2147483647;

struct data
{
    int node,cost;
    data() { }
    data(int n , int c)
    {
        node = n;
        cost = c;
    }
};

vector<data>adj[high];

int cost[high];

void BFS(int s)
{
    int u=0,v=0,i=0,len=0,vcost=0,maxi = 0;
    cost[s] = 0;
    queue<data>Q;
    Q.push(data(s , 0));

    while(!Q.empty())
    {
        u = Q.front().node;
        Q.pop();
        len = adj[u].size();

        for(i=0; i<len; i++)
        {
            v = adj[u][i].node;
            vcost = adj[u][i].cost;

            maxi = max(cost[u] , vcost);

            if(maxi < cost[v]) /// Sort of Dijkstra
            {
                cost[v] = maxi;
                Q.push(data(v , vcost));
            }
        }
    }
}

void cln()
{
    int i=0;
    for(i=0; i<high; i++)
    {
        adj[i].clr;
        cost[i] = inf;
    }
}

int main()
{
    int u,v,i,n,m,w,test,tc=0,target=0;
    sf("%d", &test);
    while(test--)
    {
        cln();
        sf("%d %d", &n , &m);
        for(i=0; i<m; i++)
        {
            sf("%d %d %d", &u , &v , &w);
            adj[u].psb(data(v , w));
            adj[v].psb(data(u , w));
        }

        sf("%d", &target);
        BFS(target);
        pf("Case %d:\n", ++tc);

        for(i=0; i<n; i++)
        {
            if(cost[i] == inf)
                pf("Impossible\n");
            else
                pf("%d\n" , cost[i]);
        }
    }
    return 0;
}
