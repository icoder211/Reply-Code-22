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
#define fo(i,n) for(ll i=0;i<n;i++)
#define rfo(i,n) for(ll i = n;i >= 0;i--)
#define rfosn(i, s, n) for(ll i = n; i >= s; i--)
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

const ll md = 998244353 ;
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
const int N = 1e5+5;

ll n;
ll c, p;
struct con{
    string name;
    int skl;
    map<string, int> lev;
};
struct proj {
    string name;
    int di, si, ri, bi;
    map<string, int> lev;
};
struct con cons[N];
struct proj projs[N];
void go1() {
    cin >> c >> p;
    fo(i,c) {
        string name;
        cin >> name;
        int n;cin >> n;
        struct con c;
        c.name = name;
        c.skl = n;
        c.lev = {};
        fo(j,n) {
            string skill;
            int skilllevel;
            cin >> skill >> skilllevel;
            c.lev[skill] = skilllevel;
        }
        cons[i] = c;
    }
    fo(i,p) {
        string projname;
        int di,si,bi,ri;
        cin >> projname;
        cin >> di >> si >> bi >> ri;
        struct proj p;
        p.name = projname;
        p.di=di;
        p.ri=ri;
        p.si=si;
        p.bi=bi;
        p.lev = {};
        fo(j, ri) {
            string skill;
            int skillreq;
            cin >> skill >> skillreq;
            p.lev[skill] = skillreq;
        }
        projs[i] = p;
    }
}

int main(){   

    Nos;
    freopen("a_an_example.in.txt", "r", stdin);
    // freopen("b_better_start_small.in.txt", "r", stdin);
    // freopen("c_collaboration.in.txt", "r", stdin);
    // freopen("d_dense_schedule.in.txt", "r", stdin);
    // freopen("e_exceptional_skills.in.txt", "r", stdin);
    // freopen("e_exceptional_skills.in.txt", "r", stdin);
    // freopen("f_find_great_mentors.in.txt", "r", stdin);

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