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

ll rep[1010];
ll cost1=0,cost2=0;
struct edge
{
    int u,v,cost;
};
bool cmp(edge a, edge b)
{
    return a.cost<b.cost;
}
bool cmp2(edge a, edge b)
{
    return a.cost>b.cost;
}
vector<edge>E,E2;
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
            cost1+=E[j].cost;
            //cout<<E[j].u<<' '<<E[j].v<<' '<<E[j].cost<<endl;
            //V[E[j].u].pb( {E[j].v, E[j].cost} );
            //V[E[j].v].pb( {E[j].u, E[j].cost} );
        }
        if(cnt==n) break;
    }
}
void mst2()
{
    ll cnt=0;
    sort(E2.begin(),E2.end(),cmp2);
    for(ll j=0;j<E2.size();j++)
    {
        ll pa=find_rep(E2[j].u);
        ll pb=find_rep(E2[j].v);
        if(pa != pb)
        {
            cnt++;
            rep[pa]=pb;
            cost2+=E2[j].cost;
            //cout<<E[j].u<<' '<<E[j].v<<' '<<E[j].cost<<endl;
            //V[E[j].u].pb( {E2[j].v, E2[j].cost} );
            //V[E[j].v].pb( {E2[j].u, E2[j].cost} );
        }
        if(cnt==n) break;
    }
}
int main ()
{
    fast();
    scanf("%lld",&t);
    for(ll cs=1;cs<=t;cs++)
    {
    E.clear(); E2.clear();
    cost1=0; cost2=0;
    scanf("%lld",&n);
    for(ll i=0;i<=n;i++)
    {
        rep[i]=i;
        //V[i].clear();
    }
    while(1)
    {
        scanf("%lld %lld %lld",&a,&b,&c);
        if(!a && !b && !c) break;
        edge g;
        g.u=a;
        g.v=b;
        g.cost=c;
        E.pb(g); E2.pb(g);
    }
    mst();
    for(ll i=0;i<=n;i++) rep[i]=i;
    mst2();
    printf("Case %lld: ",cs);
    //cout<<cost1<<' '<<cost2<<endl;
    ll cost=cost1+cost2;
    if(cost%2==0) printf("%lld\n",cost/2);
    else printf("%lld/2\n",cost);

    }

    return 0;

}

