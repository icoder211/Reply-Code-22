#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
typedef long long int ll;
typedef long double ld;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define Nos                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define fo(i,n) for(ll i=0;i<n;i++)
#define rfo(i,n) for(ll i = n;i >= 0;i--)
#define rfosn(i, s, n) for(ll i = n, i >= s; i--)
#define PI 3.141592654
#define all(v) (v).begin(), (v).end()
#define allr(v) (v).rbegin(), (v).rend()
#define pb push_back
#define mp make_pair
#define fosn(i, s, n) for(int i = s;i < n;i ++)
 
#define vb vector<bool>
#define vvb vector<vb>
#define vi vector<int>
#define vvi vector<vi>
#define vl vector<ll>
#define vvl vector<vl>
#define ln '\n'
#define pii pair<int,int>
#define vpi vector<pii>
#define unordered_set(T) unordered_set<T, custom_hash>
#define unordered_map(T1, T2) unordered_map<T1, T2, custom_hash>
#define f first
#define se second
#define out2(a1,a2) cout << a1 << " " << a2 << endl    // large prime for modulo

const ll md =1e9+7;
//ll hash_prime = 31;
// const ll md = 998244353; // 1e9+7;
long long exp(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        // assert(a>=0);
        b >>= 1;
    }
    return res;
}

ll C(ll n, ll k) {
    ll res = 1;
    for (int i = n - k + 1; i <= n; ++i)
        {res *= i; res %= md;}
    for (int i = 2; i <= k; ++i)
        {res *= exp(i, md-2, md); res %= md;}
    return res;
}

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};
const int N = 100000;


ll K = 10; // no. of ingredients in the final dish
ll n;
ll id=0;
map<string, ll> lab;
vector<string> revlab;
vector<set<int> > dis, like;
vector<ll> final_ingredients;
vector<ll> lf, df;

void go1() {
    cin >> n;
    lf.pb(0);
    df.pb(0);
    revlab.pb("");
    id = 0;
    fo(i, n) {
        int l, d;
        cin >> l;
        like.pb({});
        dis.pb({});
        fo(j, l) {
            string s;cin>> s;
            if(!lab[s]) {
                lab[s] = ++id;
                revlab.pb(s);
            }
            like.back().insert(lab[s]);
        }
        cin >> d;
        fo(j, d) {
            string s;cin>> s;
            if(!lab[s]) {
                lab[s] = ++id;
                revlab.pb(s);
            }
            dis.back().insert(lab[s]);
        }
    }
    K = min(K, id);
    lf.assign(1 + id, 0);
    df.assign(1 + id, 0);
    vector<ll> acc;
    set<ll> done;
    fo(i, n) acc.pb(1);
    while(true) {
        // cout<<final_ingredients.size()<<endl;
        int mx = 0;
        int mxi = 0;
        lf.assign(1 + id, 0);
        df.assign(1 + id, 0);
        fo(i, n) {
            if(!acc[i]) continue;
            for(auto u: like[i]) {
                if(done.count(u)) continue;
                lf[u]++;
                if(mx < lf[u]) {
                    mx = lf[u];
                    mxi = u;
                }
            }
        }
        if(mxi == 0) break;
        final_ingredients.pb(mxi);
        done.insert(mxi);
        fo(i, n) {
            if(like[i].count(mxi) == 0) acc[i] = 0;
        }
    }
    ll k = 10000;
    k = min(k, (ll)final_ingredients.size());
    cout<<k<<" ";
    fo(i, k) {
        cout << revlab[final_ingredients[i]] << " ";
    }
    cout<<ln;
}
 
int main(){   

    Nos;
    // freopen("a_an_example.in.txt", "r", stdin);
    // freopen("b_basic.in.txt", "r", stdin);
    // freopen("a_an_example.in.txt", "r", stdin);
    freopen("d_difficult.in.txt", "r", stdin);
    // freopen("a_an_example.in.txt", "r", stdin);
    freopen("a.txt", "w", stdout);
    // cout << fixed << setprecision(25);
    int t=1;
    // cin>>t;
    int t_=t;

    while(t--){
        // cout << "Case #"<<t_-t<<": ";
        go1();
    }
    return 0;
}