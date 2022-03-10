#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
typedef long long int ll;
typedef long double ld;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define Nos                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define fo(i,n) for(ll i=0;i<(n);i++)
#define rfo(i,n) for(ll i = (n);i >= 0;i--)
#define rfosn(i, s, n) for(ll i = (n); i >= (s); i--)
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
// #define unordered_set(T) unordered_set<T, custom_hash>
// #define unordered_map(T1, T2) unordered_map<T1, T2, custom_hash>
#define f first
#define se second
#define out2(a1,a2) cout << a1 << " " << a2 << endl  

const ll md = 1e9 + 7; //998244353 ;
//ll hash_prime = 31;
// const ll md = 998244353; // 1e9+7;
long long exp(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res%m;
}

ll C(ll n, ll k) {
    if(n < k) return 0;
    ll res = 1;
    for (int i = n - k + 1; i <= n; ++i)
        {res *= i; res %= md;}
    for (int i = 2; i <= k; ++i)
        {res *= exp(i, md-2, md); res %= md;}
    return res;
}

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};
const int N = 1e3+3;
// const int M = 1e5+5;

ll n, m, D, P;
struct dev {
    int comp;
    ll bonus;
    vector<int> skills; 
};
struct pm {
    int comp;
    ll bonus;
};
map<string, int> compid;
int cid=0, sid=0;
vector<string> revcompid;
map<string, int> skillid;
vector<string> revskillid;
int a[N][N];
struct dev devs[101010];
vector<pair<struct dev, int> > devsort;
vector<pair<struct pm, int> > pmsort;
struct pm pms[20202];

// bool compdevs(struct dev &d1, struct dev &d2) {
//   return d1.bonus > d2.bonus;
// }
bool compdevs(pair<struct dev, int> &d1, pair<struct dev, int> &d2) {
  if(d1.first.bonus != d2.first.bonus) return d1.first.bonus > d2.first.bonus;
  return d1.first.skills.size() > d2.first.skills.size();
}
bool comppms(struct pm &p1, struct pm &p2) {
  return p1.bonus > p2.bonus;
}

void go1() {
    revcompid.pb("");
    revskillid.pb("");
    cin >> m >> n;
    fo(i,n) {
        string s; cin >> s;
        fo(j,m) {
            if(s[j] == '#') a[i][j] = 0;
            else if(s[j] == '_') a[i][j] = 1;
            else a[i][j] = -1;
        }
    }
    cin >> D;
    fo(i,D) {
        string s;cin >> s;
        if(!compid[s]) {
            compid[s] = ++cid;
            revcompid.pb(s);
        }
        struct dev de;
        de.comp = compid[s];
        ll bon;cin >> bon;
        ll noofskills;cin >> noofskills;
        vector<int> sks(noofskills);
        fo(j, noofskills) {
            string sk;cin >> sk;
            if(!skillid[sk]) {
                skillid[sk] = ++sid;
                revskillid.pb(sk);
            }
            sks.pb(skillid[sk]);
        }
        de.skills = sks;
        de.bonus = bon;
        devs[i] = de;
    }
    cin >> P;
    fo(i,P) {
        string s;cin >> s;
        if(!compid[s]) {
            compid[s] = ++cid;
            revcompid.pb(s);
        }
        struct pm pmm;
        pmm.comp = compid[s];
        ll bon;cin >> bon;
        pmm.bonus = bon;
        pms[i] = pmm;
    }
    cerr << "took input\n";
    vector<pair<int, int> > devspots, pmspots;
    fo(i,n) {
        fo(j,m) {
            if(a[i][j] == 1) {
                devspots.pb({i,j});
            } else if(a[i][j] == -1) {
                pmspots.pb({i,j});
            }
        }
    }
    int ds = devspots.size();
    int ps = pmspots.size();
    cerr << D << " " << P << ln;
    // random_shuffle(all(devspots));
    // random_shuffle(all(pmspots));

    fo(i, D) devsort.pb( {devs[i], i});
    fo(i, P) pmsort.pb ({pms[i], i});

    // sort(all(pmsort), comppms);
    sort(all(devsort), compdevs);
    fo(i, D) {
        cerr << devsort[i].first.bonus << " ";
    }
    

    vector<pair<int, int> > dev_out(D, {-1, -1}), pm_out(P, {-1, -1});
    fo(i, ds) {
        if(i >= D) break;
        dev_out[devsort[i].second] = devspots[i];
    }
    fo(i, ps) {
        if(i >= P) break;
        pm_out[pmsort[i].second] = pmspots[i];
    }

    fo(i, D) {
        if(dev_out[i].first < 0) cout << "X\n";
        else {
            cout << dev_out[i].second << " " << dev_out[i].first << ln;
        }
    }
    fo(i, P) {
        if(pm_out[i].first < 0) cout << "X\n";
        else {
            cout << pm_out[i].second << " " << pm_out[i].first << ln;
        }
    }

    // fo(i, min(D, (ll)devspots.size())) {
    //     auto u = devspots[i];
    //     cout << u.second << " " << u.first << ln;
    // }
    // fosn(i, min(D, (ll)devspots.size()), D) {
    //     cout << "X\n";
    // }
    // fo(i, min(P, (ll)pmspots.size())) {
    //     auto u = pmspots[i];
    //     cout << u.second << " " << u.first << ln;
    // }
    // fosn(i, min(P, (ll)pmspots.size()), P) {
    //     cout << "X\n";
    // }
}
int main(){   

    Nos;
    // freopen("a_solar.txt", "r", stdin);
    // freopen("b_dream.txt", "r", stdin);
    // freopen("c_soup.txt", "r", stdin);
    freopen("d_maelstrom.txt", "r", stdin);
    // freopen("e_igloos.txt", "r", stdin);
    // freopen("f_glitch.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
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