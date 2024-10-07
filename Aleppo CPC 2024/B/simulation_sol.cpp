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
#define debugv(v) for(int abc=0;abc<(int)v.size();abc++){cout<<v[abc]<<' ';}cout<<endl;
#define debugvv(v) for(int abcd=0;abcd<(int)v.size();abcd++){debugv(v[abcd])}

int occ[10][34][10];
int ans[10][10][10][34][10];
void precompute() {
    for (int x = 1; x < 10; ++x) {
        for (int i = 1; i < 10; ++i) {
            occ[x][0][i] = 0;
        }
        occ[x][0][x] = 1;
        for (int n = 1; n < 34; ++n) {
            for (int i = 1; i < 10; ++i) {
                occ[x][n][i] = 0;
            }
            for (int i = 1; i < 10; ++i) {
                int temp = i * 3;
                occ[x][n][temp%10] += occ[x][n-1][i];
                if (temp/10) occ[x][n][temp/10] += occ[x][n-1][i];
            }
        }
    }

    for (int i = 1; i < 10; ++i) {
        for (int j = i; j < 10; ++j) {
            for (int k = j; k < 10; ++k) {
                for (int n = 1; n < 34; ++n) {
                    for (int x = 1; x < 10; ++x) {
                        ans[i][j][k][n][x] = occ[i][n][x] + occ[j][n][x] + occ[k][n][x];
                    }
                }
            }
        }
    }
}

int main() {
    IOS
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    precompute();

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vi a(10, 0);
        for (int i = 0; i < m; ++i) {
            int x;
            cin >> x;
            a[x]++;
        }
        bool good;
        int dif, card = 1;
        for (int i = 1; i < 10; ++i) {
            for (int j = i; j < 10; ++j) {
                for (int k = j; k < 10; ++k) {
                    good = true;
                    dif = 0;
                    for (int x = 1; x < 10; ++x) {
                        if (ans[i][j][k][n][x] - a[x] == 1) {
                            if (dif) {
                                good = false;
                                break;
                            }
                            dif++;
                            card = x;
                        } else if (ans[i][j][k][n][x] == a[x]) {
                            continue;
                        } else {
                            good = false;
                            break;
                        }
                    }
                    good = (good && (dif == 1));
                    if (good) break;
                }
                if (good) break;
            }
            if (good) break;
        }
        cout << card << endl;
    }

    return 0;
}