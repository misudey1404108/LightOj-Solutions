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
bool ck=false;
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
            sum+=E[j].cost;
            //cout<<E[j].u<<' '<<E[j].v<<' '<<E[j].cost<<endl;
            //V[E[j].u].pb( {E[j].v, E[j].cost} );
            //V[E[j].v].pb( {E[j].u, E[j].cost} );
        }
        if(cnt==n-1) {ck=true; break;}
    }
}
int main ()
{
    //fast();
    scanf("%lld",&t);
    map<string,ll>Map;
    for(ll cs=1;cs<=t;cs++)
    {
    ck=false;
    E.clear(); Map.clear();
    sum=0;
    scanf("%lld",&e);
    for(ll i=1;i<=100;i++)
    {
        rep[i]=i;
       // V[i].clear();
    }
    for(ll i=1;i<=e;i++)
    {
        string s1,s2;
        cin>>s1>>s2;
        ll tmp;
        if(!Map.count(s1))
        {
            tmp=Map.size();
            Map[s1]=tmp+1;
        }
        a=Map[s1];
        if(!Map.count(s2))
        {
            tmp=Map.size();
            Map[s2]=tmp+1;
        }
        b=Map[s2];
        cin>>c;
        //cout<<a<<' '<<b<<' '<<c<<endl;
        edge g;
        g.u=a;
        g.v=b;
        g.cost=c;
        E.pb(g);
    }
    n=Map.size();
    mst();
    if(ck) printf("Case %lld: %lld\n",cs,sum);
    else  printf("Case %lld: Impossible\n",cs);
    }

    return 0;

}

