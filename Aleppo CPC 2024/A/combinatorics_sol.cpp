//بسم الله الرحمان الرحيم
//we are the winners
//we are the champions

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, greater_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<ll>>
#define vb vector<bool>
#define vii vector<pair<int, int>>
#define vvii vector<vector<pair<int, int>>>
#define viii vector<tuple<int, int, int>>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tiii tuple<int, int, int>
#define tll tuple<ll, ll, ll>
#define LSOne(S) ((S) & -(S))
#define fi first
#define se second
#define pb push_back
#define lv (v<<1)
#define rv ((v<<1)+1)
#define endl '\n'
#define debugv(v) for(int i=0;i<(int)v.size();i++){cout<<v[i]<<' ';}cout<<endl;
#define debugvv(v) for(int j=0;j<(int)v.size();j++){debugv(v[j])}

const int MAXN = 1e6 + 5;
ll pref[MAXN];

const long long MOD = 1e9 + 7; // chose any MOD
long long binpow(long long a, long long b) {
    a %= MOD;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    IOS
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> pref[i];
        pref[i] += ((i > 0) ? pref[i-1] : 0);
    }
    ll tot = pref[n-1];
    ll nakas = 0;
    for(int i = 0; i < n; ++i) pref[i] *= 2ll;
    for (int r = 0; r < n; ++r) {
        if (pref[r] < tot) continue;
        int l = upper_bound(pref, pref+n, pref[r]-tot) - pref;
        ll nbl = l, nbr = n-r-1;
        if (r == n-1 && l == 0) continue;
        if (l == 0) {
            nakas = (nakas + ((binpow(2, nbr-1) - 1ll + MOD) % MOD)) % MOD;
        } else if (r == n-1) {
            nakas = (nakas + ((binpow(2, nbl) - nbl - 1ll + MOD) % MOD)) % MOD;
        } else {
            nakas += ((binpow(2, nbr-1) * ((binpow(2, nbl) - 1ll + MOD) % MOD)) % MOD);
            nakas %= MOD;
            nakas = (nakas + ((binpow(2, nbr-1) - 1ll + MOD) % MOD)) % MOD;
        }
    }
    ll ans = (binpow(2, n-1) - n + MOD) % MOD;
    ans = (ans - nakas + MOD) % MOD;
    cout << ans << endl;

    return 0;
}