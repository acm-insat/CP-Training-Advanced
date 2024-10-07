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
pii dishes[MAXN];
int main() {
    IOS
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        for (int i = 0; i < n; ++i) {
            cin >> dishes[i].fi;
        }
        for (int i = 0; i < n; ++i) {
            cin >> dishes[i].se;
        }
        sort(dishes, dishes + n);

        multiset<int> eaten;
        int maxtime = 0, sumtime = 0;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            auto &[pos, time] = dishes[i];
            if (pos >= d) break;
            while (sumtime + pos > d) {
                sumtime -= maxtime;
                eaten.erase(prev(eaten.end()));
                if (!eaten.empty()) maxtime = *prev(eaten.end());
                else maxtime = 0;
            }
            if (time + sumtime + pos <= d) {
                maxtime = max(time, maxtime);
                sumtime += time;
                eaten.insert(time);
                ans = max(ans, (int)eaten.size());
                continue;
            }
            if (time < maxtime) {
                sumtime += time - maxtime;
                eaten.insert(time);
                eaten.erase(prev(eaten.end()));
                maxtime = *prev(eaten.end());
            }
        }
        cout << ans << endl;
    }

    return 0;
}