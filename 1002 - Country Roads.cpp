///......................................///
///......... Name : Misu Dey  ...........///
///......... University: CUET ...........///
///......... Id : 1404108     ...........///
///......................................///

#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define re_fr(i,a,b) for(int i=a;i>=b;i--)
#define frl(i,a,b) for(ll i=a;i<=b;i++)
#define re_frl(i,a,b) for(ll i=a;i>=b;i--)
#define mp make_pair
#define F first
#define S second
#define MX 5000010
#define eps 1e-9
#define PI acos(-1)
#define inf 1e18
#define pll pair<ll,ll>
#define mod 1000000007
#define mod2 998244353
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define PI acos(-1)
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
/// lower bound for sorted array
/// ll lb = lower_bound( b, b+n, 100 ) - b

ll rep[1010],cost[1010],vis[1010];
ll sum=0;
struct edge
{
    int u,v,cost;
};
bool cmp(edge a, edge b)
{
    return a.cost<b.cost;
}
vector<edge>E;
vector<pll>V[1010];
ll t,n,e,a,b,c,source;
ll find_rep(ll i)
{
    if(rep[i]==i)
        return i;
    return rep[i]=find_rep(rep[i]);
}

void mst()
{
    ll cnt=0;
    sort(E.begin(),E.end(),cmp);
    for(ll j=0;j<E.size();j++)
    {
        ll pa=find_rep(E[j].u);
        ll pb=find_rep(E[j].v);
        if(pa != pb)
        {
            cnt++;
            rep[pa]=pb;
            //cout<<E[j].u<<' '<<E[j].v<<' '<<E[j].cost<<endl;
            V[E[j].u].pb( {E[j].v, E[j].cost} );
            V[E[j].v].pb( {E[j].u, E[j].cost} );
        }
        if(cnt==n-1) break;
    }
}
void dfs(ll s)
{
    vis[s]=1;
    //cout<<s<<endl;
    for(ll j=0;j<V[s].size();j++)
    {
        pll vp=V[s][j];
        //cout<<vp.F<<' '<<vp.S<<endl;
        if(!vis[vp.F])
        {
            cost[vp.F]=max(cost[s],vp.S);
            dfs(vp.F);
        }
    }
}
int main ()
{
    fast();
    scanf("%lld",&t);
    for(ll cs=1;cs<=t;cs++)
    {
    E.clear();
    scanf("%lld %lld",&n,&e);
    for(ll i=0;i<n;i++)
    {
        rep[i]=i;
        vis[i]=0;
        V[i].clear();
        cost[i]=1e18;
    }
    for(ll i=1;i<=e;i++)
    {
        scanf("%lld %lld %lld",&a,&b,&c);
        edge g;
        g.u=a;
        g.v=b;
        g.cost=c;
        E.pb(g);
    }
    mst();
    scanf("%lld",&source);
    printf("Case %lld:\n",cs);
    cost[source]=0;
    dfs(source);
    for(ll i=0;i<n;i++)
    {
        if(cost[i]==1e18) printf("Impossible\n");
        else printf("%lld\n",cost[i]);
    }

    }

    return 0;

}

