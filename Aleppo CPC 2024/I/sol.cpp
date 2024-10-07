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



int main() {
    IOS
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        unordered_map<int, vi> ls;
        unordered_map<int, vi> rs;
        for (int i = 0; i < n; ++i) {
            ll x, y, r;
            cin >> x >> y >> r;
            for (ll yi = y-r; yi <= y+r; ++yi) {
                for (ll xi = x-r; xi <= x+r; ++xi) {
                    if (((x-xi)*(x-xi)+(y-yi)*(y-yi)) <= r*r) {
                        ls[yi].pb(xi);
                        rs[yi].pb(2*x-xi);
                        break;
                    }
                }
            }
        }
        for (auto &[y, v] : ls) {
            sort(ls[y].begin(), ls[y].end());
            sort(rs[y].begin(), rs[y].end());
        }
        while (q--) {
            int x, y;
            cin >> x >> y;
            if (ls.find(y) != ls.end()) {
                int nbl = upper_bound(ls[y].begin(), ls[y].end(), x) - ls[y].begin();
                int nbr = lower_bound(rs[y].begin(), rs[y].end(), x) - rs[y].begin();
                cout << nbl - nbr << endl;
            } else cout << 0 << endl;
        }
    }

    return 0;
}