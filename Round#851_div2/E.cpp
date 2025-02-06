//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>
#include <limits>

using namespace std;

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
	using ll = long long;

	int n;
	cin >> n;
	vector<ll> v(n);
	for (auto& x : v) cin >> x;

	vector<ll> ps(n + 1);
	for (int i{1}; i <= n; ++i) ps[i] = ps[i - 1] + v[i - 1];

	vector<int> r(n + 1);
	vector<pair<ll, int>> tmp(n + 1);
	for (int i{0}; i <= n; ++i) tmp[i] = {ps[i], i};
	sort(tmp.begin(), tmp.end());
	int c{0};
	for (int i{0}; i <= n; ++i) r[tmp[i].se] = (i == n || tmp[i].fi != tmp[i + 1].fi ? c++ : c);

	struct _M { ll operator()(ll x, ll y) { return max(x, y); } };
	SGT<ll, _M> sgt{c};
	for (int i{0}; i < c; ++i) sgt.modify(i, numeric_limits<ll>::min());
	sgt.modify(r[0], 0);
	ll dp{0};
	for (int i{1}; i <= n; ++i) {
		dp = max(dp, sgt.query(0, r[i] + 1, numeric_limits<ll>::min()) + i);
		sgt.modify(r[i], dp - i);
	}

	cout << sgt.query(r[n], r[n] + 1, numeric_limits<ll>::min()) + n << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
