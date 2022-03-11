#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
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
const int N = 5e5+3;
// const int M = 1e5+5;

ll n, m, D, P;
struct dem {
    ll sc, tr, sr, na;
    vector<ll> a;
    dem(){}
};
ll s, smx, t, d;
struct dem dems[N];
vector<int> ans;
double psum[N];



bool cmpdems(int &i, int &j) {
    return dems[i].sr - dems[i].sc + psum[i]/100  > dems[j].sr - dems[j].sc + psum[j]/100 ;
    // return d1.sr - d1.sc > d2.sr - d2.sc;
}

void go1() {
    cin >> s >> smx >> t >> d;
    ans.assign(d,-1);
    fo(i,d) {
        ll sc, tr, sr, na;cin >> sc >> tr >> sr >> na;
        vector<ll> a(na);
        psum[i]=0;
        fo(j, na) {
            cin >> a[j];
            // if(2*j<d)psum[i]+=a[j];
            psum[i]+=a[j];
        }
        struct dem dm;
        dm.a = a;
        dm.na = na;
        dm.sc = sc;
        dm.tr = tr;
        dm.sr = sr;
        dems[i] = dm;
    }
    priority_queue<pair<int, int> > st;
    priority_queue<pair<pair<int, int>, int> > na;
    fo(i, d) {
        if(dems[i].sc < 6 and dems[i].sr >= 25 and dems[i].tr <= 100) {
        // if(dems[i].sc <= 10 and dems[i].sr >= 15 + dems[i].sc and dems[i].tr <= 10) {
            st.push({-dems[i].sc, i});
        }
    }
    fo(i, d) {
        if(dems[i].sc <= 50 and psum[i] > 800 and dems[i].tr <= 100) {
        // if(dems[i].sc == 7 and psum[i] > 4800) {
            // cout << dems[i].sc << " " << psum[i] << ln;
            // ans += psum[i];
            na.push({{psum[i], -dems[i].tr}, i});
        }
    }
    cerr << st.size() << " " << na.size() << ln;
    vector<int> res;
    ll scur = s;
    vector<int> diff(100000, 0);
    int day = 0; // = res.size()
    fo(i, 56) {
        scur += diff[day];
        auto u = st.top();
        res.pb(u.second);
        st.pop();
        diff[day + dems[u.second].tr] += u.first;
        scur -= dems[u.second].sc;
        day++;
    }
    cerr << scur << ln;
    fo(i, 86) {
        fo(j ,10) {
            scur += diff[day];
            auto u = na.top();
            res.pb(u.second);
            na.pop();
            diff[day + dems[u.second].tr] += dems[u.second].sr;
            scur -= dems[u.second].sc;
            day++;
        }
        fo(j, 1) {
            scur += diff[day];
            auto u = st.top();
            res.pb(u.second);
            st.pop();
            diff[day + dems[u.second].tr] += u.first;
            scur -= dems[u.second].sc;
            day++;
        }
    }
    cerr << scur << ln;
    cerr << res.size() << ln;
    // cerr << scur << ln;
    // while(scur > 100) {
    //     scur += diff[day];
    //     auto u = na.top();
    //     res.pb(u.second);
    //     na.pop();
    //     diff[day + dems[u.second].tr] += dems[u.second].sr;
    //     scur -= dems[u.second].sc;
    //     day++;
    // }
    // cerr << scur << ln;
    // fo(i, 80) {
    //     scur += diff[day];
    //     auto u = st.top();
    //     res.pb(u.second);
    //     st.pop();
    //     diff[day + 10] += u.first;
    //     scur -= 10;
    //     day++;
    // }
    // cerr << "here" << ln;
    // cerr << day << ln;
    // cerr << scur << ln;
    // while(res.size() < 1000 and scur > 0) {
    //     scur += diff[day];
    //     auto u = na.top();
    //     res.pb(u.second);
    //     na.pop();
    //     diff[day + dems[u.second].tr] += dems[u.second].sr;
    //     scur -= dems[u.second].sc;
    //     day++;
    // }
    fo(i,min(10000ll, (ll)res.size())) cout << res[i] << ln;
    // cerr << scur << ln;
    // cerr << res.size() << ln;

}
int main(){   

    Nos;
    // freopen("00.txt", "r", stdin);
    // freopen("b_dream.txt", "r", stdin);
    freopen("05.txt", "r", stdin);
    // freopen("d_maelstrom.txt", "r", stdin);
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