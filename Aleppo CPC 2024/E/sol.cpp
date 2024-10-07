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

const int MAXN = 1e5+5;
ll a[MAXN];

int msb(ll x) {
    for (ll j = 60; j >= 0; j--) {
        if ((1ll<<j) & x) return j;
    }
}

int main() {
    IOS
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi msbCount(60, 0);
        int ans = 1;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] != 0) msbCount[msb(a[i])]++;
        }
        for (int count : msbCount) ans = max(count, ans);
        cout << ans << endl;
    }

    return 0;
}