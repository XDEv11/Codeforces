//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;
const ll PM{998244353};
ll MA(ll a, ll b) { return (a + b) % PM; }
ll MS(ll a, ll b) { return (a - b + PM) % PM; }
ll MM(ll a, ll b) { return (a * b) % PM; }
ll MP(ll a, ll b) {
    ll res{1};
    do {
        if (b & 1) res = MM(res, a);
    } while (a = MM(a, a), b >>= 1);
    return res;
}
ll MI(ll a) { return MP(a, PM - 2); }
ll MD(ll a, ll b) { return MM(a, MI(b)); }

// segment tree
template<typename value_t, class merge_t>
class SGT {
    int n;
    vector<value_t> t; // root starts at 1
    merge_t merge; // associative function for SGT
public:
    explicit SGT(int _n, const merge_t& _merge = merge_t{})
        : n{_n}, t(2 * n), merge{_merge} {}
    void modify(int p, const value_t& x) {
        for (t[p += n] = x; p > 1; p >>= 1) t[p >> 1] = merge(t[p], t[p ^ 1]);
    }
    value_t query(int l, int r, value_t init) { // [l:r)
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) init = merge(init, t[l++]);
            if (r & 1) init = merge(init, t[--r]);
        }
        return init;
    }
};

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;

	ll ans{};
	{
		SGT<int, plus<int>> sgt{m};
		for (int i{0}; i < m; ++i) {
			ans = MA(ans, sgt.query(b[i], m, 0));
			sgt.modify(b[i], 1);
		}
		ans = MM(ans, n);
	}

	{
		SGT<int, plus<int>> sgt{2 * n};
		for (int i{0}; i < n; ++i) {
			int j, x;
			for (j = 0, x = a[i]; j < m && x <= 2 * n - 1; ++j, x *= 2) {
				ans = MA(ans, MM(m - j, sgt.query(x + 1, 2 * n, 0)));
			}
			for (j = 1, x = a[i] / 2; j < m && x >= 1; ++j, x /= 2) {
				ans = MA(ans, MM(m - j, sgt.query(x + 1, 2 * n, 0)));
			}
			ans = MA(ans, MM(MM(m - j, MD(m - j + 1, 2)), sgt.query(1, 2 * n, 0)));
			sgt.modify(a[i], 1);
		}
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
